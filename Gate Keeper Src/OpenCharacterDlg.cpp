// OpenCharacterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "OpenCharacterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenCharacterDlg dialog


COpenCharacterDlg::COpenCharacterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpenCharacterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpenCharacterDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COpenCharacterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenCharacterDlg)
	DDX_Control(pDX, IDC_CHARACTERS, m_lcChars);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COpenCharacterDlg, CDialog)
	//{{AFX_MSG_MAP(COpenCharacterDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_CHARACTERS, OnDblclkCharacters)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenCharacterDlg message handlers

BOOL COpenCharacterDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CRect rect;
	m_lcChars.GetClientRect(&rect);
	m_lcChars.InsertColumn(0,"File",LVCFMT_LEFT,80);
	m_lcChars.InsertColumn(1,"Character Name",LVCFMT_LEFT,120);
	m_lcChars.InsertColumn(2,"Last Modified",LVCFMT_LEFT,rect.Width()-80-120-17);

	m_strPath = _strGamePath;
	m_strPath.TrimRight();
	m_strPath.TrimLeft();
	if (m_strPath.IsEmpty())
	{
		AfxMessageBox("Unable to find Baldur's Gate. Use the Settings menu option to change the path.");
		EndDialog(IDCANCEL);
		return(TRUE);
	}
	if (m_strPath.Right(1) != "\\")
		m_strPath += "\\";
	CString strChars;
	strChars.LoadString(IDS_CHARACTERDIR);
	m_strPath += strChars;

	FindCharacters();

	if (m_lcChars.GetItemCount())
		m_lcChars.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);

	return TRUE;
}

void COpenCharacterDlg::FindCharacters()
{
	HANDLE handle;
	WIN32_FIND_DATA fdFile;
	BOOL bResult;
	int nIndex;
	CString strPath;
	CString strFile;
	CString strName;
	CString strTime;
	CFile file;
	SYSTEMTIME st;

	m_lcChars.DeleteAllItems();

	strPath = m_strPath + "*.chr";
	bResult = TRUE;
	handle = FindFirstFile(strPath,&fdFile);
	while(bResult && handle != INVALID_HANDLE_VALUE)
	{
		strFile = fdFile.cFileName;
		strFile.MakeLower();
		if (!file.Open(m_strPath+strFile,CFile::modeRead|CFile::typeBinary))
		{
			MessageBox(CString("Unable to open file: ")+strFile,"File Error",MB_ICONWARNING);
			EndDialog(IDCANCEL);
			return;
		}
		file.Seek(8,CFile::begin);
		file.Read(strName.GetBufferSetLength(22),21);
		strName.ReleaseBuffer();
		file.Close();

		FileTimeToSystemTime(&fdFile.ftLastWriteTime,&st);
		strTime.Format("%02d/%02d/%d at %02d:%02d",
			st.wMonth,
			st.wDay,
			st.wYear,
			st.wHour,
			st.wMinute);

		nIndex = m_lcChars.InsertItem(0,strFile);
		m_lcChars.SetItemText(nIndex,1,strName);
		m_lcChars.SetItemText(nIndex,2,strTime);

		bResult = FindNextFile(handle,&fdFile);
	}
}

void COpenCharacterDlg::OnDblclkCharacters(NMHDR* pNMHDR, LRESULT* pResult) 
{
	OnOK();	
	*pResult = 0;
}

void COpenCharacterDlg::OnOK() 
{
	int nIndex = m_lcChars.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
		return;

	m_strFile = m_strPath + m_lcChars.GetItemText(nIndex,0);
	m_strCharacter = m_lcChars.GetItemText(nIndex,1);
	
	CDialog::OnOK();
}
