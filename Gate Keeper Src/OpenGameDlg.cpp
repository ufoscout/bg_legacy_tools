// OpenGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "OpenGameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGameDlg dialog


COpenGameDlg::COpenGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpenGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpenGameDlg)
	m_nGameType = 0;
	m_strGameName = _T("");
	//}}AFX_DATA_INIT
}


void COpenGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenGameDlg)
	DDX_Control(pDX, IDC_SAVED_GAMES, m_lbGames);
	DDX_Radio(pDX, IDC_GAMETYPE, m_nGameType);
	DDX_LBString(pDX, IDC_SAVED_GAMES, m_strGameName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COpenGameDlg, CDialog)
	//{{AFX_MSG_MAP(COpenGameDlg)
	ON_BN_CLICKED(IDC_GAMETYPE, OnGametype)
	ON_BN_CLICKED(IDC_GAMETYPE2, OnGametype2)
	ON_LBN_DBLCLK(IDC_SAVED_GAMES, OnDblclkSavedGames)
	ON_BN_CLICKED(IDC_VERIFY, OnVerify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGameDlg message handlers


BOOL COpenGameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	FindGames();
	return TRUE; 
}

void COpenGameDlg::FindGames()
{
	HANDLE handle;
	WIN32_FIND_DATA fdFile;
	CString strSubDir;
	CString strPath;
	CString strNumber;
	CString strFile;
	BOOL bResult;
	int nIndex;

	UpdateData(TRUE);
	if (!m_nGameType)
		strSubDir.LoadString(IDS_SINGLESAVEDIR);
	else
		strSubDir.LoadString(IDS_MULTISAVEDIR);

	strPath = _strGamePath;
	strPath.TrimRight();
	strPath.TrimLeft();
	if (strPath.IsEmpty())
	{
		AfxMessageBox("Unable to find Baldur's Gate. Set the path under the Settings menu option.");
		EndDialog(IDCANCEL);
		return;
	}
	if (strPath.Right(1) != "\\")
		strPath += "\\";
	strPath += strSubDir + "*.*";

	m_lbGames.ResetContent();

	bResult = TRUE;
	handle = FindFirstFile(strPath,&fdFile);
	while(bResult && handle != INVALID_HANDLE_VALUE)
	{
		if (fdFile.dwFileAttributes && FILE_ATTRIBUTE_DIRECTORY)
		{
			strFile = fdFile.cFileName;
			if (strFile.Find('-') != -1)
			{
				strNumber = strFile.Left(9);
				strFile = strFile.Right(strFile.GetLength()-10);

				nIndex = m_lbGames.AddString(strFile);
				m_lbGames.SetItemData(nIndex,atoi(strNumber));
			}
		}

		bResult = FindNextFile(handle,&fdFile);
	}

	m_lbGames.SetCurSel(0);
}

void COpenGameDlg::OnGametype() 
{
	FindGames();	
}

void COpenGameDlg::OnGametype2() 
{
	FindGames();	
}

void COpenGameDlg::OnDblclkSavedGames() 
{
	OnOK();	
}

BOOL COpenGameDlg::GetPath()
{
	CString strFile;
	CString strSubDir;
	CString strTemp;
	UINT nNumber;
	int nIndex;

	nIndex = m_lbGames.GetCurSel();
	if (nIndex == -1)
		return(FALSE);

	UpdateData(TRUE);
	if (!m_nGameType)
		strSubDir.LoadString(IDS_SINGLESAVEDIR);
	else
		strSubDir.LoadString(IDS_MULTISAVEDIR);

	m_strFile = _strGamePath;
	m_strFile.TrimRight();
	m_strFile.TrimLeft();
	if (m_strFile.Right(1) != "\\")
		m_strFile += "\\";

	nNumber = m_lbGames.GetItemData(nIndex);
	m_lbGames.GetText(nIndex,strFile);

	strTemp.Format("%s\\%09u-%s\\Baldur.gam",(const char *)strSubDir,nNumber,(const char *)strFile);
	m_strFile += strTemp;
	return(TRUE);
}

void COpenGameDlg::OnOK() 
{
	if (!GetPath())
		return;
	CDialog::OnOK();
}

