// ProficienciesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "ProficienciesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProficienciesDlg dialog


CProficienciesDlg::CProficienciesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProficienciesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProficienciesDlg)
	m_nProfAxe = 0;
	m_nProfBlunt = 0;
	m_nProfBow = 0;
	m_nProfLgSword = 0;
	m_nProfMissile = 0;
	m_nProfSmSword = 0;
	m_nProfSpear = 0;
	m_nProfSpiked = 0;
	//}}AFX_DATA_INIT
}


void CProficienciesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProficienciesDlg)
	DDX_Control(pDX, IDC_SPIN_PROF_SMSWORD, m_sbtnProfSmSword);
	DDX_Control(pDX, IDC_SPIN_PROF_SPIKED, m_sbtnProfSpiked);
	DDX_Control(pDX, IDC_SPIN_PROF_SPEAR, m_sbtnProfSpear);
	DDX_Control(pDX, IDC_SPIN_PROF_MISSILE, m_sbtnProfMissile);
	DDX_Control(pDX, IDC_SPIN_PROF_LGSWORD, m_sbtnProfLgSword);
	DDX_Control(pDX, IDC_SPIN_PROF_BOW, m_sbtnProfBow);
	DDX_Control(pDX, IDC_SPIN_PROF_BLUNT, m_sbtnProfBlunt);
	DDX_Control(pDX, IDC_SPIN_PROF_AXE, m_sbtnProfAxe);
	DDX_Text(pDX, IDC_PROF_AXE, m_nProfAxe);
	DDV_MinMaxUInt(pDX, m_nProfAxe, 0, 5);
	DDX_Text(pDX, IDC_PROF_BLUNT, m_nProfBlunt);
	DDV_MinMaxUInt(pDX, m_nProfBlunt, 0, 5);
	DDX_Text(pDX, IDC_PROF_BOW, m_nProfBow);
	DDV_MinMaxUInt(pDX, m_nProfBow, 0, 5);
	DDX_Text(pDX, IDC_PROF_LGSWORD, m_nProfLgSword);
	DDV_MinMaxUInt(pDX, m_nProfLgSword, 0, 5);
	DDX_Text(pDX, IDC_PROF_MISSILE, m_nProfMissile);
	DDV_MinMaxUInt(pDX, m_nProfMissile, 0, 5);
	DDX_Text(pDX, IDC_PROF_SMSWORD, m_nProfSmSword);
	DDV_MinMaxUInt(pDX, m_nProfSmSword, 0, 5);
	DDX_Text(pDX, IDC_PROF_SPEAR, m_nProfSpear);
	DDV_MinMaxUInt(pDX, m_nProfSpear, 0, 5);
	DDX_Text(pDX, IDC_PROF_SPIKED, m_nProfSpiked);
	DDV_MinMaxUInt(pDX, m_nProfSpiked, 0, 5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProficienciesDlg, CDialog)
	//{{AFX_MSG_MAP(CProficienciesDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProficienciesDlg message handlers

BOOL CProficienciesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_sbtnProfAxe.SetRange(0,5);
	m_sbtnProfBlunt.SetRange(0,5);
	m_sbtnProfSpiked.SetRange(0,5);
	m_sbtnProfBow.SetRange(0,5);
	m_sbtnProfMissile.SetRange(0,5);
	m_sbtnProfSpear.SetRange(0,5);
	m_sbtnProfSmSword.SetRange(0,5);
	m_sbtnProfLgSword.SetRange(0,5);

	return TRUE;  // return TRUE unless you set the focus to a control
}
