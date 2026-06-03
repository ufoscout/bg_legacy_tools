// MiscAbilitiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "MiscAbilitiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

RACIALENEMY _racialEnemy[] =
{
	{"Carrion Crawler",RACIAL_ENEMY_CRAWLER},
	{"Ettercap",RACIAL_ENEMY_ETTERCAP},
	{"Ghoul",RACIAL_ENEMY_GHOUL},
	{"Gibberling",RACIAL_ENEMY_GIBBERLING},
	{"Gnoll",RACIAL_ENEMY_GNOLL},
	{"Hobgoblin",RACIAL_ENEMY_HOBGOBLIN},
	{"Kobold",RACIAL_ENEMY_KOBOLD},
	{"Ogre",RACIAL_ENEMY_OGRE},
	{"Skeleton",RACIAL_ENEMY_SKELETON},
	{"Spider",RACIAL_ENEMY_SPIDER},
	{NULL,0}
};

NUMBEROFATTACKS _numberOfAttacks[] =
{
	{"1",0x01},
	{"2",0x02},
	{"3",0x03},
	{"4",0x04},
	{"5",0x05},
	{"1/2",0x06},
	{"1+1/2",0x07},
	{"2+1/2",0x08},
	{"3+1/2",0x09},
	{"4+1/2",0x0A},
	{NULL,0}
};

/////////////////////////////////////////////////////////////////////////////
// CMiscAbilitiesDlg dialog


CMiscAbilitiesDlg::CMiscAbilitiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMiscAbilitiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMiscAbilitiesDlg)
	m_nThac0 = 0;
	m_nAc = 0;
	m_nMagicResistance = 0;
	//}}AFX_DATA_INIT

	m_chClass = CLASS_NOTHING;
}


void CMiscAbilitiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMiscAbilitiesDlg)
	DDX_Control(pDX, IDC_SPIN_MAGIC_RESISTANCE, m_sbtnMagicResistance);
	DDX_Control(pDX, IDC_SPIN_AC, m_sbtnAc);
	DDX_Control(pDX, IDC_NUMBER_OF_ATTACKS, m_cboAttacks);
	DDX_Control(pDX, IDC_SPIN_THAC0, m_sbtnThac0);
	DDX_Control(pDX, IDC_RACIAL_ENEMY, m_cboRacialEnemy);
	DDX_Text(pDX, IDC_THAC0, m_nThac0);
	DDV_MinMaxUInt(pDX, m_nThac0, 1, 20);
	DDX_Text(pDX, IDC_AC, m_nAc);
	DDV_MinMaxInt(pDX, m_nAc, 0, 10);
	DDX_Text(pDX, IDC_MAGIC_RESISTANCE, m_nMagicResistance);
	DDV_MinMaxUInt(pDX, m_nMagicResistance, 0, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMiscAbilitiesDlg, CDialog)
	//{{AFX_MSG_MAP(CMiscAbilitiesDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMiscAbilitiesDlg message handlers

BOOL CMiscAbilitiesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int nIndex;
	int i;

	for (i=0;_racialEnemy[i].pszName;i++)
	{
		nIndex = m_cboRacialEnemy.AddString(_racialEnemy[i].pszName);
		m_cboRacialEnemy.SetItemData(nIndex,_racialEnemy[i].chValue);

		if (m_chClass == CLASS_RANGER && m_chRacialEnemy == _racialEnemy[i].chValue)
			m_cboRacialEnemy.SetCurSel(nIndex);
	}

	if (m_chClass != CLASS_RANGER)
		m_cboRacialEnemy.EnableWindow(FALSE);

	m_sbtnThac0.SetRange(1,20);
	m_sbtnAc.SetRange(0,10);
	m_sbtnMagicResistance.SetRange(0,100);

	for (i=0;_numberOfAttacks[i].pszText;i++)
	{
		nIndex = m_cboAttacks.AddString(_numberOfAttacks[i].pszText);
		m_cboAttacks.SetItemData(nIndex,_numberOfAttacks[i].chValue);

		if (m_chNumberOfAttacks == _numberOfAttacks[i].chValue)
			m_cboAttacks.SetCurSel(nIndex);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CMiscAbilitiesDlg::OnOK() 
{
	if (m_chClass == CLASS_RANGER)
	{
		int nIndex = m_cboRacialEnemy.GetCurSel();
		if (nIndex == CB_ERR)
			return;
		m_chRacialEnemy = (unsigned char)m_cboRacialEnemy.GetItemData(nIndex);
	}

	int nIndex = m_cboAttacks.GetCurSel();
	if (nIndex == CB_ERR)
		return;
	m_chNumberOfAttacks = (unsigned char)m_cboAttacks.GetItemData(nIndex);
	
	CDialog::OnOK();
}
