// SpellsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "SpellsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpellsDlg dialog


CSpellsDlg::CSpellsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpellsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpellsDlg)
	m_bInnate = TRUE;
	m_bPriest = TRUE;
	m_bWizard = TRUE;
	m_nMemorized = 0;
	//}}AFX_DATA_INIT
	m_nSelectedSpell = -1;
}


void CSpellsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpellsDlg)
	DDX_Control(pDX, IDC_TIMES_MEMORIZED, m_edMemorized);
	DDX_Control(pDX, IDC_CURRENT_SPELL, m_edCurrentSpell);
	DDX_Control(pDX, IDC_SPELL_WIZARD, m_btnWizard);
	DDX_Control(pDX, IDC_SPELL_PRIEST, m_btnPriest);
	DDX_Control(pDX, IDC_SEPLL_INNATE, m_btnInnate);
	DDX_Control(pDX, IDC_SPELLS, m_lcSpells);
	DDX_Check(pDX, IDC_SEPLL_INNATE, m_bInnate);
	DDX_Check(pDX, IDC_SPELL_PRIEST, m_bPriest);
	DDX_Check(pDX, IDC_SPELL_WIZARD, m_bWizard);
	DDX_Text(pDX, IDC_TIMES_MEMORIZED, m_nMemorized);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpellsDlg, CDialog)
	//{{AFX_MSG_MAP(CSpellsDlg)
	ON_BN_CLICKED(IDC_SEPLL_INNATE, OnSepllInnate)
	ON_BN_CLICKED(IDC_SPELL_PRIEST, OnSpellPriest)
	ON_BN_CLICKED(IDC_SPELL_WIZARD, OnSpellWizard)
	ON_NOTIFY(NM_CLICK, IDC_SPELLS, OnClickSpells)
	ON_NOTIFY(NM_DBLCLK, IDC_SPELLS, OnDblclkSpells)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpellsDlg message handlers

BOOL CSpellsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rClient;
	m_lcSpells.GetClientRect(&rClient);
	m_lcSpells.InsertColumn(0,"Type",LVCFMT_LEFT,50);
	m_lcSpells.InsertColumn(1,"Level",LVCFMT_LEFT,45);
	m_lcSpells.InsertColumn(2,"Name",LVCFMT_LEFT,rClient.Width()-112);
	m_lcSpells.DeleteAllItems();

	m_btnInnate.EnableWindow(m_bInnate);
	m_btnWizard.EnableWindow(m_bWizard);
	m_btnPriest.EnableWindow(m_bPriest);

	FillList();

	if (m_nSelectedSpell != -1)
	{
		// Item must match one currently viewable.
		int nSpellIndex;
		int nCount = m_lcSpells.GetItemCount();
		for (int i=0;i<nCount;i++)
		{
			nSpellIndex = m_lcSpells.GetItemData(i);
			if (nSpellIndex == m_nSelectedSpell)
			{
				m_lcSpells.SetItemState(i,LVIS_SELECTED,LVIS_SELECTED);
				m_lcSpells.EnsureVisible(i,FALSE);
				DoClick();
				break;
			}
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CSpellsDlg::FillList()
{
	CString strType;
	CString strLevel;
	int nCount;
	int nIndex;
	BOOL bAdd;

	m_lcSpells.DeleteAllItems();
	UpdateData(TRUE);

	nCount = 0;
	while(_spells[nCount].nSpellType != ST_ENDOFLIST)
	{
		bAdd = FALSE;
		switch(_spells[nCount].nSpellType)
		{
			case ST_INNATE :
				bAdd = m_bInnate;
				strType = "Innate";
				break;
			case ST_WIZARD :
				bAdd = m_bWizard;
				strType = "Wizard";
				break;
			case ST_PRIEST :
				bAdd = m_bPriest;
				strType = "Priest";
				break;
		}
		if (bAdd)
		{
			strLevel.Format("%c",_spells[nCount].szGameCode[4]);
			nIndex = m_lcSpells.InsertItem(m_lcSpells.GetItemCount(),strType);
			m_lcSpells.SetItemText(nIndex,1,strLevel);
			m_lcSpells.SetItemText(nIndex,2,_spells[nCount].szDescription);
			m_lcSpells.SetItemData(nIndex,nCount);
		}
		nCount++;
	}
}

void CSpellsDlg::DoClick()
{
	int nIndex = m_lcSpells.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
	{
		m_edMemorized.EnableWindow(FALSE);
		m_edMemorized.SetWindowText("0");
		m_edCurrentSpell.SetWindowText("");
		return;
	}
	m_edMemorized.EnableWindow(TRUE);
	int nSpellIndex = m_lcSpells.GetItemData(nIndex);
	m_edCurrentSpell.SetWindowText(_spells[nSpellIndex].szDescription);
	UpdateData(FALSE);
}

void CSpellsDlg::OnSepllInnate() 
{
	FillList();
}

void CSpellsDlg::OnSpellPriest() 
{
	FillList();
}

void CSpellsDlg::OnSpellWizard() 
{
	FillList();
}

void CSpellsDlg::OnClickSpells(NMHDR* pNMHDR, LRESULT* pResult) 
{
	DoClick();
	*pResult = 0;
}

void CSpellsDlg::OnDblclkSpells(NMHDR* pNMHDR, LRESULT* pResult) 
{
	OnOK();	
	*pResult = 0;
}

void CSpellsDlg::OnOK() 
{
	int nIndex = m_lcSpells.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
		return;

	m_nSelectedSpell = m_lcSpells.GetItemData(nIndex);
	
	CDialog::OnOK();
}
