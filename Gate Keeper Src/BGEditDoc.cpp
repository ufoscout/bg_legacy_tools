// BGEditDoc.cpp : implementation of the CBGEditDoc class
//

#include "stdafx.h"
#include "BGEdit.h"
#include "OpenGameDlg.h"
#include "OpenCharacterDlg.h"
#include "BGEditDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBGEditDoc

IMPLEMENT_DYNCREATE(CBGEditDoc, CDocument)

BEGIN_MESSAGE_MAP(CBGEditDoc, CDocument)
	//{{AFX_MSG_MAP(CBGEditDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN_CHR, OnFileOpenChr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBGEditDoc construction/destruction

CBGEditDoc::CBGEditDoc()
{
	for (int i=0;i<6;i++)
	{
		m_character[i].nBufLen = 0;
		m_character[i].pCharacter = NULL;
	}
	for (i=0;i<MAX_NON_PARTY;i++)
	{
		m_nonPartyCharacter[i].nBufLen = 0;
		m_nonPartyCharacter[i].pCharacter = NULL;
	}
	m_pData = NULL;
	m_pFileHeader = NULL;
	m_nBufSize = 0;
	m_bExported = FALSE;
}

CBGEditDoc::~CBGEditDoc()
{
	for (int i=0;i<6;i++)
		if (m_character[i].pCharacter)
			delete [] m_character[i].pCharacter;
	for (i=0;i<MAX_NON_PARTY;i++)
		if (m_nonPartyCharacter[i].pCharacter)
			delete [] m_nonPartyCharacter[i].pCharacter;
	if (m_pData)
		delete [] m_pData;
}

BOOL CBGEditDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CBGEditDoc serialization

void CBGEditDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBGEditDoc diagnostics

#ifdef _DEBUG
void CBGEditDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBGEditDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBGEditDoc commands

// Takes a pointer to a header and calculates the length of the NPC record
// to the best of my knowledge.
UINT CBGEditDoc::CalcNpcLength(NPC_HEADER *pHeader)
{
	UINT nBytes;

	nBytes = sizeof(NPC_HEADER);
	nBytes += sizeof(SPELL) * pHeader->nKnownSpells;
	nBytes += sizeof(NPC_MEMORIZEDINFO) * pHeader->nMemorizedInfo;
	nBytes += sizeof(SPELL) * pHeader->nMemorizedSpells;
	nBytes += sizeof(NPC_ITEMSLOTS);
	nBytes += sizeof(ITEM) * pHeader->nItems;
	nBytes += sizeof(NPC_AFTERITEM) * pHeader->nAfterItems;

	return(nBytes);
}

CString CBGEditDoc::FixName(const char *pszName)
{
	char szName[21];
	int nIndex;

	szName[0] = toupper(pszName[0]);
	nIndex = 0;
	if (*pszName)
	{
		nIndex = 1;
		while(pszName[nIndex])
		{
			szName[nIndex] = tolower(pszName[nIndex]);
			nIndex++;
		}
	}
	szName[nIndex] = '\x0';
	return(CString(szName));
}

void CBGEditDoc::OnFileOpen() 
{
	int i;
	CFile file;
	COpenGameDlg d;

	if (d.DoModal() != IDOK)
		return;
	DeleteContents();

	if (!file.Open(d.m_strFile,CFile::modeRead))
	{
		AfxMessageBox("Unable to open the file.");
		DeleteContents();
		return;
	}
	m_strFilename = d.m_strFile;
	m_nBufSize = file.GetLength();
	m_pData = new unsigned char[m_nBufSize];
	if (!m_pData)
	{
		AfxMessageBox("Unable to allocate memory.");
		DeleteContents();
		return;
	}
	file.Read(m_pData,m_nBufSize);
	file.Close();

	// Create the editable/adjustable buffers for the view to mess around
	// with.
	NPC_INFO *pInfo;
	m_pFileHeader = (FILE_HEADER*)m_pData;
	for (i=0;i<(int)m_pFileHeader->nPartyCount;i++)
	{
		pInfo = (NPC_INFO*)(m_pData+m_pFileHeader->nPartyOffset+sizeof(NPC_INFO)*i);
		m_character[i].pCharacter = new unsigned char[pInfo->nDataLen];
		if (!m_character[i].pCharacter)
		{
			AfxMessageBox("Unable to create the edit buffers.");
			DeleteContents();
			return;
		}
		m_character[i].nBufLen = pInfo->nDataLen;
		memcpy(m_character[i].pCharacter,m_pData+pInfo->nDataStart,pInfo->nDataLen);

		// Check the length of the recrod against the length the record will be
		// set to if my code tries to recreate it. If they are different, there is
		// probably something in the record that I'm unaware of.
		if (pInfo->nDataLen != CalcNpcLength((NPC_HEADER*)m_character[i].pCharacter))
		{
			CString strText, strName;

			if (!strcmp(pInfo->szName,""))
				strName = ((NPC_HEADER*)(m_character[i].pCharacter))->szName;
			else
				strName = pInfo->szName;

			strText.Format("WARNING! There is a record length disagreement between Baldur's Gate and "
				"the editor over character %s. (BG: %u - Editor: %u)\n\nIt it recommended you DO NOT "
				"save the file as it will most likely be corrupted.\n\nContinue Loading?",
				(const char *)FixName(strName),pInfo->nDataLen,CalcNpcLength((NPC_HEADER*)m_character[i].pCharacter));
			int nResult = AfxGetMainWnd()->MessageBox(strText,"File Format Warning",MB_ICONWARNING|MB_YESNO);
			if (nResult == IDNO)
			{
				DeleteContents();
				return;
			}
		}
	}

	// Store the non party characters.
	for(i=0;i<(int)m_pFileHeader->nNonPartyCharCount;i++)
	{
		pInfo = (NPC_INFO*)(m_pData+m_pFileHeader->nNonPartyCharOffset+sizeof(NPC_INFO)*i);
		m_nonPartyCharacter[i].pCharacter = new unsigned char[pInfo->nDataLen];
		if (!m_nonPartyCharacter[i].pCharacter)
		{
			AfxMessageBox("Unable to create the edit buffers.");
			DeleteContents();
			return;
		}
		m_nonPartyCharacter[i].nBufLen = pInfo->nDataLen;
		memcpy(m_nonPartyCharacter[i].pCharacter,m_pData+pInfo->nDataStart,pInfo->nDataLen);
	}

	AfxGetMainWnd()->SetWindowText(CString("Baldur's Gate Game Editor : ")+d.m_strGameName);

	UpdateAllViews(NULL,HINT_LOAD);
}

