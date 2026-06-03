// ItemsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "ItemsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CItemsDlg dialog

CItemsDlg::CItemsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CItemsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CItemsDlg)
	m_bAmulets = TRUE;
	m_bArmor = TRUE;
	m_bBelts = TRUE;
	m_bBooks = TRUE;
	m_bBoots = TRUE;
	m_bCloaks = TRUE;
	m_bGauntlets = TRUE;
	m_bHelms = TRUE;
	m_bMisc = TRUE;
	m_bMissiles = TRUE;
	m_bPotions = TRUE;
	m_bRings = TRUE;
	m_bScrolls = TRUE;
	m_bShields = TRUE;
	m_bWands = TRUE;
	m_bWeapons = TRUE;
	m_nQty = 0;
	//}}AFX_DATA_INIT
	m_nSelectedItem = -1;
}


void CItemsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CItemsDlg)
	DDX_Control(pDX, IDC_MAX_QTY, m_btnMaxQty);
	DDX_Control(pDX, IDC_VIEW_WEAPONS, m_edWeapons);
	DDX_Control(pDX, IDC_VIEW_WANDS, m_edWands);
	DDX_Control(pDX, IDC_VIEW_SHIELDS, m_edShields);
	DDX_Control(pDX, IDC_VIEW_SCROLLS, m_edScrolls);
	DDX_Control(pDX, IDC_VIEW_RINGS, m_edRings);
	DDX_Control(pDX, IDC_VIEW_POTIONS, m_edPotions);
	DDX_Control(pDX, IDC_VIEW_MISSILES, m_edMissiles);
	DDX_Control(pDX, IDC_VIEW_MISC, m_edMisc);
	DDX_Control(pDX, IDC_VIEW_HELMS, m_edHelms);
	DDX_Control(pDX, IDC_VIEW_GAUNTLETS, m_edGauntlets);
	DDX_Control(pDX, IDC_VIEW_BOOTS, m_edBoots);
	DDX_Control(pDX, IDC_VIEW_CLOAKS, m_edCloaks);
	DDX_Control(pDX, IDC_VIEW_BOOKS, m_edBooks);
	DDX_Control(pDX, IDC_VIEW_BELTS, m_edBelts);
	DDX_Control(pDX, IDC_VIEW_ARMOR, m_edArmor);
	DDX_Control(pDX, IDC_VIEW_AMULETS, m_edAmulets);
	DDX_Control(pDX, IDC_QTY, m_edQty);
	DDX_Control(pDX, IDC_CURRENT_ITEM, m_edCurrentItem);
	DDX_Control(pDX, IDC_ITEMS, m_lcItems);
	DDX_Check(pDX, IDC_VIEW_AMULETS, m_bAmulets);
	DDX_Check(pDX, IDC_VIEW_ARMOR, m_bArmor);
	DDX_Check(pDX, IDC_VIEW_BELTS, m_bBelts);
	DDX_Check(pDX, IDC_VIEW_BOOKS, m_bBooks);
	DDX_Check(pDX, IDC_VIEW_BOOTS, m_bBoots);
	DDX_Check(pDX, IDC_VIEW_CLOAKS, m_bCloaks);
	DDX_Check(pDX, IDC_VIEW_GAUNTLETS, m_bGauntlets);
	DDX_Check(pDX, IDC_VIEW_HELMS, m_bHelms);
	DDX_Check(pDX, IDC_VIEW_MISC, m_bMisc);
	DDX_Check(pDX, IDC_VIEW_MISSILES, m_bMissiles);
	DDX_Check(pDX, IDC_VIEW_POTIONS, m_bPotions);
	DDX_Check(pDX, IDC_VIEW_RINGS, m_bRings);
	DDX_Check(pDX, IDC_VIEW_SCROLLS, m_bScrolls);
	DDX_Check(pDX, IDC_VIEW_SHIELDS, m_bShields);
	DDX_Check(pDX, IDC_VIEW_WANDS, m_bWands);
	DDX_Check(pDX, IDC_VIEW_WEAPONS, m_bWeapons);
	DDX_Text(pDX, IDC_QTY, m_nQty);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CItemsDlg, CDialog)
	//{{AFX_MSG_MAP(CItemsDlg)
	ON_BN_CLICKED(IDC_VIEW_AMULETS, OnViewAmulets)
	ON_BN_CLICKED(IDC_VIEW_ARMOR, OnViewArmor)
	ON_BN_CLICKED(IDC_VIEW_BELTS, OnViewBelts)
	ON_BN_CLICKED(IDC_VIEW_BOOKS, OnViewBooks)
	ON_BN_CLICKED(IDC_VIEW_BOOTS, OnViewBoots)
	ON_BN_CLICKED(IDC_VIEW_CLOAKS, OnViewCloaks)
	ON_BN_CLICKED(IDC_VIEW_GAUNTLETS, OnViewGauntlets)
	ON_BN_CLICKED(IDC_VIEW_HELMS, OnViewHelms)
	ON_BN_CLICKED(IDC_VIEW_MISC, OnViewMisc)
	ON_BN_CLICKED(IDC_VIEW_MISSILES, OnViewMissiles)
	ON_BN_CLICKED(IDC_VIEW_POTIONS, OnViewPotions)
	ON_BN_CLICKED(IDC_VIEW_RINGS, OnViewRings)
	ON_BN_CLICKED(IDC_VIEW_SCROLLS, OnViewScrolls)
	ON_BN_CLICKED(IDC_VIEW_SHIELDS, OnViewShields)
	ON_BN_CLICKED(IDC_VIEW_WANDS, OnViewWands)
	ON_BN_CLICKED(IDC_VIEW_WEAPONS, OnViewWeapons)
	ON_BN_CLICKED(IDC_ALL, OnAll)
	ON_BN_CLICKED(IDC_NONE, OnNone)
	ON_NOTIFY(NM_CLICK, IDC_ITEMS, OnClickItems)
	ON_BN_CLICKED(IDC_MAX_QTY, OnMaxQty)
	ON_NOTIFY(NM_DBLCLK, IDC_ITEMS, OnDblclkItems)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CItemsDlg message handlers

