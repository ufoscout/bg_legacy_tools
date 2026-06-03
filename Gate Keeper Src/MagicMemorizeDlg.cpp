// MagicMemorizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "MagicMemorizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMagicMemorizeDlg dialog


CMagicMemorizeDlg::CMagicMemorizeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMagicMemorizeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMagicMemorizeDlg)
	m_nMemorized = 0;
	//}}AFX_DATA_INIT
}


void CMagicMemorizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMagicMemorizeDlg)
	DDX_Text(pDX, IDC_MEM_TIMES, m_nMemorized);
	DDV_MinMaxUInt(pDX, m_nMemorized, 0, 15);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMagicMemorizeDlg, CDialog)
	//{{AFX_MSG_MAP(CMagicMemorizeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMagicMemorizeDlg message handlers

BOOL CMagicMemorizeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetWindowText(m_strSpell);
	
	return TRUE;  // return TRUE unless you set the focus to a control
}
