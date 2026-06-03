// GameLocationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "GameLocationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameLocationDlg dialog


CGameLocationDlg::CGameLocationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameLocationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameLocationDlg)
	m_strGamePath = _T("");
	//}}AFX_DATA_INIT
}


void CGameLocationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameLocationDlg)
	DDX_Text(pDX, IDC_GAME_PATH, m_strGamePath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGameLocationDlg, CDialog)
	//{{AFX_MSG_MAP(CGameLocationDlg)
	ON_BN_CLICKED(IDC_BROWSE_LOCATION, OnBrowseLocation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameLocationDlg message handlers


BOOL CGameLocationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
}

void CGameLocationDlg::OnBrowseLocation() 
{
	CFileDialog d(TRUE);

	if (d.DoModal() == IDOK)
	{
		m_strGamePath = d.GetPathName();
		int nIndex = m_strGamePath.ReverseFind('\\');
		if (nIndex != -1)
		{
			m_strGamePath = m_strGamePath.Left(nIndex+1);
			UpdateData(FALSE);
		}
	}
}