void CBGEditDoc::DeleteContents() 
{
	for (int i=0;i<6;i++)
	{
		m_character[i].nBufLen = 0;
		if (m_character[i].pCharacter)
		{
			delete [] m_character[i].pCharacter;
			m_character[i].pCharacter = NULL;
		}
	}
	for (i=0;i<MAX_NON_PARTY;i++)
	{
		m_nonPartyCharacter[i].nBufLen = 0;
		if (m_nonPartyCharacter[i].pCharacter)
		{
			delete [] m_nonPartyCharacter[i].pCharacter;
			m_nonPartyCharacter[i].pCharacter = NULL;
		}
	}
	if (m_pData)
	{
		delete [] m_pData;
		m_pData = NULL;
	}
	m_nBufSize = 0;
	m_pFileHeader = NULL;
	m_pChrHeader = NULL;
	m_bExported = FALSE;
	m_strFilename.Empty();
	
	CDocument::DeleteContents();

	UpdateAllViews(NULL,HINT_CLEAR);
}

void CBGEditDoc::OnFileSave() 
{
	if (!m_pData || m_strFilename.IsEmpty() || !m_nBufSize)
		return;

	UpdateAllViews(NULL,HINT_SAVE);

	UINT nBufLen;
	unsigned char *pBuf;

	if (!m_bExported)
	{
		// Need to reconstruct that data file. There are a bunch of file
		// offsets that need to be adjusted for any possible new lengths
		// of the character records.
		nBufLen = sizeof(FILE_HEADER);
		nBufLen += m_pFileHeader->nPartyCount * sizeof(NPC_INFO);
		for (int i=0;i<(int)m_pFileHeader->nPartyCount;i++)
			nBufLen += m_character[i].nBufLen;
		// Plus all the data AFTER the original character data.
		nBufLen += m_nBufSize - m_pFileHeader->nNonPartyCharOffset;

		pBuf = new unsigned char[nBufLen];
		if (!pBuf)
		{
			AfxMessageBox("Unable to create the reconstruction buffer. Cannot save.");
			return;
		}

		UINT nDestOff = sizeof(FILE_HEADER);
		nDestOff += m_pFileHeader->nPartyCount * sizeof(NPC_INFO);
		memcpy(pBuf,m_pData,nDestOff);

		NPC_INFO *pDestInfo;
		for (i=0;i<(int)m_pFileHeader->nPartyCount;i++)
		{
			pDestInfo = (NPC_INFO*)(pBuf+m_pFileHeader->nPartyOffset+sizeof(NPC_INFO)*i);
			pDestInfo->nDataStart = nDestOff;
			pDestInfo->nDataLen = m_character[i].nBufLen;

			memcpy(pBuf+nDestOff,m_character[i].pCharacter,m_character[i].nBufLen);
			nDestOff += m_character[i].nBufLen;
		}

		// nDif is the number of bytes it has shifted +/-.
		// If nDestOff is not pointing at the same place it was in the original
		// file then all the offsets in the header need to be adjusted up or down.
		FILE_HEADER *pHeader = (FILE_HEADER*)pBuf;
		int nDif = nDestOff - m_pFileHeader->nNonPartyCharOffset;
		if (nDif)
		{
			pHeader->nNonPartyCharOffset += nDif;
			pHeader->nQuestOffset += nDif;
			pHeader->nMysteryOffset += nDif;
		}

		// Copy the Non Party Character NPC_INFO blocks.
		memcpy(pBuf+nDestOff,
			m_pData+m_pFileHeader->nNonPartyCharOffset,
			m_pFileHeader->nNonPartyCharCount * sizeof(NPC_INFO));
		nDestOff += m_pFileHeader->nNonPartyCharCount * sizeof(NPC_INFO);

		// Write out the NPC data for non party character.
		for (i=0;i<(int)m_pFileHeader->nNonPartyCharCount;i++)
		{
			pDestInfo = (NPC_INFO*)(pBuf+pHeader->nNonPartyCharOffset+sizeof(NPC_INFO)*i);
			pDestInfo->nDataStart = nDestOff;
			pDestInfo->nDataLen = m_nonPartyCharacter[i].nBufLen;

			memcpy(pBuf+nDestOff,m_nonPartyCharacter[i].pCharacter,m_nonPartyCharacter[i].nBufLen);
			nDestOff += m_nonPartyCharacter[i].nBufLen;
		}

		// Pick up the data after the characters from the original buffer.
		// I have a game in the file here. The quest offset skips over a 
		// small chunk of data between the Non Party Chars and the start
		// of the quest stuff.
		memcpy(pBuf+nDestOff,m_pData+m_pFileHeader->nQuestOffset,
			m_nBufSize - m_pFileHeader->nQuestOffset);
	}
	else
	{
		nBufLen = sizeof(CHR_HEADER) + m_character[0].nBufLen;
		pBuf = new unsigned char[nBufLen];
		if (!pBuf)
		{
			AfxMessageBox("Unable to create the reconstruction buffer.");
			return;
		}
		m_pChrHeader->nDataLen = m_character[0].nBufLen;
		memcpy(pBuf,m_pData,sizeof(CHR_HEADER));
		memcpy(pBuf+sizeof(CHR_HEADER),m_character[0].pCharacter,m_character[0].nBufLen);
	}

	CFile file;
	if (!file.Open(m_strFilename,CFile::modeWrite|CFile::modeCreate))
	{
		AfxMessageBox("Unable to open the file.");
		delete [] pBuf;
		return;
	}
	file.Write(pBuf,nBufLen);
	file.Close();

	delete [] pBuf;

	AfxGetMainWnd()->MessageBox("File Saved.",NULL,MB_ICONINFORMATION);
}

