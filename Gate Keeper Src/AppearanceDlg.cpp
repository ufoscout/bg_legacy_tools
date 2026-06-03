// AppearanceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "AppearanceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppearanceDlg dialog

SEX _sexAvatar[] =
{
	{"Male",AVATAR_SEX_MALE},
	{"Female",AVATAR_SEX_FEMALE},
	{NULL,0}
};

CLASS _classAvatar[] =
{
	// I'm leaving the high nibble set to 6.
	{"Cleric",0x60},
	{"Fighter",0x61},
	{"Mage",0x62},
	{"Thief",0x63},
	{"Drizzt",0x64},
	{NULL,0}
};

RACE _raceAvatar[] = 
{
	{"Human",AVATAR_RACE_HUMAN},
	{"Elf",AVATAR_RACE_ELF},
	{"Half-Elf",AVATAR_RACE_HALFELF},
	{"Dwarf",AVATAR_RACE_DWARF},
	{"Halfling",AVATAR_RACE_HALFLING},
	{"Gnome",AVATAR_RACE_GNOME},
	{NULL,0},
};

CAppearanceDlg::CAppearanceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAppearanceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAppearanceDlg)
	//}}AFX_DATA_INIT

	m_chAvatar = AVATAR_RACE_HUMAN | AVATAR_SEX_MALE;
}


void CAppearanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAppearanceDlg)
	DDX_Control(pDX, IDC_AVATAR_CLASS, m_cboClass);
	DDX_Control(pDX, IDC_AVATAR_GENDER, m_cboSex);
	DDX_Control(pDX, IDC_AVATAR_RACE, m_cboRace);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAppearanceDlg, CDialog)
	//{{AFX_MSG_MAP(CAppearanceDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppearanceDlg message handlers

BOOL CAppearanceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	int nIndex;
	int nItem;

	nIndex = 0;
	while(_sexAvatar[nIndex].pszSex)
	{
		nItem = m_cboSex.AddString(_sexAvatar[nIndex].pszSex);
		m_cboSex.SetItemData(nItem,_sexAvatar[nIndex].chSex);
		if (_sexAvatar[nIndex].chSex == (m_chAvatar & 0xF0))
			m_cboSex.SetCurSel(nItem);
		nIndex++;
	}

	nIndex = 0;
	while(_raceAvatar[nIndex].pszRace)
	{
		nItem = m_cboRace.AddString(_raceAvatar[nIndex].pszRace);
		m_cboRace.SetItemData(nItem,_raceAvatar[nIndex].chRace);
		if (_raceAvatar[nIndex].chRace == (m_chAvatar & 0x0F))
			m_cboRace.SetCurSel(nItem);
		nIndex++;
	}

	nIndex = 0;
	while(_classAvatar[nIndex].pszClass)
	{
		nItem = m_cboClass.AddString(_classAvatar[nIndex].pszClass);
		m_cboClass.SetItemData(nItem,_classAvatar[nIndex].chClass);
		if (_classAvatar[nIndex].chClass == m_chAvatarClass)
			m_cboClass.SetCurSel(nItem);
		nIndex++;
	}
	
	return TRUE;
}

void CAppearanceDlg::OnOK() 
{
	int nRaceIndex = m_cboRace.GetCurSel();
	int nSexIndex = m_cboSex.GetCurSel();
	int nClassIndex = m_cboClass.GetCurSel();
	if (nRaceIndex == CB_ERR || nSexIndex == CB_ERR || nClassIndex == CB_ERR)
		return;

	unsigned char chSex = (unsigned char)m_cboSex.GetItemData(nSexIndex);
	unsigned char chRace = (unsigned char)m_cboRace.GetItemData(nRaceIndex);

	m_chAvatar = chSex | chRace;
	m_chAvatarClass = (unsigned char)m_cboClass.GetItemData(nClassIndex);
	
	CDialog::OnOK();
}