BOOL CItemsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rClient;
	m_lcItems.GetClientRect(&rClient);
	m_lcItems.InsertColumn(0,"Name",LVCFMT_LEFT,275);
	m_lcItems.InsertColumn(1,"Type",LVCFMT_LEFT,rClient.Width()-292);

	// Any flags that are marked false when the dialog comes up are
	// assumed to be not available to the user at the time.
	m_edAmulets.EnableWindow(m_bAmulets);
	m_edArmor.EnableWindow(m_bArmor);
	m_edBelts.EnableWindow(m_bBelts);
	m_edBooks.EnableWindow(m_bBooks);
	m_edBoots.EnableWindow(m_bBoots);
	m_edCloaks.EnableWindow(m_bCloaks);
	m_edGauntlets.EnableWindow(m_bGauntlets);
	m_edHelms.EnableWindow(m_bHelms);
	m_edMisc.EnableWindow(m_bMisc);
	m_edMissiles.EnableWindow(m_bMissiles);
	m_edPotions.EnableWindow(m_bPotions);
	m_edRings.EnableWindow(m_bRings);
	m_edScrolls.EnableWindow(m_bScrolls);
	m_edShields.EnableWindow(m_bShields);
	m_edWands.EnableWindow(m_bWands);
	m_edWeapons.EnableWindow(m_bWeapons);

	FillList();

	if (m_nSelectedItem != -1)
	{
		// Item must match one currently viewable.
		int nItem;
		int nCount = m_lcItems.GetItemCount();
		for (int i=0;i<nCount;i++)
		{
			nItem = m_lcItems.GetItemData(i);
			if (!strcmp(_items[m_nSelectedItem].szCode,_items[nItem].szCode) &&
				 !strcmp(_items[m_nSelectedItem].szNumber,_items[nItem].szNumber))
			{
				m_lcItems.SetItemState(i,LVIS_SELECTED,LVIS_SELECTED);
				m_lcItems.EnsureVisible(i,FALSE);
				UINT nQty = m_nQty;	// Need to save this, DoClick will lose it.
				DoClick();
				m_nQty = nQty;
				UpdateData(FALSE);	// REset the quantity.
				break;
			}
		}
	}

	return TRUE;
}

void CItemsDlg::FillList()
{
	int nIndex;
	int nCount;
	BOOL bAdd;

	m_lcItems.DeleteAllItems();
	UpdateData(TRUE);

	nCount = 0;
	while(_items[nCount].nItemType != TYPE_ENDOFLIST)
	{
		bAdd = FALSE;
		switch(_items[nCount].nItemType)
		{
			case TYPE_ARMOR :
				bAdd = m_bArmor;
				break;
			case TYPE_WEAPON :
				bAdd = m_bWeapons;
				break;
			case TYPE_HELM :
				bAdd = m_bHelms;
				break;
			case TYPE_AMULET :
				bAdd = m_bAmulets;
				break;
			case TYPE_MISSILE :
				bAdd = m_bMissiles;
				break;
			case TYPE_BELT :
				bAdd = m_bBelts;
				break;
			case TYPE_RING :
				bAdd = m_bRings;
				break;
			case TYPE_SHIELD :
				bAdd = m_bShields;
				break;
			case TYPE_BOOT :
				bAdd = m_bBoots;
				break;
			case TYPE_CLOAK :
				bAdd = m_bCloaks;
				break;
			case TYPE_POTION :
				bAdd = m_bPotions;
				break;
			case TYPE_GLOVE :
				bAdd = m_bGauntlets;
				break;
			case TYPE_WAND :
				bAdd = m_bWands;
				break;
			case TYPE_BOOK :
				bAdd = m_bBooks;
				break;
			case TYPE_SCROLL :
				bAdd = m_bScrolls;
				break;
			case TYPE_MISC :
				bAdd = m_bMisc;
				break;
		}

		if (bAdd)
		{
			nIndex = m_lcItems.InsertItem(m_lcItems.GetItemCount(),_items[nCount].szDescription);
			m_lcItems.SetItemText(nIndex,1,_itemType[_items[nCount].nItemType].pszType);
			m_lcItems.SetItemData(nIndex,nCount);
		}
		nCount++;
	}
}