void CBGEditDoc::OnFileOpenChr() 
{
	if (!_bAllowChrEdit)
		return;

	COpenCharacterDlg d;
	CFile file;
	
	if (d.DoModal() != IDOK)
		return;
	DeleteContents();

	if (!file.Open(d.m_strFile,CFile::modeRead))
	{
		AfxMessageBox("Unable to open the file.");
		DeleteContents();
		return;
	}
	m_strFilename = d.m_strFile;
	m_nBufSize = file.GetLength();
	m_pData = new unsigned char[m_nBufSize];
	if (!m_pData)
	{
		AfxMessageBox("Unable to allocate memory.");
		DeleteContents();
		return;
	}
	file.Read(m_pData,m_nBufSize);
	file.Close();

	m_pChrHeader = (CHR_HEADER*)m_pData;

	m_character[0].nBufLen = m_pChrHeader->nDataLen;
	m_character[0].pCharacter = new unsigned char[m_pChrHeader->nDataLen];
	if (!m_character[0].pCharacter)
	{
		AfxMessageBox("Unable to create edit buffers.");
		DeleteContents();
		return;
	}
	memcpy(m_character[0].pCharacter,m_pData+m_pChrHeader->nDataStart,m_pChrHeader->nDataLen);

	// Check the length of the recrod against the length the record will be
	// set to if my code tries to recreate it. If they are different, there is
	// probably something in the record that I'm unaware of.
	if (m_pChrHeader->nDataLen != CalcNpcLength((NPC_HEADER*)m_character[0].pCharacter))
	{
		CString strText;

		strText.Format("WARNING! There is a record length disagreement between Baldur's Gate and "
			"the editor over character %s. (BG: %u - Editor: %u)\n\nIt it recommended you DO NOT "
			"save the file as it will most likely be corrupted.\n\nContinue Loading?",
			(const char *)FixName(((NPC_HEADER*)(m_character[0].pCharacter))->szName),
			m_pChrHeader->nDataLen,
			CalcNpcLength((NPC_HEADER*)m_character[0].pCharacter));
		int nResult = AfxGetMainWnd()->MessageBox(strText,"File Format Warning",MB_ICONWARNING|MB_YESNO);
		if (nResult == IDNO)
		{
			DeleteContents();
			return;
		}
	}
	AfxGetMainWnd()->SetWindowText(CString("Baldur's Gate Game Editor : ")+d.m_strCharacter);
	m_bExported = TRUE;
	UpdateAllViews(NULL,HINT_LOAD);
}
