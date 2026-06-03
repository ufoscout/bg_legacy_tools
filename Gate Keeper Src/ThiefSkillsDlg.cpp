// ThiefSkillsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "ThiefSkillsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThiefSkillsDlg dialog


CThiefSkillsDlg::CThiefSkillsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThiefSkillsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThiefSkillsDlg)
	m_nDetectTrapsBase = 0;
	m_nOpenLocksBase = 0;
	m_nPickPocketsBase = 0;
	m_nStealthBase = 0;
	m_nDetectTrapsRace = 0;
	m_nOpenLocksRace = 0;
	m_nPickPocketsRace = 0;
	m_nStealthRace = 0;
	m_nDetectTrapsDex = 0;
	m_nOpenLocksDex = 0;
	m_nPickPocketsDex = 0;
	m_nStealthDex = 0;
	m_nDetectTraps = 0;
	m_nOpenLocks = 0;
	m_nPickPockets = 0;
	m_nStealth = 0;
	m_nDetectTrapsActual = 0;
	m_nOpenLocksActual = 0;
	m_nPickPocketsActual = 0;
	m_nStealthActual = 0;
	//}}AFX_DATA_INIT
	m_nRace = RACE_HUMAN;
	m_nDex = 18;
}


void CThiefSkillsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThiefSkillsDlg)
	DDX_Control(pDX, IDC_SPIN_DETECT_TRAPS, m_sbtnDetectTraps);
	DDX_Control(pDX, IDC_SPIN_STEALTH, m_sbtnStealth);
	DDX_Control(pDX, IDC_SPIN_PICK_POCKETS, m_sbtnPickPockets);
	DDX_Control(pDX, IDC_SPIN_OPEN_LOCKS, m_sbtnOpenLocks);
	DDX_Text(pDX, IDC_DETECT_TRAPS_BASE, m_nDetectTrapsBase);
	DDX_Text(pDX, IDC_OPEN_LOCKS_BASE, m_nOpenLocksBase);
	DDX_Text(pDX, IDC_PICK_POCKETS_BASE, m_nPickPocketsBase);
	DDX_Text(pDX, IDC_STEALTH_BASE, m_nStealthBase);
	DDX_Text(pDX, IDC_DETECT_TRAPS_RACE, m_nDetectTrapsRace);
	DDX_Text(pDX, IDC_OPEN_LOCKS_RACE, m_nOpenLocksRace);
	DDX_Text(pDX, IDC_PICK_POCKETS_RACE, m_nPickPocketsRace);
	DDX_Text(pDX, IDC_STEALTH_RACE, m_nStealthRace);
	DDX_Text(pDX, IDC_DETECT_TRAPS_DEX, m_nDetectTrapsDex);
	DDX_Text(pDX, IDC_OPEN_LOCKS_DEX, m_nOpenLocksDex);
	DDX_Text(pDX, IDC_PICK_POCKETS_DEX, m_nPickPocketsDex);
	DDX_Text(pDX, IDC_STEALTH_DEX, m_nStealthDex);
	DDX_Text(pDX, IDC_DETECT_TRAPS, m_nDetectTraps);
	DDV_MinMaxUInt(pDX, m_nDetectTraps, 0, 100);
	DDX_Text(pDX, IDC_OPEN_LOCKS, m_nOpenLocks);
	DDV_MinMaxUInt(pDX, m_nOpenLocks, 0, 100);
	DDX_Text(pDX, IDC_PICK_POCKETS, m_nPickPockets);
	DDV_MinMaxUInt(pDX, m_nPickPockets, 0, 100);
	DDX_Text(pDX, IDC_STEALTH, m_nStealth);
	DDV_MinMaxUInt(pDX, m_nStealth, 0, 100);
	DDX_Text(pDX, IDC_DETECT_TRAPS_ACTUAL, m_nDetectTrapsActual);
	DDX_Text(pDX, IDC_OPEN_LOCKS_ACTUAL, m_nOpenLocksActual);
	DDX_Text(pDX, IDC_PICK_POCKETS_ACTUAL, m_nPickPocketsActual);
	DDX_Text(pDX, IDC_STEALTH_ACTUAL, m_nStealthActual);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThiefSkillsDlg, CDialog)
	//{{AFX_MSG_MAP(CThiefSkillsDlg)
	ON_EN_CHANGE(IDC_DETECT_TRAPS, OnChangeDetectTraps)
	ON_EN_CHANGE(IDC_OPEN_LOCKS, OnChangeOpenLocks)
	ON_EN_CHANGE(IDC_PICK_POCKETS, OnChangePickPockets)
	ON_EN_CHANGE(IDC_STEALTH, OnChangeStealth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThiefSkillsDlg message handlers

BOOL CThiefSkillsDlg::OnInitDialog() 
{
	// Fill in the Bonuses.
	if (m_nRace < 0 || m_nRace > NUM_THIEFRACEMOD)
		m_nRace = RACE_HUMAN;
	if (m_nDex < 1 || m_nDex > 25)
		m_nDex = 17;
	else
		m_nDex--;

	m_nPickPocketsBase = 15;
	m_nOpenLocksBase = 10;
	m_nDetectTrapsBase = 5;
	m_nStealthBase = 10;

	m_nPickPocketsRace = _thiefRaceMod[m_nRace].nPickPockets;
	m_nOpenLocksRace = _thiefRaceMod[m_nRace].nOpenLocks;
	m_nDetectTrapsRace = _thiefRaceMod[m_nRace].nDetectTraps;
	m_nStealthRace = _thiefRaceMod[m_nRace].nStealth;

	m_nPickPocketsDex = _thiefDexMod[m_nDex].nPickPockets;
	m_nOpenLocksDex = _thiefDexMod[m_nDex].nOpenLocks;
	m_nDetectTrapsDex = _thiefDexMod[m_nDex].nDetectTraps;
	m_nStealthDex = _thiefDexMod[m_nDex].nStealth;

	CDialog::OnInitDialog();

	m_sbtnPickPockets.SetRange(0,100);
	m_sbtnOpenLocks.SetRange(0,100);
	m_sbtnDetectTraps.SetRange(0,100);
	m_sbtnStealth.SetRange(0,100);

	CalculateTotals();
	
	return TRUE;
}

void CThiefSkillsDlg::CalculateTotals()
{
	UpdateData(TRUE);

	m_nPickPocketsActual = m_nPickPockets+m_nPickPocketsBase+m_nPickPocketsRace+m_nPickPocketsDex;
	m_nOpenLocksActual = m_nOpenLocks+m_nOpenLocksBase+m_nOpenLocksRace+m_nOpenLocksDex;
	m_nDetectTrapsActual = m_nDetectTraps+m_nDetectTrapsBase+m_nDetectTrapsRace+m_nDetectTrapsDex;
	m_nStealthActual = m_nStealth+m_nStealthBase+m_nStealthRace+m_nStealthDex;

	UpdateData(FALSE);
}

void CThiefSkillsDlg::OnChangeDetectTraps() 
{
	if (m_sbtnDetectTraps.GetSafeHwnd())
		CalculateTotals();
}

void CThiefSkillsDlg::OnChangeOpenLocks() 
{
	if (m_sbtnOpenLocks.GetSafeHwnd())
		CalculateTotals();
}

void CThiefSkillsDlg::OnChangePickPockets() 
{
	if (m_sbtnPickPockets.GetSafeHwnd())
		CalculateTotals();
}

void CThiefSkillsDlg::OnChangeStealth() 
{
	if (m_sbtnStealth.GetSafeHwnd())
		CalculateTotals();
}