void CItemsDlg::OnViewAmulets() 
{
	FillList();
}

void CItemsDlg::OnViewArmor() 
{
	FillList();
}

void CItemsDlg::OnViewBelts() 
{
	FillList();
}

void CItemsDlg::OnViewBooks() 
{
	FillList();
}

void CItemsDlg::OnViewBoots() 
{
	FillList();
}

void CItemsDlg::OnViewCloaks() 
{
	FillList();
}

void CItemsDlg::OnViewGauntlets() 
{
	FillList();
}

void CItemsDlg::OnViewHelms() 
{
	FillList();
}

void CItemsDlg::OnViewMisc() 
{
	FillList();
}

void CItemsDlg::OnViewMissiles() 
{
	FillList();
}

void CItemsDlg::OnViewPotions() 
{
	FillList();
}

void CItemsDlg::OnViewRings() 
{
	FillList();
}

void CItemsDlg::OnViewScrolls() 
{
	FillList();
}

void CItemsDlg::OnViewShields() 
{
	FillList();
}

void CItemsDlg::OnViewWands() 
{
	FillList();
}

void CItemsDlg::OnViewWeapons() 
{
	FillList();
}

void CItemsDlg::OnAll() 
{
	m_bAmulets = TRUE;
	m_bArmor = TRUE;
	m_bBelts = TRUE;
	m_bBooks = TRUE;
	m_bBoots = TRUE;
	m_bCloaks = TRUE;
	m_bGauntlets = TRUE;
	m_bHelms = TRUE;
	m_bMisc = TRUE;
	m_bMissiles = TRUE;
	m_bPotions = TRUE;
	m_bRings = TRUE;
	m_bScrolls = TRUE;
	m_bShields = TRUE;
	m_bWands = TRUE;
	m_bWeapons = TRUE;
	
	// Checking the window handle so I can use this function externally.
	if (GetSafeHwnd())
	{
		UpdateData(FALSE);
		FillList();
	}
}

void CItemsDlg::OnNone() 
{
	m_bAmulets = FALSE;
	m_bArmor = FALSE;
	m_bBelts = FALSE;
	m_bBooks = FALSE;
	m_bBoots = FALSE;
	m_bCloaks = FALSE;
	m_bGauntlets = FALSE;
	m_bHelms = FALSE;
	m_bMisc = FALSE;
	m_bMissiles = FALSE;
	m_bPotions = FALSE;
	m_bRings = FALSE;
	m_bScrolls = FALSE;
	m_bShields = FALSE;
	m_bWands = FALSE;
	m_bWeapons = FALSE;

	// Checking the window handle so I can use this function externally.
	if (GetSafeHwnd())
	{
		UpdateData(FALSE);
		FillList();
	}
}

void CItemsDlg::DoClick()
{
	int nIndex = m_lcItems.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
	{
		m_edQty.EnableWindow(FALSE);
		m_edQty.SetWindowText("0");
		m_edCurrentItem.SetWindowText("");
		return;
	}

	int nItem = m_lcItems.GetItemData(nIndex);

	m_edQty.EnableWindow(_items[nItem].bStackable);
	m_btnMaxQty.EnableWindow(_items[nItem].bStackable);
	if (m_edQty.IsWindowEnabled())
	{
		if (_items[nItem].nItemType == TYPE_POTION)
			m_nQty = (short)MAX_QTY_POTION;
		else
			m_nQty = (short)MAX_QTY;
		UpdateData(FALSE);
	}
	else
		m_edQty.SetWindowText("0");
	m_edCurrentItem.SetWindowText(_items[nItem].szDescription);
}

void CItemsDlg::OnClickItems(NMHDR* pNMHDR, LRESULT* pResult) 
{
	DoClick();
	*pResult = 0;
}

void CItemsDlg::OnOK() 
{
	int nIndex = m_lcItems.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex != -1)
		m_nSelectedItem = m_lcItems.GetItemData(nIndex);
	else
		m_nSelectedItem = -1;
	CDialog::OnOK();
}

void CItemsDlg::OnMaxQty() 
{
	m_nQty = MAX_QTY;
	UpdateData(FALSE);
}

void CItemsDlg::OnDblclkItems(NMHDR* pNMHDR, LRESULT* pResult) 
{
	OnOK();	
	*pResult = 0;
}