// A few people have reported corrupted game files. The number of memeorized
// spells is greater than the number of memeorized spell data. This has thrown
// off some offsets. Symptom in the editor: You get "Unknown Spell" when trying
// to reload one of these games. The PutValues routine should now be able to
// detect this as it recreates the data. This function attempts to find and 
// repair corrupted save files.
void COpenGameDlg::OnVerify() 
{
	if (!GetPath())
		return;

	if (MessageBox("This attempts to reconstruct a corrupted "
		"save game file. A 'Baldur.bak' file will be created and 'Baldur.gam' will be recreated. "
		"If the reconstruction causes problems rename 'Baldur.bak' to 'Baldur.gam' to undo the "
		"changes.\n\r\n\r"
		"Reconstruct file now?", "Reconstruct Saved Game File",
		MB_ICONQUESTION|MB_YESNO) == IDNO)
		{
			return;
		}

	CFile file;
	if (!file.Open(m_strFile,CFile::modeRead|CFile::typeBinary))
	{
		AfxMessageBox("Unable to open the save file.");
		return;
	}

	int nLen = file.GetLength();
	char *pBuf = new char[nLen];
	if (!pBuf)
	{
		AfxMessageBox("Unable to allocate memory.");
		return;
	}

	if (file.Read(pBuf,nLen) != (UINT)nLen)
	{
		delete [] pBuf;
		AfxMessageBox("Unable to read the saved game.");
		return;
	}
	file.Close();

	// Make a backup of the file.
	CString strBackup(m_strFile);
	int nIndex = strBackup.ReverseFind('.');
	if (nIndex != -1)
		strBackup = strBackup.Left(nIndex);
	strBackup += ".bak";
	if (!file.Open(strBackup,CFile::modeWrite|CFile::modeCreate|CFile::typeBinary))
	{
		delete [] pBuf;
		AfxMessageBox("Unable to create a backup file. Repair canceled.");
		return;
	}
	file.Write(pBuf,nLen);
	file.Close();

	// Buffer for reconstructing the file.
	char *pNew = new char[nLen];
	if (!pNew)
	{
		AfxMessageBox("Unable to allocate memory.");
		return;
	}

	UINT nOldOff;
	UINT nNewOff;

	FILE_HEADER *pFileHeader = (FILE_HEADER*)pBuf;
	FILE_HEADER *pNewFileHeader = (FILE_HEADER*)pNew;

	// Taking for granted that the file header and info blocks are correct.
	nOldOff = nNewOff = pFileHeader->nPartyOffset + sizeof(NPC_INFO) * pFileHeader->nPartyCount;
	memcpy(pNew,pBuf,nOldOff);

	// This is built up while walking the characters in the party. Once through
	// all the party memebers it should be the same as the offset set in the 
	// file header.
	UINT nNonParty = nOldOff;
	UINT nHeaderOff, nOldHeaderOff;
	int nSlotAdjust;
	char szSpellType[3];
	int nSpellCount;
	int j,k;
	int nSpellNum;
	int nItemCount;
	BOOL bItemsOk;
	SPELL *pSpell;
	ITEM *pItem;
	NPC_MEMORIZEDINFO *pMemInfo;
	NPC_ITEMSLOTS *pSlots;
	NPC_INFO *pInfo;
	NPC_HEADER *pHeader, *pNewHeader;
	pInfo = (NPC_INFO*)(pNew + pFileHeader->nPartyOffset);
	for (UINT i=0;i<pFileHeader->nPartyCount;i++)
	{
		pHeader = (NPC_HEADER*)(pBuf + pInfo->nDataStart);

		nOldOff = pInfo->nDataStart;
		// Corrupt data tends to make the following always come true. The Info records
		// seem to be always in good shape so we'll just trust them for the offset to
		// the next record.
		/*
		if ((void*)pHeader != (void*)(pBuf+nOldOff))
		{
			MessageBox("Mismatch start of player records, unable to repair.","Reconstruction Error",MB_ICONWARNING);
			delete [] pNew;
			delete [] pBuf;
			return;
		}*/

		nOldHeaderOff = nOldOff;
		nHeaderOff = nNewOff;

		memcpy(pNew+nNewOff,pBuf+nOldOff,sizeof(NPC_HEADER));
		pNewHeader = (NPC_HEADER*)(pNew+nNewOff);
		nNewOff += sizeof(NPC_HEADER);
		nOldOff += sizeof(NPC_HEADER);

		if (pHeader->nKnownSpells && pNewHeader->nKnownOffset != (int)(nNewOff - nHeaderOff))
		{
			MessageBox("Mismatched known spell offset -- repaired.","Bad Data",MB_ICONINFORMATION);
			pNewHeader->nKnownOffset = nNewOff - nHeaderOff;
		}

		// Walk known spells and count them while copying.
		nSpellCount = 0;
		pSpell = (SPELL*)(pBuf+nOldOff);
		while(!strncmp(pSpell->szSpell,"SP",2))
		{
			nSpellCount++;

			memcpy(pNew+nNewOff,pSpell,sizeof(SPELL));
			nNewOff += sizeof(SPELL);
			nOldOff += sizeof(SPELL);

			pSpell++;
		}

		if (pNewHeader->nKnownSpells != nSpellCount)
		{
			MessageBox("Mismatch in count of known spells -- repaired.","Bad Data",MB_ICONINFORMATION);
			pNewHeader->nKnownSpells = nSpellCount;
		}

		if ((UINT)pNewHeader->nMemorizedInfoOffset != nNewOff - nHeaderOff)
		{
			MessageBox("Incorrect memorized info block -- repaired.","Bad Data",MB_ICONINFORMATION);
			pNewHeader->nMemorizedInfoOffset = nNewOff - nHeaderOff;
		}

		memcpy(pNew+nNewOff,pBuf+nOldOff,sizeof(NPC_MEMORIZEDINFO)*pNewHeader->nMemorizedInfo);
		pMemInfo = (NPC_MEMORIZEDINFO*)(pNew+nNewOff);
		nNewOff += sizeof(NPC_MEMORIZEDINFO) * pNewHeader->nMemorizedInfo;
		nOldOff += sizeof(NPC_MEMORIZEDINFO) * pHeader->nMemorizedInfo;

		// Zero out the count of all memorized spells. Will refigure the counts below.
		for (j=0;j<pNewHeader->nMemorizedInfo;j++)
			(pMemInfo+j)->nNumMemorized = 0;

		if (pNewHeader->nMemorizedSpells && pNewHeader->nMemorizedOffset != (int)(nNewOff - nHeaderOff))
		{
			MessageBox("Mismatched memorized spell offset -- repaired.","Bad Data",MB_ICONINFORMATION);
			pNewHeader->nMemorizedOffset = nNewOff - nHeaderOff;
		}

		nSpellCount = 0;
		pSpell = (SPELL*)(pBuf+nOldOff);
		while(!strncmp(pSpell->szSpell,"SP",2))
		{
			nSpellCount++;

			memcpy(pNew+nNewOff,pSpell,sizeof(SPELL));
			nNewOff += sizeof(SPELL);
			nOldOff += sizeof(SPELL);

			// Keep the memorized info updated.
			if (!isdigit(pSpell->szSpell[4]))
			{
				MessageBox("Invalid spell. Can't repair.","Reconstruction Error",MB_ICONWARNING);
				delete [] pNew;
				delete [] pBuf;
				return;
			}

			nSpellNum = pSpell->szSpell[4]-'0'-1;
			memcpy(szSpellType,pSpell->szSpell+2,2);
			szSpellType[2] = '\x0';
			if (!strcmp(szSpellType,"WI"))
			{
				if (nSpellNum < 0 || nSpellNum > 8)
				{
					MessageBox("Invalid wizard spell level. Can't repair.","Reconstruction Error",MB_ICONWARNING);
					delete [] pNew;
					delete [] pBuf;
					return;
				}
				nSpellNum += 7;	// Comes after all the priest spells.
				(pMemInfo+nSpellNum)->nNumMemorized++;
			}
			else
				if (!strcmp(szSpellType,"PR"))
				{
					if (nSpellNum < 0 || nSpellNum > 6)
					{
						MessageBox("Invalid priest spell level. Can't repair.","Reconstruction Error",MB_ICONWARNING);
						delete [] pNew;
						delete [] pBuf;
						return;
					}
					(pMemInfo+nSpellNum)->nNumMemorized++;
				}
				else
					if (!strcmp(szSpellType,"IN"))
					{
						if (pNewHeader->nMemorizedInfo < 17)
						{
							MessageBox("Innate spell found without the innate memorized info block. Can't repair.","Reconstruction Error",MB_ICONWARNING);
							delete [] pNew;
							delete [] pBuf;
							return;
						}
						(pMemInfo+16)->nNumMemorized++;
					}
					else
					{
						MessageBox("Unknown spell type. Can't repair.","Reconstruction Error",MB_ICONWARNING);
						delete [] pNew;
						delete [] pBuf;
						return;
					}

			pSpell++;
		}

		if (pNewHeader->nMemorizedSpells != nSpellCount)
		{
			MessageBox("Mismatch in count of memorized spells -- repaired.","Bad Data",MB_ICONINFORMATION);
			pNewHeader->nMemorizedSpells = nSpellCount;
		}

		if ((UINT)pNewHeader->nItemSlotOffset != nNewOff - nHeaderOff)
		{
			MessageBox("Incorrect item slot info block -- repaired.","Bad Data",MB_ICONINFORMATION);
			pNewHeader->nItemSlotOffset = nNewOff - nHeaderOff;
		}

		memcpy(pNew+nNewOff,pBuf+nOldOff,sizeof(NPC_ITEMSLOTS));
		pSlots = (NPC_ITEMSLOTS*)(pNew+nNewOff);
		nNewOff += sizeof(NPC_ITEMSLOTS);
		nOldOff += sizeof(NPC_ITEMSLOTS);

		bItemsOk = TRUE;
		for (j=0;j<NUM_ITEM_SLOTS && bItemsOk;j++)
		{
			if (pSlots->nItemSlot[j] == 0xFFFF)
				continue;
			if (pSlots->nItemSlot[j] < 0 || pSlots->nItemSlot[j] >= pNewHeader->nItems)
			{
				bItemsOk = FALSE;
				break;
			}
			for (k=j+1;k<NUM_ITEM_SLOTS-1 && bItemsOk;k++)
				if (pSlots->nItemSlot[j] == pSlots->nItemSlot[k])
				{
					bItemsOk = FALSE;
					break;
				}
		}

		// Even if they were all ok, it's possible that there is an invalid block size.
		// This can happen if the memorized spells were not correct.
		if (bItemsOk && pNewHeader->nItems)
			if (pNewHeader->nItemOffset-pNewHeader->nItemSlotOffset != sizeof(NPC_ITEMSLOTS))
				bItemsOk = FALSE;

		if (!bItemsOk)
		{
			// Item slot block is screwed, need to rebuild. Need to find where the items
			// start. This is an assumption, but it is likely that the first 3 consecutive
			// alpha chars will be the first item.
			while(nOldOff < (UINT)nLen-3 && (!isalnum(*(pBuf+nOldOff)) || !isalnum(*(pBuf+nOldOff+1)) || !isalnum(*(pBuf+nOldOff+2))))
				nOldOff++;

			if (nOldOff >= (UINT)nLen || nOldOff - nOldHeaderOff >= pInfo->nDataLen)
			{
				MessageBox("Error locating corrupted items, cannot repair.","Reconstruction Error",MB_ICONWARNING);
				delete [] pNew;
				delete [] pBuf;
				return;
			}

			// Copy the items one by one into the new buffer.
			pNewHeader->nItemOffset = nNewOff - nHeaderOff;
			nItemCount = 0;
			pItem = (ITEM*)(pBuf+nOldOff);
			while(nOldOff-nOldHeaderOff < pInfo->nDataLen && isalnum(*(pBuf+nOldOff)) && isalnum(*(pBuf+nOldOff+1)) && isalnum(*(pBuf+nOldOff+2)))
			{
				memcpy(pNew+nNewOff,pItem,sizeof(ITEM));
				nNewOff += sizeof(ITEM);
				nOldOff += sizeof(ITEM);

				nItemCount++;
				pItem++;
			}
			pNewHeader->nItems = nItemCount;

			// There are only 36 available slots. Some of these may be weapon slots that
			// are unavailable in the game. If there are more items than 33 (-3 extra slots
			// for warriors) don't deal with it.
			if (pNewHeader->nItems > 33)
			{
				MessageBox("Too many items to repair. Clear up a few spots in inventory and try again.","Reconstruction Error",MB_ICONWARNING);
				delete [] pNew;
				delete [] pBuf;
				return;
			}

			// Items need to be placed in the slots so they don't get lost. Rather than
			// trying to match up proper eq with the proper slots going to just sequentially
			// attach them to slots. This will look silly in the game but the player can
			// then remove the eq and put it where it goes.

			// First set all the slots to empty.
			for (j=0;j<NUM_ITEM_SLOTS;j++)
				pSlots->nItemSlot[j] = (short)0xFFFF;

			// Not really sure WHAT to set this too. This pattern is there a lot so give
			// it a shot.
			pSlots->junk[0] = (char)0xE8;
			pSlots->junk[1] = (char)0x03;
			pSlots->junk[2] = (char)0x00;
			pSlots->junk[3] = (char)0x00;

			// There are only 36 available slots. Some of these may be weapon slots that
			// are unavailable in the game.
			nItemCount = 0;
			for (j=0;j<pNewHeader->nItems;j++)
			{
				nSlotAdjust = 0;
				if (j > 9)		// Adjust for weapon slots.
					nSlotAdjust += 3;
				if (j+nSlotAdjust > 15)	// Adjust for unused spot.
					nSlotAdjust++;

				pSlots->nItemSlot[j+nSlotAdjust] = nItemCount;
				nItemCount++;
			}
			MessageBox("Corrupt Inventory -- repaired.","Bad Data",MB_ICONINFORMATION);
		}
		else
		{
			// Items should be ok, just copy them all.
			memcpy(pNew+nNewOff,pBuf+nOldOff,sizeof(ITEM)*pNewHeader->nItems);
			nNewOff += sizeof(ITEM) * pNewHeader->nItems;
			nOldOff += sizeof(ITEM) * pHeader->nItems;
		}

		/*
		// Pick up all the extra affectations.
		memcpy(pNew+nNewOff,pBuf+nOldOff,sizeof(NPC_AFTERITEM)*pNewHeader->nAfterItems);
		nNewOff += sizeof(NPC_AFTERITEM) * pNewHeader->nAfterItems;
		nOldOff += sizeof(NPC_AFTERITEM) * pNewHeader->nAfterItems; */

		// Some of the files I've seen have a ton of affectations, not sure if there
		// should be that many or not. Just going to remove them.
		pNewHeader->nAfterItems = 0;
		pNewHeader->nAfterItemsOffset = 0;

		pInfo->nDataStart = nHeaderOff;
		pInfo->nDataLen = nNewOff - nHeaderOff;

		nNonParty += pInfo->nDataLen;
		pInfo++;
	}

	// This is just a sanity/safety check. They should always be equal since they
	// were just built above.
	if (nNonParty != nNewOff)
	{
		MessageBox("Unrecoverable mismatch between party and non-party characters.","Reconstruction Error",MB_ICONWARNING);
		delete [] pNew;
		delete [] pBuf;
		return;
	}

	// Doubtful this will ever be found. Would have to somehow get extra crap after
	// the last party member's character data.
	if (nOldOff != pFileHeader->nNonPartyCharOffset)
	{
		MessageBox("Non party characters mismatched -- repaired.","Bad Data",MB_ICONINFORMATION);
		nOldOff = pFileHeader->nNonPartyCharOffset;
	}

	pNewFileHeader->nNonPartyCharOffset = nNonParty;

	// Copy all the non party NPC info blocks and character records. The info blocks
	// needs to be adjusted for starting offsets.
	memcpy(pNew+nNewOff,pBuf+nOldOff,sizeof(NPC_INFO)*pFileHeader->nNonPartyCharCount);
	pInfo = (NPC_INFO*)(pNew+nNewOff);
	nNewOff += sizeof(NPC_INFO)*pFileHeader->nNonPartyCharCount;
	nOldOff += sizeof(NPC_INFO)*pFileHeader->nNonPartyCharCount;

	// Copy each non party character block and set the info offset.
	for (i=0;i<pFileHeader->nNonPartyCharCount;i++)
	{
		pInfo->nDataStart = nNewOff;
		memcpy(pNew+nNewOff,pBuf+nOldOff,pInfo->nDataLen);
		nNewOff += pInfo->nDataLen;
		nOldOff += pInfo->nDataLen;

		pInfo++;
	}

	// End of non-player character data is the quest stuff.
	pNewFileHeader->nQuestOffset = nNewOff;

	// Keep the offsets the same distance apart in case my quest structure isn't 
	// the right size (in other words don't calculate the new offset based on my "known"
	// figures).
	pNewFileHeader->nMysteryOffset = nNewOff + (pFileHeader->nMysteryOffset-pFileHeader->nQuestOffset);

	// None of the data in the file below here should have been changed or should
	// need adjustment so just grap the rest of what's left and tack it on.
	memcpy(pNew+nNewOff,pBuf+nOldOff,nLen-nOldOff);

	// Should now be the new length of the file.
	nNewOff += nLen-nOldOff;

	if (!file.Open(m_strFile,CFile::modeCreate|CFile::modeWrite|CFile::typeBinary))
	{
		delete [] pNew;
		delete [] pBuf;
		MessageBox("Unable to open the saved game file for writing.","Reconstruction Error",MB_ICONWARNING);
		return;
	}

	file.Write(pNew,nNewOff);
	file.Close();

	delete [] pNew;
	delete [] pBuf;

	MessageBox("The saved game file has been reconstructed.\r\n\r\n"
		"Inventory: If you had any messages related to inventory you will have to reposition "
		"your equipment in the game (you'll find objects where they don't belong). All of your "
		"equipment should be there, however.","Reconstruction Complete",MB_ICONINFORMATION);
}
