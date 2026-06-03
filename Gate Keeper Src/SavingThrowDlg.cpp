// SavingThrowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "SavingThrowDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSavingThrowDlg dialog


CSavingThrowDlg::CSavingThrowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSavingThrowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSavingThrowDlg)
	m_nSaveBW = 1;
	m_nSavePP = 1;
	m_nSavePPD = 1;
	m_nSaveRSW = 1;
	m_nSaveS = 1;
	//}}AFX_DATA_INIT
}


void CSavingThrowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSavingThrowDlg)
	DDX_Control(pDX, IDC_SPIN_S, m_sbtnSaveS);
	DDX_Control(pDX, IDC_SPIN_RSW, m_sbtnSaveRSW);
	DDX_Control(pDX, IDC_SPIN_PPD, m_sbtnSavePPD);
	DDX_Control(pDX, IDC_SPIN_PP, m_sbtnSavePP);
	DDX_Control(pDX, IDC_SPIN_BW, m_sbtnSaveBW);
	DDX_Text(pDX, IDC_SAVE_BW, m_nSaveBW);
	DDV_MinMaxUInt(pDX, m_nSaveBW, 1, 20);
	DDX_Text(pDX, IDC_SAVE_PP, m_nSavePP);
	DDV_MinMaxUInt(pDX, m_nSavePP, 1, 20);
	DDX_Text(pDX, IDC_SAVE_PPD, m_nSavePPD);
	DDV_MinMaxUInt(pDX, m_nSavePPD, 1, 20);
	DDX_Text(pDX, IDC_SAVE_RSW, m_nSaveRSW);
	DDV_MinMaxUInt(pDX, m_nSaveRSW, 1, 20);
	DDX_Text(pDX, IDC_SAVE_S, m_nSaveS);
	DDV_MinMaxUInt(pDX, m_nSaveS, 1, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSavingThrowDlg, CDialog)
	//{{AFX_MSG_MAP(CSavingThrowDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSavingThrowDlg message handlers

BOOL CSavingThrowDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_sbtnSaveRSW.SetRange(1,20);
	m_sbtnSavePPD.SetRange(1,20);
	m_sbtnSaveS.SetRange(1,20);
	m_sbtnSavePP.SetRange(1,20);
	m_sbtnSaveBW.SetRange(1,20);
	
	return TRUE;  // return TRUE unless you set the focus to a control
}
