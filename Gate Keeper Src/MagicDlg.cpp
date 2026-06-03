// MagicDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "MagicDlg.h"
#include "MagicMemorizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMagicDlg dialog


CMagicDlg::CMagicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMagicDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMagicDlg)
	m_nCanMemorize = 0;
	m_nMemorized = 0;
	//}}AFX_DATA_INIT

	for (int i=0;i<MAX_SPELLS;i++)
	{
		m_spells[i].nSpellDesc = -1;
		m_spells[i].nValue1 = 0;
		m_spells[i].nValue2 = 0;
		m_spells[i].nMemorized = 0;
		m_spells[i].szGameCode[0] = '\x0';
	}

	for (i=0;i<MAX_MEMORIZEDINFO;i++)
		memset(&m_memorizedInfo[i],0,sizeof(NPC_MEMORIZEDINFO));

	m_nMemorizedInfo = 0;
}


void CMagicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMagicDlg)
	DDX_Control(pDX, IDC_MAGIC_LEVEL, m_cbLevel);
	DDX_Control(pDX, IDC_MAGIC_TYPE, m_cbMagic);
	DDX_Control(pDX, IDC_REMOVE_FROM_KNOWN, m_btnFromKnown);
	DDX_Control(pDX, IDC_ADD_TO_KNOWN, m_btnToKnown);
	DDX_Control(pDX, IDC_AVAILABLE, m_lcAvailable);
	DDX_Control(pDX, IDC_KNOWN, m_lcKnown);
	DDX_Text(pDX, IDC_CAN_MEMORIZE, m_nCanMemorize);
	DDX_Text(pDX, IDC_MEMORIZED, m_nMemorized);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMagicDlg, CDialog)
	//{{AFX_MSG_MAP(CMagicDlg)
	ON_CBN_SELCHANGE(IDC_MAGIC_TYPE, OnSelchangeMagicType)
	ON_CBN_SELCHANGE(IDC_MAGIC_LEVEL, OnSelchangeMagicLevel)
	ON_BN_CLICKED(IDC_ADD_TO_KNOWN, OnAddToKnown)
	ON_BN_CLICKED(IDC_REMOVE_FROM_KNOWN, OnRemoveFromKnown)
	ON_EN_CHANGE(IDC_CAN_MEMORIZE, OnChangeCanMemorize)
	ON_NOTIFY(NM_DBLCLK, IDC_KNOWN, OnDblclkKnown)
	ON_NOTIFY(NM_DBLCLK, IDC_AVAILABLE, OnDblclkAvailable)
	ON_BN_CLICKED(IDC_SET_MEM, OnSetMem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMagicDlg message handlers

BOOL CMagicDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CRect rect;
	m_lcKnown.GetClientRect(&rect);
	m_lcKnown.InsertColumn(0,"Name",LVCFMT_LEFT,rect.Width()-17-35);
	m_lcKnown.InsertColumn(1,"Mem",LVCFMT_LEFT,35);

	m_lcAvailable.GetClientRect(&rect);
	m_lcAvailable.InsertColumn(0,"Name",LVCFMT_LEFT,rect.Width()-17);

	int nIndex;

	nIndex = m_cbMagic.AddString("Innate");
	m_cbMagic.SetItemData(nIndex,ST_INNATE);
	nIndex = m_cbMagic.AddString("Wizard");
	m_cbMagic.SetItemData(nIndex,ST_WIZARD);
	nIndex = m_cbMagic.AddString("Priest");
	m_cbMagic.SetItemData(nIndex,ST_PRIEST);
	m_cbMagic.SetCurSel(0);

	FillLevels();
	FillAvailable();
	FillKnown();
	FillData();

	m_bmpToKnown.LoadBitmap(IDB_ARROW_DOWN);
	m_bmpFromKnown.LoadBitmap(IDB_ARROW_UP);

	m_btnToKnown.SetBitmap((HBITMAP)m_bmpToKnown.GetSafeHandle());
	m_btnFromKnown.SetBitmap((HBITMAP)m_bmpFromKnown.GetSafeHandle());

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CMagicDlg::FillLevels()
{
	m_cbLevel.ResetContent();
	int nIndex = m_cbMagic.GetCurSel();
	if (nIndex == CB_ERR)
		return;
	int nMagicType = m_cbMagic.GetItemData(nIndex);

	CString strLevel;
	for (int i=0;i<m_nMemorizedInfo;i++)
	{
		if (m_memorizedInfo[i].nSpellType == nMagicType)
		{
			strLevel.Format("%d",m_memorizedInfo[i].nSpellLevel+1);
			nIndex = m_cbLevel.AddString(strLevel);
			m_cbLevel.SetItemData(nIndex,i);
		}
	}

	if (m_cbLevel.GetCount())
		m_cbLevel.SetCurSel(0);
}

void CMagicDlg::FillAvailable()
{
	m_lcAvailable.DeleteAllItems();
	int nLevelIndex = m_cbLevel.GetCurSel();
	if (nLevelIndex == CB_ERR)
		return;
	int nMagicIndex = m_cbMagic.GetCurSel();
	if (nMagicIndex == CB_ERR)
		return;
	int nMagicType = m_cbMagic.GetItemData(nMagicIndex);
	int nMemorizedIndex = m_cbLevel.GetItemData(nLevelIndex);
	char chLevel = m_memorizedInfo[nMemorizedIndex].nSpellLevel + 1 + '0';
	int nItem;
	int nIndex = 0;
	while(_spells[nIndex].nSpellType != ST_ENDOFLIST)
	{
		if (nMagicType == _spells[nIndex].nSpellType && 
			((_spells[nIndex].szGameCode[4] == chLevel && strcmp(_spells[nIndex].szGameCode,"SPWI108")) || (chLevel == '2' && !strcmp(_spells[nIndex].szGameCode,"SPWI108"))) )
		{
			nItem = m_lcAvailable.InsertItem(m_lcAvailable.GetItemCount(),_spells[nIndex].szDescription);
			m_lcAvailable.SetItemData(nItem,nIndex);
		}
		nIndex++;
	}
}

void CMagicDlg::FillKnown()
{
	m_lcKnown.DeleteAllItems();
	int nLevelIndex = m_cbLevel.GetCurSel();
	if (nLevelIndex == CB_ERR)
		return;
	int nMagicIndex = m_cbMagic.GetCurSel();
	if (nMagicIndex == CB_ERR)
		return;
	int nMagicType = m_cbMagic.GetItemData(nMagicIndex);
	int nMemorizedIndex = m_cbLevel.GetItemData(nLevelIndex);
	char chLevel = m_memorizedInfo[nMemorizedIndex].nSpellLevel + 1 + '0';
	int nItem;
	CString strMem;
	for (int i=0;i<MAX_SPELLS;i++)
	{
		if (m_spells[i].nSpellDesc != -1 && nMagicType == _spells[m_spells[i].nSpellDesc].nSpellType && _spells[m_spells[i].nSpellDesc].szGameCode[4] == chLevel)
		{
			strMem.Format("%d",m_spells[i].nMemorized);
			nItem = m_lcKnown.InsertItem(m_lcKnown.GetItemCount(),_spells[m_spells[i].nSpellDesc].szDescription);
			m_lcKnown.SetItemText(nItem,1,strMem);
			m_lcKnown.SetItemData(nItem,i);
		}
	}
}

void CMagicDlg::FillData()
{
	int nLevelIndex = m_cbLevel.GetCurSel();
	if (nLevelIndex == CB_ERR)
	{
		m_nCanMemorize = 0;
		m_nMemorized = 0;
		UpdateData(FALSE);
		return;
	}
	int nMemIndex = m_cbLevel.GetItemData(nLevelIndex);
	m_nCanMemorize = m_memorizedInfo[nMemIndex].nCanMemorize1;
	m_nMemorized = 0;
	int nSpellIndex;
	int nCount = m_lcKnown.GetItemCount();
	for (int i=0;i<nCount;i++)
	{
		nSpellIndex = m_lcKnown.GetItemData(i);
		m_nMemorized += m_spells[nSpellIndex].nMemorized;
	}
	UpdateData(FALSE);
}

void CMagicDlg::GetData()
{
	UpdateData(TRUE);
	int nLevelIndex = m_cbLevel.GetCurSel();
	if (nLevelIndex == CB_ERR)
		return;
	int nMemIndex = m_cbLevel.GetItemData(nLevelIndex);
	m_memorizedInfo[nMemIndex].nCanMemorize1 = m_nCanMemorize;
	m_memorizedInfo[nMemIndex].nCanMemorize2 = m_nCanMemorize;
}

void CMagicDlg::OnSelchangeMagicType() 
{
	FillLevels();
	FillAvailable();
	FillKnown();
	FillData();
}

void CMagicDlg::OnSelchangeMagicLevel() 
{
	FillAvailable();
	FillKnown();
	FillData();
}

void CMagicDlg::OnChangeCanMemorize() 
{
	GetData();
}

void CMagicDlg::OnAddToKnown() 
{
	int nIndex = m_lcAvailable.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
		return;
	int nSpellIndex = m_lcAvailable.GetItemData(nIndex);
	int nItemCount = m_lcKnown.GetItemCount();

	// Make sure it isn't already in the list.
	for (int i=0;i<nItemCount;i++)
		if (m_spells[m_lcKnown.GetItemData(i)].nSpellDesc == nSpellIndex)
			return;

	// Find the next available slot in the spell arrary.
	for (i=0;i<MAX_SPELLS;i++)
		if (m_spells[i].nSpellDesc == -1)
			break;
	if (i == MAX_SPELLS)
		return;

	m_spells[i].nSpellDesc = nSpellIndex;
	m_spells[i].nValue1 = 0;
	m_spells[i].nValue2 = 0;
	m_spells[i].nMemorized = 0;
	m_spells[i].nType = _spells[nSpellIndex].nSpellType;
	strcpy(m_spells[i].szGameCode,_spells[nSpellIndex].szGameCode);

	CString strMem;
	strMem.Format("%d",m_spells[i].nMemorized);
	int nItem = m_lcKnown.InsertItem(m_lcKnown.GetItemCount(),_spells[m_spells[i].nSpellDesc].szDescription);
	m_lcKnown.SetItemText(nItem,1,strMem);
	m_lcKnown.SetItemData(nItem,i);
	m_lcKnown.EnsureVisible(nItem,FALSE);
	m_lcKnown.SetItemState(nItem,LVIS_SELECTED,LVIS_SELECTED);
}

void CMagicDlg::OnRemoveFromKnown() 
{
	int nIndex = m_lcKnown.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
		return;
	int nSpellIndex = m_lcKnown.GetItemData(nIndex);

	m_spells[nSpellIndex].nSpellDesc = -1;
	m_lcKnown.DeleteItem(nIndex);
	FillData();
}

void CMagicDlg::OnDblclkKnown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int nIndex = m_lcKnown.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
		return;
	int nSpellIndex = m_lcKnown.GetItemData(nIndex);

	CMagicMemorizeDlg d;
	d.m_nMemorized = m_spells[nSpellIndex].nMemorized;
	d.m_strSpell = _spells[m_spells[nSpellIndex].nSpellDesc].szDescription;
	if (d.DoModal() == IDOK)
	{
		m_spells[nSpellIndex].nMemorized = d.m_nMemorized;
		CString strMem;
		strMem.Format("%d",d.m_nMemorized);
		m_lcKnown.SetItemText(nIndex,1,strMem);
		FillData();
	}
	*pResult = 0;
}

void CMagicDlg::OnOK() 
{
	CDialog::OnOK();
}

void CMagicDlg::OnDblclkAvailable(NMHDR* pNMHDR, LRESULT* pResult) 
{
	OnAddToKnown();
	*pResult = 0;
}

void CMagicDlg::OnSetMem() 
{
	CMagicMemorizeDlg d;
	d.m_nMemorized = 15;
	d.m_strSpell = "Set All Memorized";
	if (d.DoModal() == IDOK)
	{
		CString strMem;
		int nSpellIndex;
		int nCount = m_lcKnown.GetItemCount();
		for (int i=0;i<nCount;i++)
		{
			nSpellIndex = m_lcKnown.GetItemData(i);
			m_spells[nSpellIndex].nMemorized = d.m_nMemorized;
			strMem.Format("%d",d.m_nMemorized);
			m_lcKnown.SetItemText(i,1,strMem);
		}
		FillData();
	}
}
