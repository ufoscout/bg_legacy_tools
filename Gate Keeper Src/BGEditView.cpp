// BGEditView.cpp : implementation of the CBGEditView class
//

#include "stdafx.h"
#include "BGEdit.h"
#include "BGEditDoc.h"
#include "BGEditView.h"
#include "QuadButton.h"
#include "ItemsDlg.h"
#include "SpellsDlg.h"
#include "ProficienciesDlg.h"
#include "MagicDlg.h"
#include "CharacteristicsDlg.h"
#include "SavingThrowDlg.h"
#include "DualClassDlg.h"
#include "ThiefSkillsDlg.h"
#include "LocationDlg.h"
#include "AppearanceDlg.h"
#include "MiscAbilitiesDlg.h"
#include "ChangeNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBGEditView



IMPLEMENT_DYNCREATE(CBGEditView, CFormView)

BEGIN_MESSAGE_MAP(CBGEditView, CFormView)
	//{{AFX_MSG_MAP(CBGEditView)
	ON_BN_CLICKED(IDC_CHAR1, OnChar1)
	ON_BN_CLICKED(IDC_CHAR2, OnChar2)
	ON_BN_CLICKED(IDC_CHAR3, OnChar3)
	ON_BN_CLICKED(IDC_CHAR4, OnChar4)
	ON_BN_CLICKED(IDC_CHAR5, OnChar5)
	ON_BN_CLICKED(IDC_CHAR6, OnChar6)
	ON_BN_CLICKED(IDC_MAX_QTY, OnMaxQty)
	ON_BN_CLICKED(IDC_DELETEITEM, OnDeleteitem)
	ON_BN_CLICKED(IDC_EDITITEM, OnEdititem)
	ON_NOTIFY(NM_DBLCLK, IDC_INVENTORY, OnDblclkInventory)
	ON_BN_CLICKED(IDC_EDIT_PROFICIENCIES, OnEditProficiencies)
	ON_BN_CLICKED(IDC_EDIT_MAGIC, OnEditMagic)
	ON_BN_CLICKED(IDC_EDIT_CHARACTERISTICS, OnEditCharacteristics)
	ON_BN_CLICKED(IDC_EDIT_SAVES, OnEditSaves)
	ON_BN_CLICKED(IDC_EDIT_DUAL, OnEditDual)
	ON_BN_CLICKED(IDC_EDIT_THIEF, OnEditThief)
	ON_BN_CLICKED(IDC_EDIT_LOCATION, OnEditLocation)
	ON_BN_CLICKED(IDC_EDIT_APPEARANCE, OnEditAppearance)
	ON_BN_CLICKED(IDC_EDIT_MISC_ABILITIES, OnEditMiscAbilities)
	ON_COMMAND(ID_HELP_VIEWREADMETXT, OnHelpViewreadmetxt)
	//}}AFX_MSG_MAP
	// Standard printing commands
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBGEditView construction/destruction

CBGEditView::CBGEditView()
	: CFormView(CBGEditView::IDD)
{
	//{{AFX_DATA_INIT(CBGEditView)
	m_nStr = 0;
	m_nStrBonus = 0;
	m_nDex = 0;
	m_nCha = 0;
	m_nCon = 0;
	m_nInt = 0;
	m_nWis = 0;
	m_nExp = 1;
	m_nGold = 0;
	m_nMaxHp = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_nNumChars = 0;
	m_nMemorizedInfo = 0;
	ClearSpells();
}

CBGEditView::~CBGEditView()
{
}

void CBGEditView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBGEditView)
	DDX_Control(pDX, IDC_STR, m_edStr);
	DDX_Control(pDX, IDC_EDIT_THIEF, m_btnThief);
	DDX_Control(pDX, IDC_EDIT_SAVES, m_btnSaves);
	DDX_Control(pDX, IDC_EDIT_PROFICIENCIES, m_btnProficiencies);
	DDX_Control(pDX, IDC_EDIT_MAGIC, m_btnMagic);
	DDX_Control(pDX, IDC_EDIT_LOCATION, m_btnLocation);
	DDX_Control(pDX, IDC_EDIT_DUAL, m_btnDualOnly);
	DDX_Control(pDX, IDC_INVENTORY, m_lcInventory);
	DDX_Control(pDX, IDC_SPIN_WIS, m_sbtnWis);
	DDX_Control(pDX, IDC_SPIN_INT, m_sbtnInt);
	DDX_Control(pDX, IDC_SPIN_CON, m_sbtnCon);
	DDX_Control(pDX, IDC_SPIN_CHA, m_sbtnCha);
	DDX_Control(pDX, IDC_SPIN_DEX, m_sbtnDex);
	DDX_Control(pDX, IDC_SPIN_STR_BONUS, m_sbtnStrBonus);
	DDX_Control(pDX, IDC_SPIN_STR, m_sbtnStr);
	DDX_Control(pDX, IDC_CHAR6, m_btnChar6);
	DDX_Control(pDX, IDC_CHAR5, m_btnChar5);
	DDX_Control(pDX, IDC_CHAR4, m_btnChar4);
	DDX_Control(pDX, IDC_CHAR3, m_btnChar3);
	DDX_Control(pDX, IDC_CHAR2, m_btnChar2);
	DDX_Control(pDX, IDC_CHAR1, m_btnChar1);
	DDX_Text(pDX, IDC_STR, m_nStr);
	DDV_MinMaxUInt(pDX, m_nStr, 3, 25);
	DDX_Text(pDX, IDC_STR_BONUS, m_nStrBonus);
	DDV_MinMaxUInt(pDX, m_nStrBonus, 0, 100);
	DDX_Text(pDX, IDC_DEX, m_nDex);
	DDV_MinMaxUInt(pDX, m_nDex, 3, 25);
	DDX_Text(pDX, IDC_CHA, m_nCha);
	DDV_MinMaxUInt(pDX, m_nCha, 3, 25);
	DDX_Text(pDX, IDC_CON, m_nCon);
	DDV_MinMaxUInt(pDX, m_nCon, 3, 25);
	DDX_Text(pDX, IDC_INT, m_nInt);
	DDV_MinMaxUInt(pDX, m_nInt, 3, 25);
	DDX_Text(pDX, IDC_WIS, m_nWis);
	DDV_MinMaxUInt(pDX, m_nWis, 3, 25);
	DDX_Text(pDX, IDC_EXP, m_nExp);
	DDV_MinMaxUInt(pDX, m_nExp, 0, 100000000);
	DDX_Text(pDX, IDC_GOLD, m_nGold);
	DDV_MinMaxUInt(pDX, m_nGold, 0, 5000000);
	DDX_Text(pDX, IDC_HP_BASE, m_nMaxHp);
	DDV_MinMaxUInt(pDX, m_nMaxHp, 1, 32000);
	//}}AFX_DATA_MAP
}

BOOL CBGEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CBGEditView::OnInitialUpdate()
{
	AfxGetMainWnd()->SetWindowText("Baldur's Gate Game Editor");

	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);

	CRect rClient;
	m_lcInventory.GetClientRect(&rClient);
	m_lcInventory.InsertColumn(0,"Position",LVCFMT_LEFT,50);
	m_lcInventory.InsertColumn(1,"Type",LVCFMT_LEFT,50);
	m_lcInventory.InsertColumn(2,"Qty",LVCFMT_LEFT,50);
	m_lcInventory.InsertColumn(3,"Name",LVCFMT_LEFT,rClient.Width()-167);
	m_lcInventory.DeleteAllItems();

	ClearAll();
}

void CBGEditView::ClearInventory()
{
	m_lcInventory.DeleteAllItems();

	int nIndex;
	for (int i=NUM_ITEM_SLOTS-1;i>-1;i--)
	{
		if (_itemPos[i].pszPos)
		{
			nIndex = m_lcInventory.InsertItem(0,_itemPos[i].pszPos);
			m_lcInventory.SetItemData(nIndex,i);
		}
	}
}

void CBGEditView::ClearSpells()
{
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
}

/////////////////////////////////////////////////////////////////////////////
// CBGEditView diagnostics

#ifdef _DEBUG
void CBGEditView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBGEditView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBGEditDoc* CBGEditView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBGEditDoc)));
	return (CBGEditDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBGEditView message handlers

void CBGEditView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	switch(lHint)
	{
		case HINT_LOAD :
			FileLoaded();
			FetchValues(m_nCurrentChar);
			break;
		case HINT_SAVE :
			PutValues(m_nCurrentChar);
			break;
		case HINT_CLEAR :
			ClearAll();
			break;
	}
}

void CBGEditView::FileLoaded()
{
	m_btnChar1.SetWindowText("None");
	m_btnChar2.SetWindowText("None");
	m_btnChar3.SetWindowText("None");
	m_btnChar4.SetWindowText("None");
	m_btnChar5.SetWindowText("None");
	m_btnChar6.SetWindowText("None");
	
	if (GetDocument()->IsExported())
	{
		m_nNumChars = 1;

		NPC_HEADER *pHeader = GetNpcHeader(0);
		if (!pHeader)
		{
			m_nNumChars = 0;
			EnableControls();
			return;
		}

		m_btnChar1.SetWindowText(GetDocument()->FixName(GetDocument()->m_pChrHeader->szName));
	}
	else
	{
		if (GetDocument()->m_pFileHeader)
		{
			m_nNumChars = GetDocument()->m_pFileHeader->nPartyCount;
			m_nGold = GetDocument()->m_pFileHeader->nGold;
		}
		else
		{
			m_nNumChars = 0;
			m_nGold = 0;
		}

		NPC_HEADER *pHeader;
		NPC_INFO *pInfo;
		CString strName;
		for (int i=0;i<m_nNumChars;i++)
		{
			pInfo = (NPC_INFO*)(GetDocument()->m_pData+GetDocument()->m_pFileHeader->nPartyOffset+sizeof(NPC_INFO)*i);
			if (!strcmp(pInfo->szName,""))
			{
				pHeader = GetNpcHeader(i);
				if (!pHeader)
					strName = "Error";
				else
					strName = GetDocument()->FixName(pHeader->szName);
			}
			else
				strName = GetDocument()->FixName(pInfo->szName);
			switch(i)
			{
				case 0 :
					m_btnChar1.SetWindowText(strName);
					break;
				case 1 :
					m_btnChar2.SetWindowText(strName);
					break;
				case 2 :
					m_btnChar3.SetWindowText(strName);
					break;
				case 3 :
					m_btnChar4.SetWindowText(strName);
					break;
				case 4 :
					m_btnChar5.SetWindowText(strName);
					break;
				case 5 :
					m_btnChar6.SetWindowText(strName);
					break;
			}
		}
	}

	EnableControls();
	SetCurrentChar(0);
	m_edStr.SetFocus();
}

NPC_HEADER* CBGEditView::GetNpcHeader(int nIndex)
{
	if (!m_nNumChars || nIndex < 0 || nIndex >= m_nNumChars)
		return(NULL);

	return((NPC_HEADER*)(GetDocument()->m_character[nIndex].pCharacter));
}

NPC_INFO* CBGEditView::GetNpcInfo(int nIndex)
{
	if (GetDocument()->IsExported())
		return(NULL);
	if (!m_nNumChars || nIndex < 0 || nIndex >= m_nNumChars)
		return(NULL);
	return((NPC_INFO*)(GetDocument()->m_pData+GetDocument()->m_pFileHeader->nPartyOffset+sizeof(NPC_INFO)*nIndex));
}

void CBGEditView::FetchValues(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_nNumChars)
		return;
	NPC_HEADER *pHeader;
	pHeader = GetNpcHeader(nIndex);
	if (!pHeader)
		return;
	NPC_INFO *pInfo = GetNpcInfo(nIndex);
	if (!GetDocument()->IsExported() && !pInfo)
		return;

	if (!GetDocument()->IsExported())
	{
		m_strArea = pInfo->szArea;
		m_nMapX = pInfo->nPlayerX;
		m_nMapY = pInfo->nPlayerY;
		m_nGold = GetDocument()->m_pFileHeader->nGold;
	}
	else
		m_nGold = pHeader->nGold;

	m_btnDualOnly.EnableWindow(pHeader->chDualClass >= 8);

	m_nStr = pHeader->chStr;
	m_nStrBonus = pHeader->chStrBonus;
	m_nDex = pHeader->chDex;
	m_nCon = pHeader->chCon;
	m_nInt = pHeader->chInt;
	m_nWis = pHeader->chWis;
	m_nCha = pHeader->chCha;
	m_nExp = pHeader->nExperience;

	m_chAvatar = pHeader->chAvatar;
	m_chAvatarClass = pHeader->chAvatarClass;

	m_nProfLgSword = LOTRIBBLE(pHeader->chProfLargeSword);
	m_nProfSmSword = LOTRIBBLE(pHeader->chProfSmallSword);
	m_nProfBow = LOTRIBBLE(pHeader->chProfBow);
	m_nProfSpear = LOTRIBBLE(pHeader->chProfSpear);
	m_nProfBlunt = LOTRIBBLE(pHeader->chProfBlunt);
	m_nProfSpiked = LOTRIBBLE(pHeader->chProfSpiked);
	m_nProfAxe = LOTRIBBLE(pHeader->chProfAxe);
	m_nProfMissile = LOTRIBBLE(pHeader->chProfMissile);

	m_nProfLgSword2 = HITRIBBLE(pHeader->chProfLargeSword);
	m_nProfSmSword2 = HITRIBBLE(pHeader->chProfSmallSword);
	m_nProfBow2 = HITRIBBLE(pHeader->chProfBow);
	m_nProfSpear2 = HITRIBBLE(pHeader->chProfSpear);
	m_nProfBlunt2 = HITRIBBLE(pHeader->chProfBlunt);
	m_nProfSpiked2 = HITRIBBLE(pHeader->chProfSpiked);
	m_nProfAxe2 = HITRIBBLE(pHeader->chProfAxe);
	m_nProfMissile2 = HITRIBBLE(pHeader->chProfMissile);

	m_chSex = pHeader->chSex;
	m_chRace = pHeader->chRace;
	m_chClass = pHeader->chClass;
	m_nMageSpecialty = pHeader->nMageSpecialty;
	m_chAlignment = pHeader->chAlignment;

	m_chAC = pHeader->chAC;
	m_chThac0 = pHeader->chThac0;
	m_chNumberOfAttacks = pHeader->chNumberOfAttacks;
	m_chRacialEnemy = pHeader->chRacialEnemy;
	m_chLore = pHeader->chLore;
	m_chMagicResist = pHeader->chMagicResist;

	m_chSavePPD = pHeader->chSavePPD;
	m_chSaveRSW = pHeader->chSaveRSW;
	m_chSavePP = pHeader->chSavePP;
	m_chSaveBW = pHeader->chSaveBW;
	m_chSaveS = pHeader->chSaveS;

	m_chFindTraps = pHeader->chFindTraps;
	m_chOpenLocks = pHeader->chOpenLocks;
	m_chStealth = pHeader->chStealth;
	m_chPickPockets = pHeader->chPickPockets;

	m_chLevel[0] = pHeader->chLevel[0];
	m_chLevel[1] = pHeader->chLevel[1];
	m_chLevel[2] = pHeader->chLevel[2];

	m_nMaxHp = pHeader->nMaxHp;

	UpdateData(FALSE);
	FetchItems(nIndex);
	if (!FetchSpells(nIndex))
	{
		ClearAll();
		return;
	}
}

void CBGEditView::ClearItem(int nPos, BOOL bUpdateList)
{
	ASSERT(nPos >= 0 && nPos < NUM_ITEM_SLOTS);

	m_inv[nPos].bIndentified = TRUE;
	m_inv[nPos].bStackable = FALSE;
	m_inv[nPos].nItemType = TYPE_UNKNOWN;
	m_inv[nPos].nQuantity = 0;
	strcpy(m_inv[nPos].szCode,"");
	strcpy(m_inv[nPos].szDescription,"");
	strcpy(m_inv[nPos].szNumber,"");

	if (bUpdateList)
		PutInList(nPos);
}

BOOL CBGEditView::AddKnownSpell(SPELL *pSpell, int nIndex)
{
	m_spells[nIndex].nValue1 = 0;
	m_spells[nIndex].nValue2 = 0;
	strcpy(m_spells[nIndex].szGameCode,pSpell->szSpell);
	int j = 0;
	while(_spells[j].nSpellType != ST_ENDOFLIST)
	{
		if (!strcmp(_spells[j].szGameCode,pSpell->szSpell))
		{
			m_spells[nIndex].nSpellDesc = j;
			m_spells[nIndex].nType = _spells[j].nSpellType;
			break;
		}
		j++;
	}
	if (_spells[j].nSpellType == ST_ENDOFLIST)
	{
		CString strCode;
		strncpy(strCode.GetBufferSetLength(5),m_spells[nIndex].szGameCode,4);
		strCode.ReleaseBuffer(4);
		strCode.MakeUpper();
		if (strCode == "SPWI")
			m_spells[nIndex].nType = ST_WIZARD;
		else
			if (strCode == "SPIN")
				m_spells[nIndex].nType = ST_INNATE;
			else
				if (strCode == "SPPR")
					m_spells[nIndex].nType = ST_PRIEST;
				else
					return(FALSE);
		m_spells[nIndex].nSpellDesc = j;
	}
	return(TRUE);
}

BOOL CBGEditView::FetchSpells(int nIndex)
{
	CString strCode;
	SPELL *pSpell;
	UINT nOff;
	int i,j;

	if (nIndex < 0 || nIndex >= m_nNumChars)
		return(FALSE);
	ClearSpells();

	NPC_HEADER* pHeader = GetNpcHeader(nIndex);
	ASSERT(pHeader != NULL);
	if (!pHeader)
	{
		AfxMessageBox("Spell read error.");
		return(FALSE);
	}

	for (i=0;i<pHeader->nMemorizedInfo;i++)
	{
		nOff = pHeader->nMemorizedInfoOffset + sizeof(NPC_MEMORIZEDINFO) * i;
		memcpy(&m_memorizedInfo[i],(char*)(pHeader)+nOff,sizeof(NPC_MEMORIZEDINFO));
	}
	m_nMemorizedInfo = pHeader->nMemorizedInfo;
	// Check for the innate info block. If it doesn't exist give the character one so
	// they can add innate abilities.
	for (i=0;i<m_nMemorizedInfo;i++)
		if (m_memorizedInfo[i].nSpellType == ST_INNATE)
			break;
	if (i == m_nMemorizedInfo)
	{
		memset(&m_memorizedInfo[i],0,sizeof(NPC_MEMORIZEDINFO));
		m_memorizedInfo[i].nSpellType = ST_INNATE;
		m_nMemorizedInfo++;
	}

	for (i=0;i<pHeader->nKnownSpells;i++)
	{
		nOff = pHeader->nKnownOffset+sizeof(SPELL)*i;
		pSpell = (SPELL*)((char*)pHeader+nOff);
		if (!AddKnownSpell(pSpell,i))
		{
			MessageBox("Unknown spell type. Cannot load.","Warning",MB_ICONWARNING);
			return(FALSE);
		}
	}

	for (i=0;i<pHeader->nMemorizedSpells;i++)
	{
		nOff = pHeader->nMemorizedOffset+sizeof(SPELL)*i;
		pSpell = (SPELL*)((char*)pHeader+nOff);
		for (j=0;j<MAX_SPELLS;j++)
		{
			if (m_spells[j].nSpellDesc != -1 && !strcmp(m_spells[j].szGameCode,pSpell->szSpell))
			{
				m_spells[j].nMemorized++;
				break;
			}
		}
		if (j == MAX_SPELLS)
		{
			// A matching known spell was not found. Add it to the list of known spells.
			for (j=0;j<MAX_SPELLS;j++)
			{
				if (m_spells[j].nSpellDesc == -1)
				{
					if (!AddKnownSpell(pSpell,j))
					{
						MessageBox("Unkown spell type. Cannot load.","Warning",MB_ICONWARNING);
						return(FALSE);
					}
					m_spells[j].nMemorized++;
					break;
				}
			}
			if (j == MAX_SPELLS)
			{
				MessageBox("Error adding a memorized spell to the list of known spells. Cannot Load.","Warning",MB_ICONWARNING);
				return(FALSE);
			}
		}
	}


	return(TRUE);
}

void CBGEditView::FetchItems(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_nNumChars)
		return;

	int i,j;
	for (i=0;i<NUM_ITEM_SLOTS;i++)
		ClearItem(i,FALSE);
	ClearInventory();

	NPC_HEADER* pHeader = GetNpcHeader(nIndex);
	ASSERT(pHeader != NULL);
	if (!pHeader)
	{
		AfxMessageBox("Inventory read error.");
		return;
	}
	NPC_ITEMSLOTS* pSlots = GetNpcItemSlots(pHeader);
	if (!pSlots)
	{
		AfxMessageBox("Inventory read error.");
		return;
	}

	ITEM *pItem;
//	char *ptr = (char*)(pSlots) + sizeof(NPC_ITEMSLOTS);
	UINT nOff;
	for (i=0;i<pHeader->nItems;i++)
	{
		nOff = pHeader->nItemOffset + i * sizeof(ITEM);
		pItem = (ITEM*)((char *)(pHeader)+nOff);

		// Find where it goes.
		for (j=0;j<NUM_ITEM_SLOTS;j++)
			if (pSlots->nItemSlot[j] == i)
			{
				ConvertBufferItem(j,pItem);
				PutInList(j);
				break;
			}

		if (j == NUM_ITEM_SLOTS)
			AfxMessageBox("Unknown equipment position.");
	}
}

void CBGEditView::PutInList(int nPos)
{
	if (strcmp(m_inv[nPos].szCode,""))
	{
		CString strQty;
		strQty.Format("%d",(unsigned short)m_inv[nPos].nQuantity);
		m_lcInventory.SetItemText(nPos,1,_itemType[m_inv[nPos].nItemType].pszType);
		m_lcInventory.SetItemText(nPos,2,strQty);
		m_lcInventory.SetItemText(nPos,3,m_inv[nPos].szDescription);
	}
	else
	{
		m_lcInventory.SetItemText(nPos,1,"");
		m_lcInventory.SetItemText(nPos,2,"");
		m_lcInventory.SetItemText(nPos,3,"");
	}
}

void CBGEditView::ConvertBufferItem(int nPos, ITEM* pItem)
{
	CString strItem;
	CString strNum;
	CString strType;

	strItem = pItem->szItem;
	strNum = strItem.Right(2);
	strType = strItem.Left(strItem.GetLength()-2);

	int nIndex = 0;
	while(_items[nIndex].nItemType != TYPE_ENDOFLIST)
	{
		if (strType == _items[nIndex].szCode && strNum == _items[nIndex].szNumber)
		{
			m_inv[nPos].bIndentified = TRUE;
			m_inv[nPos].bStackable = _items[nIndex].bStackable;
			m_inv[nPos].nItemType = _items[nIndex].nItemType;
			m_inv[nPos].nQuantity = pItem->nCount;
			strcpy(m_inv[nPos].szCode,strType);
			strcpy(m_inv[nPos].szDescription,_items[nIndex].szDescription);
			strcpy(m_inv[nPos].szNumber,strNum);
			return;
		}
		nIndex++;
	}
	
	// Unknown item, preserve the info in the object, users can't edit.
	m_inv[nPos].bIndentified = pItem->nIdentified;
	m_inv[nPos].bStackable = FALSE;
	m_inv[nPos].nItemType = TYPE_UNKNOWN;
	m_inv[nPos].nQuantity = pItem->nCount;
	strcpy(m_inv[nPos].szCode,strType);
	sprintf(m_inv[nPos].szDescription,"Unknown:%s",(const char *)strItem);
	strcpy(m_inv[nPos].szNumber,strNum);
}

NPC_ITEMSLOTS* CBGEditView::GetNpcItemSlots(NPC_HEADER *pHeader)
{
	ASSERT(pHeader != NULL);
	if (!pHeader)
		return(NULL);

	/*UINT nOff = sizeof(NPC_HEADER);
	nOff += sizeof(SPELL) * pHeader->nKnownSpells;
	nOff += sizeof(NPC_BETWEENSPELL) * pHeader->nBetweenSpells;
	nOff += sizeof(SPELL) * pHeader->nMemorizedSpells; */
	return((NPC_ITEMSLOTS*)((char*)pHeader+pHeader->nItemSlotOffset));
}

void CBGEditView::PutValues(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_nNumChars)
		return;

	NPC_HEADER *pHeader = GetNpcHeader(nIndex);
	if (!pHeader)
		return;
	NPC_INFO *pInfo = GetNpcInfo(nIndex);
	if (!GetDocument()->IsExported() && !pInfo)
		return;

	UINT nOrigLen = GetDocument()->m_character[nIndex].nBufLen;

	UINT nNewLen = sizeof(NPC_HEADER);
	nNewLen += sizeof(SPELL) * GetSpellCount(TRUE);
	nNewLen += sizeof(NPC_MEMORIZEDINFO) * m_nMemorizedInfo;
	nNewLen += sizeof(SPELL) * GetSpellCount(FALSE);
	nNewLen += sizeof(NPC_ITEMSLOTS);
	nNewLen += sizeof(ITEM) * GetItemCount();
	nNewLen += sizeof(NPC_AFTERITEM) * pHeader->nAfterItems;

	// Always want to create a new character record and then copy the data
	// into the main buffer. The adjustments for buffer differences are made
	// below to make more or less room. This assures that even if the buffers
	// are the same size that the data is correctly gets copied.
	unsigned char *pBuf = new unsigned char[nNewLen];
	if (!pBuf)
	{
		AfxMessageBox("Cannot create copy buffer. Unable to save data.");
		return;
	}
	NPC_HEADER *pNewHeader = (NPC_HEADER*)pBuf;

	UINT nSrcOff = 0;
	UINT nDestOff = 0;
	memcpy(pBuf,pHeader,sizeof(NPC_HEADER));

	pNewHeader->nKnownSpells = GetSpellCount(TRUE);
	pNewHeader->nKnownOffset = sizeof(NPC_HEADER);
	pNewHeader->nMemorizedInfo = m_nMemorizedInfo;
	pNewHeader->nMemorizedInfoOffset = pNewHeader->nKnownOffset + pNewHeader->nKnownSpells * sizeof(SPELL);
	pNewHeader->nMemorizedSpells = GetSpellCount(FALSE);
	pNewHeader->nMemorizedOffset = pNewHeader->nMemorizedInfoOffset + pNewHeader->nMemorizedInfo * sizeof(NPC_MEMORIZEDINFO);
	pNewHeader->nItemSlotOffset = pNewHeader->nMemorizedOffset + pNewHeader->nMemorizedSpells * sizeof(SPELL);
	pNewHeader->nItems = GetItemCount();
	pNewHeader->nItemOffset = pNewHeader->nItemSlotOffset + sizeof(NPC_ITEMSLOTS);
	if (pNewHeader->nAfterItems)
		pNewHeader->nAfterItemsOffset = pNewHeader->nItemOffset + pNewHeader->nItems * sizeof(ITEM);

	nSrcOff = sizeof(NPC_HEADER);
	nDestOff = sizeof(NPC_HEADER);
	if (pNewHeader->nKnownSpells)
	{
		if (CreateSpells((SPELL*)(pBuf+nDestOff),TRUE) != pNewHeader->nKnownSpells)
		{
			MessageBox("Unable to properly recreate the known spell data. Unable to save.","Warning",
				MB_ICONWARNING);
			delete [] pBuf;
			return;
		}
		nDestOff += sizeof(SPELL) * pNewHeader->nKnownSpells;
	}
	if (pHeader->nKnownSpells)
		nSrcOff += sizeof(SPELL) * pHeader->nKnownSpells;
	CreateMemorizedInfo((NPC_MEMORIZEDINFO*)(pBuf+nDestOff));
	nDestOff += sizeof(NPC_MEMORIZEDINFO) * pNewHeader->nMemorizedInfo;
	nSrcOff += sizeof(NPC_MEMORIZEDINFO) * pHeader->nMemorizedInfo;
	if (pNewHeader->nMemorizedSpells)
	{
		if (CreateSpells((SPELL*)(pBuf+nDestOff),FALSE) != pNewHeader->nMemorizedSpells)
		{
			MessageBox("Unable to properly recreate the memorized spell data. Unable to save.",
				"Warning",MB_ICONWARNING);
			delete [] pBuf;
			return;
		}
		nDestOff += sizeof(SPELL) * pNewHeader->nMemorizedSpells;
	}
	if (pHeader->nMemorizedSpells)
		nSrcOff += sizeof(SPELL) * pHeader->nMemorizedSpells;
	CreateItemSlots((NPC_ITEMSLOTS*)(pBuf+nDestOff));
	nSrcOff += sizeof(NPC_ITEMSLOTS);
	nDestOff += sizeof(NPC_ITEMSLOTS);
	CreateItems((ITEM*)(pBuf+nDestOff));
	nSrcOff += pHeader->nItems * sizeof(ITEM);
	nDestOff += pNewHeader->nItems * sizeof(ITEM);
	memcpy(pBuf+nDestOff,((char*)pHeader)+nSrcOff,sizeof(NPC_AFTERITEM)*pHeader->nAfterItems);
	nSrcOff += sizeof(NPC_AFTERITEM)*pHeader->nAfterItems;
	nDestOff += sizeof(NPC_AFTERITEM)*pHeader->nAfterItems;

	// Both offsets at this point should equal the buffer length if everything
	// went as planned.
	if (nSrcOff != GetDocument()->m_character[nIndex].nBufLen)
	{
		MessageBox("There has been an error recreating the game information from the"
			" source buffer. Unable to save the changes.","Warning",MB_ICONWARNING);
		delete [] pBuf;
		return;
	}
	if (nDestOff != nNewLen)
	{
		MessageBox("There has been an error recreating the game information. The data"
			" created is smaller than expected.","Warning",MB_ICONWARNING);
		delete [] pBuf;
		return;
	}

	delete [] GetDocument()->m_character[nIndex].pCharacter;
	GetDocument()->m_character[nIndex].nBufLen = nNewLen;
	GetDocument()->m_character[nIndex].pCharacter = pBuf;
	pHeader = (NPC_HEADER*)pBuf;

	UpdateData(TRUE);

	pHeader->chStr = m_nStr;
	pHeader->chStrBonus = m_nStrBonus;
	pHeader->chDex = m_nDex;
	pHeader->chCon = m_nCon;
	pHeader->chInt = m_nInt;
	pHeader->chWis = m_nWis;
	pHeader->chCha = m_nCha;
	pHeader->nExperience = m_nExp;

	pHeader->chAvatar = m_chAvatar;
	pHeader->chAvatarClass = m_chAvatarClass;

	pHeader->chProfLargeSword = MAKETRIBBLE(m_nProfLgSword,m_nProfLgSword2);
	pHeader->chProfSmallSword = MAKETRIBBLE(m_nProfSmSword,m_nProfSmSword2);
	pHeader->chProfBow = MAKETRIBBLE(m_nProfBow,m_nProfBow2);
	pHeader->chProfSpear = MAKETRIBBLE(m_nProfSpear,m_nProfSpear2);
	pHeader->chProfBlunt = MAKETRIBBLE(m_nProfBlunt,m_nProfBlunt2);
	pHeader->chProfSpiked = MAKETRIBBLE(m_nProfSpiked,m_nProfSpiked2);
	pHeader->chProfAxe = MAKETRIBBLE(m_nProfAxe,m_nProfAxe2);
	pHeader->chProfMissile = MAKETRIBBLE(m_nProfMissile,m_nProfMissile2);

	pHeader->chSex = m_chSex;
	pHeader->chAlignment = m_chAlignment;
	pHeader->chClass = m_chClass;
	pHeader->nMageSpecialty = m_nMageSpecialty;
	pHeader->chRace = m_chRace;

	pHeader->chAC = m_chAC;
	pHeader->chThac0 = m_chThac0;
	pHeader->chNumberOfAttacks = m_chNumberOfAttacks;
	pHeader->chRacialEnemy = m_chRacialEnemy;
	pHeader->chMagicResist = m_chMagicResist;
	pHeader->chLore = m_chLore;

	pHeader->chSavePPD = m_chSavePPD;
	pHeader->chSaveRSW = m_chSaveRSW;
	pHeader->chSavePP = m_chSavePP;
	pHeader->chSaveBW = m_chSaveBW;
	pHeader->chSaveS = m_chSaveS;

	pHeader->chLevel[0] = m_chLevel[0];
	pHeader->chLevel[1] = m_chLevel[1];
	pHeader->chLevel[2] = m_chLevel[2];

	pHeader->nMaxHp = m_nMaxHp;
	pHeader->nCurrentHp = m_nMaxHp;

	pHeader->chFindTraps = m_chFindTraps;
	pHeader->chOpenLocks = m_chOpenLocks;
	pHeader->chStealth = m_chStealth;
	pHeader->chPickPockets = m_chPickPockets;

	if (GetDocument()->IsExported())
		pHeader->nGold = m_nGold;
	else
		GetDocument()->m_pFileHeader->nGold = m_nGold;

	if (!GetDocument()->IsExported())
	{
		// See if the party needs to be relocated.
		// Line them up in 2 rows of 3.
		// 1 2 3
		// 4 5 6
		if (m_strArea != pInfo->szArea || m_nMapX != pInfo->nPlayerX || m_nMapY != pInfo->nPlayerY)
		{
			NPC_INFO *pInfoTemp;
			for (int i=0;i<m_nNumChars;i++)
			{
				pInfoTemp = GetNpcInfo(i);
				if (!pInfoTemp)
					continue;
				strcpy(pInfoTemp->szArea,m_strArea);
				pInfoTemp->nPlayerX = m_nMapX + ((i % 3) * 40);
				pInfoTemp->nPlayerY = m_nMapY + ((i / 3) * 40);
				pInfoTemp->nViewX = m_nMapX - QUADX / 4;
				pInfoTemp->nViewY = m_nMapY - QUADY / 4;
			}
		}
	}
}

void CBGEditView::MarkButton(CButton *pBtn, BOOL bMark)
{
	CString strText;

	pBtn->GetWindowText(strText);

	if (bMark)
		pBtn->SetWindowText(CString("[")+strText+"]");
	else
		if (strText.Left(1) == "[")
			pBtn->SetWindowText(strText.Mid(1,strText.GetLength()-2));
}

void CBGEditView::SetCurrentChar(int nNumber)
{
	MarkButton(&m_btnChar1,FALSE);
	MarkButton(&m_btnChar2,FALSE);
	MarkButton(&m_btnChar3,FALSE);
	MarkButton(&m_btnChar4,FALSE);
	MarkButton(&m_btnChar5,FALSE);
	MarkButton(&m_btnChar6,FALSE);

	CButton *pBtn;
	switch(nNumber)
	{
		case 0 :
			pBtn = &m_btnChar1;
			break;
		case 1 :
			pBtn = &m_btnChar2;
			break;
		case 2 :
			pBtn = &m_btnChar3;
			break;
		case 3 :
			pBtn = &m_btnChar4;
			break;
		case 4 :
			pBtn = &m_btnChar5;
			break;
		case 5 :
			pBtn = &m_btnChar6;
			break;
		default :
			pBtn = NULL;
			break;
	}

	if (pBtn)
		MarkButton(pBtn,TRUE);

	m_nCurrentChar = nNumber;
}

void CBGEditView::OnChar1() 
{
	if (!m_nNumChars)
		return;
	if (!GetNpcHeader(0))
		return;
	PutValues(m_nCurrentChar);
	SetCurrentChar(0);
	FetchValues(m_nCurrentChar);

	if (!IsNpc(0) && GetKeyState(VK_SHIFT) & 0x80000000)
	{
		CChangeNameDlg d;

		GetCharName(0,d.m_strName);
		if (d.DoModal() == IDOK)
		{
			SetCharName(0,d.m_strName);
			m_btnChar1.SetWindowText(d.m_strName);
			MarkButton(&m_btnChar1,TRUE);
		}
	}
}

void CBGEditView::OnChar2() 
{
	if (m_nNumChars < 2)
		return;
	if (!GetNpcHeader(1))
		return;
	PutValues(m_nCurrentChar);
	SetCurrentChar(1);
	FetchValues(m_nCurrentChar);

	if (!IsNpc(1) && GetKeyState(VK_SHIFT) & 0x80000000)
	{
		CChangeNameDlg d;

		GetCharName(1,d.m_strName);
		if (d.DoModal() == IDOK)
		{
			SetCharName(1,d.m_strName);
			m_btnChar2.SetWindowText(d.m_strName);
			MarkButton(&m_btnChar2,TRUE);
		}
	}
}

void CBGEditView::OnChar3() 
{
	if (m_nNumChars < 3)
		return;
	if (!GetNpcHeader(2))
		return;
	PutValues(m_nCurrentChar);
	SetCurrentChar(2);
	FetchValues(m_nCurrentChar);

	if (!IsNpc(2) && GetKeyState(VK_SHIFT) & 0x80000000)
	{
		CChangeNameDlg d;

		GetCharName(2,d.m_strName);
		if (d.DoModal() == IDOK)
		{
			SetCharName(2,d.m_strName);
			m_btnChar3.SetWindowText(d.m_strName);
			MarkButton(&m_btnChar3,TRUE);
		}
	}
}

void CBGEditView::OnChar4() 
{
	if (m_nNumChars < 4)
		return;
	if (!GetNpcHeader(3))
		return;
	PutValues(m_nCurrentChar);
	SetCurrentChar(3);
	FetchValues(m_nCurrentChar);

	if (!IsNpc(3) && GetKeyState(VK_SHIFT) & 0x80000000)
	{
		CChangeNameDlg d;

		GetCharName(3,d.m_strName);
		if (d.DoModal() == IDOK)
		{
			SetCharName(3,d.m_strName);
			m_btnChar4.SetWindowText(d.m_strName);
			MarkButton(&m_btnChar4,TRUE);
		}
	}
}

void CBGEditView::OnChar5() 
{
	if (m_nNumChars < 5)
		return;
	if (!GetNpcHeader(4))
		return;
	PutValues(m_nCurrentChar);
	SetCurrentChar(4);
	FetchValues(m_nCurrentChar);

	if (!IsNpc(4) && GetKeyState(VK_SHIFT) & 0x80000000)
	{
		CChangeNameDlg d;

		GetCharName(4,d.m_strName);
		if (d.DoModal() == IDOK)
		{
			SetCharName(4,d.m_strName);
			m_btnChar5.SetWindowText(d.m_strName);
			MarkButton(&m_btnChar5,TRUE);
		}
	}
}

void CBGEditView::OnChar6() 
{
	if (m_nNumChars < 6)
		return;
	if (!GetNpcHeader(5))
		return;
	PutValues(m_nCurrentChar);
	SetCurrentChar(5);
	FetchValues(m_nCurrentChar);

	if (!IsNpc(5) && GetKeyState(VK_SHIFT) & 0x80000000)
	{
		CChangeNameDlg d;

		GetCharName(5,d.m_strName);
		if (d.DoModal() == IDOK)
		{
			SetCharName(5,d.m_strName);
			m_btnChar6.SetWindowText(d.m_strName);
			MarkButton(&m_btnChar6,TRUE);
		}
	}
}

// Sets the quantities of all items that can have quantities to 65535.
void CBGEditView::OnMaxQty() 
{
	if (!m_nNumChars)
		return;
	for (int i=0;i<NUM_ITEM_SLOTS;i++)
		if (strcmp(m_inv[i].szCode,""))
			if (m_inv[i].bStackable)
			{
				switch(m_inv[i].nItemType)
				{
					case TYPE_POTION :
						m_inv[i].nQuantity = (short)MAX_QTY_POTION;
						break;
					default :
						m_inv[i].nQuantity = (short)MAX_QTY;
						break;
				}
				PutInList(i);
			}
}

UINT CBGEditView::GetItemCount()
{
	UINT nCount = 0;
	for (int i=0;i<NUM_ITEM_SLOTS;i++)
		if (strcmp(m_inv[i].szCode,""))
			nCount++;
	return(nCount);
}

void CBGEditView::CreateItemSlots(NPC_ITEMSLOTS *pSlots)
{
	UINT nOrdinal = 0;

	for (int i=0;i<NUM_ITEM_SLOTS;i++)
		if (strcmp(m_inv[i].szCode,""))
		{
			pSlots->nItemSlot[i] = nOrdinal;
			nOrdinal++;
		}
		else
			pSlots->nItemSlot[i] = (short)0xFFFF;

	// Not sure what this is for. The following values are found
	// frequently so taking a guess and just setting it to this.
	pSlots->junk[0] = '\xE8';
	pSlots->junk[1] = '\x03';
	pSlots->junk[2] = '\x00';
	pSlots->junk[3] = '\x00';
}

BOOL CBGEditView::CreateItems(ITEM *pItem)
{
	UINT nOrdinal = 0;

	for (int i=0;i<NUM_ITEM_SLOTS;i++)
	{
		if (strcmp(m_inv[i].szCode,""))
		{
			memset(pItem+nOrdinal,0,sizeof(ITEM));
			(pItem+nOrdinal)->nCount = m_inv[i].nQuantity;
			(pItem+nOrdinal)->nIdentified = (m_inv[i].bIndentified ? 1 : 0);
			sprintf((pItem+nOrdinal)->szItem,"%s%s",m_inv[i].szCode,m_inv[i].szNumber);
			nOrdinal++;
		}
	}
	return(TRUE);
}

UINT CBGEditView::GetSpellCount(BOOL bKnown)
{
	UINT nCount = 0;
	for (int i=0;i<MAX_SPELLS;i++)
	{
		if (m_spells[i].nSpellDesc != -1)
		{
			if (bKnown)
				nCount++;
			else
			{
				// Need to save out all innates regardless of whether they have it
				// set to be memorized.
				if (m_spells[i].nType == ST_INNATE && !m_spells[i].nMemorized)
					nCount++;
				else
					nCount += m_spells[i].nMemorized;
			}
		}
	}
	return(nCount);
}

BOOL CBGEditView::CreateMemorizedInfo(NPC_MEMORIZEDINFO *pMemInfo)
{
	short nMemorized;
	int nSpellLevel;
	int j;
	for (int i=0;i<m_nMemorizedInfo;i++)
	{
		nMemorized = 0;
		for (j=0;j<MAX_SPELLS;j++)
		{
			if (m_spells[j].nSpellDesc != -1 && m_memorizedInfo[i].nSpellType == m_spells[j].nType)
			{
				nSpellLevel = m_spells[j].szGameCode[4]-'0'-1;
				// For protection from petrification which is labeled wrong.
				if (!strcmp(m_spells[j].szGameCode,"SPWI108"))
					nSpellLevel = 1;
				if (m_memorizedInfo[i].nSpellLevel == nSpellLevel)
				{
					if (m_spells[j].nType == ST_INNATE)
					{
						if (m_spells[j].nMemorized)
							nMemorized += m_spells[j].nMemorized;
						else
							nMemorized++;
					}
					else
						nMemorized += m_spells[j].nMemorized;
				}
			}
		}
		m_memorizedInfo[i].nNumMemorized = nMemorized;
		if (m_memorizedInfo[i].nSpellType == ST_INNATE)
		{
			// I don't know if this is necessary. Looks like in the data file for
			// innates the CANs are the same as the number memorized.
			m_memorizedInfo[i].nCanMemorize1 = nMemorized;
			m_memorizedInfo[i].nCanMemorize2 = nMemorized;
		}
	}

	for (i=0;i<m_nMemorizedInfo;i++)
		memcpy(pMemInfo+i,&m_memorizedInfo[i],sizeof(NPC_MEMORIZEDINFO));
	return(TRUE);
}

int CBGEditView::CreateSpells(SPELL *pSpell, BOOL bKnown)
{
	UINT nSpellCount = 0;
	int nRepeat;
	int j;
	for (int i=0;i<MAX_SPELLS;i++)
	{
		if (m_spells[i].nSpellDesc == -1)
			continue;

		if (bKnown)
			nRepeat = 1;
		else
		{
			if (m_spells[i].nType == ST_INNATE)
			{
				if (!m_spells[i].nMemorized)
					nRepeat = 1;
				else
					nRepeat = m_spells[i].nMemorized;
			}
			else
				nRepeat = m_spells[i].nMemorized;
		}

		for (j=0;j<nRepeat;j++)
		{
			strcpy((pSpell+nSpellCount)->szSpell,m_spells[i].szGameCode);

			if (bKnown)
			{
				// I think this is supposed to be spell level-1 when in the KNOWN
				// section.
				// Prot from Petrification is apparently a level 2 spell by uses a level
				// one string making an exception here.
				if (!strcmp(m_spells[i].szGameCode,"SPWI108"))
					(pSpell+nSpellCount)->nValue1 = 1;
				else
					(pSpell+nSpellCount)->nValue1 = (pSpell+nSpellCount)->szSpell[4]-'0'-1;
				switch(m_spells[i].nType)
				{
					case ST_INNATE :
						(pSpell+nSpellCount)->nValue2 = 2;
						break;
					case ST_PRIEST :
						(pSpell+nSpellCount)->nValue2 = 0;
						break;
					case ST_WIZARD :
						(pSpell+nSpellCount)->nValue2 = 1;
						break;
					default:
						MessageBox("Unknown spell type. Unable to save.","Warning",MB_ICONWARNING);
						return(-1);
				}
			}
			else
			{
				// In Memorized section nAbailable=1 means the spell has not yet been
				// cast by the player.
				(pSpell+nSpellCount)->nValue1 = 1;

				// This sometimes has values and sometimes doesn't. I'm going to set it
				// to 0 for kicks (and it would be a pain to store) and hope nothing
				// goofs up. I did this by hand as a test and I don't see any effect on
				// the game.
				(pSpell+nSpellCount)->nValue2 = 0;
			}
			nSpellCount++;
		}
	}
	return(nSpellCount);
}

void CBGEditView::OnDeleteitem() 
{
	if (!m_nNumChars)
		return;
	int nIndex = m_lcInventory.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
		return;

	ClearItem(nIndex);
}

void CBGEditView::OnEdititem() 
{
	if (!m_nNumChars)
		return;
	int nIndex = m_lcInventory.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
		return;

	CItemsDlg d;
	d.SelectNone();		// The majority will be specific.
	switch(nIndex)
	{
		case 0 : // Helm
			d.m_bHelms = TRUE;
			break;
		case 1 :	// Armor
			d.m_bArmor = TRUE;
			break;
		case 2 : // Shield
			d.m_bShields = TRUE;
			break;
		case 3 : // Gauntlets
			d.m_bGauntlets = TRUE;
			break;
		case 4 : // Rings
		case 5 :
			d.m_bRings = TRUE;
			break;
		case 6 : // Amulet
			d.m_bAmulets = TRUE;
			break;
		case 7 : // Belts
			d.m_bBelts = TRUE;
			break;
		case 8 :	// Boots
			d.m_bBoots = TRUE;
			break;
		case 9 : // Weapons
		case 10 :
		case 11 :
		case 12 :
			d.m_bWeapons = TRUE;
			break;
		case 13 : // Quiver
		case 14 :
		case 15 :
			d.m_bMissiles = TRUE;
			break;
		case 16 : // No idea what this slot is for.
			return;
		case 17 :
			d.m_bCloaks = TRUE;
			break;
		case 18 : // Quick Slots
		case 19 :
		case 20 :
			d.m_bScrolls = TRUE;
			d.m_bWands = TRUE;
			d.m_bPotions = TRUE;
			break;

	}
	if (nIndex >= 21 && nIndex <= 37)
		d.SelectAll();

	// If there is an item in the slot, select it.
	if (strcmp(m_inv[nIndex].szCode,""))
	{
		int nTemp = 0;
		while(_items[nTemp].nItemType != TYPE_ENDOFLIST)
		{
			if (!strcmp(m_inv[nIndex].szCode,_items[nTemp].szCode) && !strcmp(m_inv[nIndex].szNumber,_items[nTemp].szNumber))
			{
				d.m_nSelectedItem = nTemp;
				d.m_nQty = (unsigned short)m_inv[nIndex].nQuantity;
				break;
			}
			nTemp++;
		}
	}

	if (d.DoModal() == IDOK && d.m_nSelectedItem != -1)
	{
		m_inv[nIndex].bIndentified = TRUE;
		m_inv[nIndex].bStackable = _items[d.m_nSelectedItem].bStackable;
		m_inv[nIndex].nItemType = _items[d.m_nSelectedItem].nItemType;
		m_inv[nIndex].nQuantity = d.m_nQty;
		strcpy(m_inv[nIndex].szCode,_items[d.m_nSelectedItem].szCode);
		strcpy(m_inv[nIndex].szDescription,_items[d.m_nSelectedItem].szDescription);
		strcpy(m_inv[nIndex].szNumber,_items[d.m_nSelectedItem].szNumber);
		PutInList(nIndex);
	}
}

void CBGEditView::OnDblclkInventory(NMHDR* pNMHDR, LRESULT* pResult) 
{
	OnEdititem();	
	*pResult = 0;
}

void CBGEditView::ClearAll()
{
	if (!m_lcInventory.GetSafeHwnd())
		return;

	m_btnChar1.SetWindowText("None");
	m_btnChar2.SetWindowText("None");
	m_btnChar3.SetWindowText("None");
	m_btnChar4.SetWindowText("None");
	m_btnChar5.SetWindowText("None");
	m_btnChar6.SetWindowText("None");

	ClearInventory();

	m_sbtnStr.SetRange(3,25);
	m_sbtnStr.SetPos(18);
	m_sbtnStrBonus.SetRange(0,100);
	m_sbtnStrBonus.SetPos(100);
	m_sbtnDex.SetRange(3,25);
	m_sbtnDex.SetPos(18);
	m_sbtnCon.SetRange(3,25);
	m_sbtnCon.SetPos(18);
	m_sbtnInt.SetRange(3,25);
	m_sbtnInt.SetPos(18);
	m_sbtnWis.SetRange(3,25);
	m_sbtnWis.SetPos(18);
	m_sbtnCha.SetRange(3,25);
	m_sbtnCha.SetPos(18);

	m_nGold = 0;
	m_nExp = 0;
	m_nNumChars = 0;
	UpdateData(FALSE);

	EnableControls();
}

void CBGEditView::OnEditProficiencies() 
{
	if (!m_nNumChars)
		return;
	CProficienciesDlg d;

	d.m_nProfLgSword = m_nProfLgSword;
	d.m_nProfSmSword = m_nProfSmSword;
	d.m_nProfBow = m_nProfBow;
	d.m_nProfSpear = m_nProfSpear;
	d.m_nProfBlunt = m_nProfBlunt;
	d.m_nProfSpiked = m_nProfSpiked;
	d.m_nProfAxe = m_nProfAxe;
	d.m_nProfMissile = m_nProfMissile;
	if (d.DoModal() == IDOK)
	{
		m_nProfLgSword = d.m_nProfLgSword;
		m_nProfSmSword = d.m_nProfSmSword;
		m_nProfBow = d.m_nProfBow;
		m_nProfSpear = d.m_nProfSpear;
		m_nProfBlunt = d.m_nProfBlunt;
		m_nProfSpiked = d.m_nProfSpiked;
		m_nProfAxe = d.m_nProfAxe;
		m_nProfMissile = d.m_nProfMissile;
	}
}

void CBGEditView::OnEditMagic() 
{
	if (!m_nNumChars)
		return;
	int i;
	CMagicDlg d;
	
	d.m_nMemorizedInfo = m_nMemorizedInfo;
	for (i=0;i<m_nMemorizedInfo;i++)
		memcpy(&d.m_memorizedInfo[i],&m_memorizedInfo[i],sizeof(NPC_MEMORIZEDINFO));
	for (i=0;i<MAX_SPELLS;i++)
		memcpy(&d.m_spells[i],&m_spells[i],sizeof(CHARSPELL));
	if (d.DoModal() == IDOK)
	{
		for (i=0;i<m_nMemorizedInfo;i++)
			memcpy(&m_memorizedInfo[i],&d.m_memorizedInfo[i],sizeof(NPC_MEMORIZEDINFO));
		for (i=0;i<MAX_SPELLS;i++)
			memcpy(&m_spells[i],&d.m_spells[i],sizeof(CHARSPELL));
	}
}

void CBGEditView::OnEditCharacteristics() 
{
	if (!m_nNumChars)
		return;

	CCharacteristicsDlg d;
	d.m_chSex = m_chSex;
	d.m_chClass = m_chClass;
	d.m_nMageSpecialty = m_nMageSpecialty;
	d.m_chRace = m_chRace;
	d.m_chAlignment = m_chAlignment;
	if (d.DoModal() == IDOK)
	{
		m_chSex = d.m_chSex;
		m_chRace = d.m_chRace;
		m_chAlignment = d.m_chAlignment;
		m_chClass = d.m_chClass;
		m_nMageSpecialty = d.m_nMageSpecialty;
	}
}

void CBGEditView::OnEditSaves() 
{
	if (!m_nNumChars)
		return;

	CSavingThrowDlg d;
	d.m_nSavePPD = m_chSavePPD;
	d.m_nSaveRSW = m_chSaveRSW;
	d.m_nSavePP = m_chSavePP;
	d.m_nSaveBW = m_chSaveBW;
	d.m_nSaveS = m_chSaveS;
	if (d.DoModal() == IDOK)
	{
		m_chSavePPD = d.m_nSavePPD;
		m_chSaveRSW = d.m_nSaveRSW;
		m_chSavePP = d.m_nSavePP;
		m_chSaveBW = d.m_nSaveBW;
		m_chSaveS = d.m_nSaveS;
	}
}

void CBGEditView::OnEditDual() 
{
	if (!m_nNumChars)
		return;

	CDualClassDlg d;
	d.m_nLevel = m_chLevel[0];
	d.m_nProfLgSword = m_nProfLgSword2;
	d.m_nProfSmSword = m_nProfSmSword2;
	d.m_nProfBow = m_nProfBow2;
	d.m_nProfSpear = m_nProfSpear2;
	d.m_nProfBlunt = m_nProfBlunt2;
	d.m_nProfSpiked = m_nProfSpiked2;
	d.m_nProfAxe = m_nProfAxe2;
	d.m_nProfMissile = m_nProfMissile2;
	if (d.DoModal() == IDOK)
	{
		m_chLevel[0] = d.m_nLevel;
		m_nProfLgSword2 = d.m_nProfLgSword;
		m_nProfSmSword2 = d.m_nProfSmSword;
		m_nProfBow2 = d.m_nProfBow;
		m_nProfSpear2 = d.m_nProfSpear;
		m_nProfBlunt2 = d.m_nProfBlunt;
		m_nProfSpiked2 = d.m_nProfSpiked;
		m_nProfAxe2 = d.m_nProfAxe;
		m_nProfMissile2 = d.m_nProfMissile;
	}
}

void CBGEditView::OnEditThief() 
{
	if (!m_nNumChars)
		return;

	CThiefSkillsDlg d;

	d.m_nRace = (int)m_chRace;
	d.m_nDex = m_nDex;
	d.m_nPickPockets = (UINT)m_chPickPockets;
	d.m_nOpenLocks = (UINT)m_chOpenLocks;
	d.m_nDetectTraps = (UINT)m_chFindTraps;
	d.m_nStealth = (UINT)m_chStealth;
	if (d.DoModal() == IDOK)
	{
		m_chPickPockets = (unsigned char)d.m_nPickPockets;
		m_chOpenLocks = (unsigned char)d.m_nOpenLocks;
		m_chFindTraps = (unsigned char)d.m_nDetectTraps;
		m_chStealth = (unsigned char)d.m_nStealth;
	}
}

void CBGEditView::OnEditLocation() 
{
	if (!m_nNumChars)
		return;

	CLocationDlg d;

	d.m_strArea = m_strArea;
	d.m_nMapX = m_nMapX;
	d.m_nMapY = m_nMapY;
	if (d.DoModal() == IDOK)
	{
		m_strArea = d.m_strArea;
		m_nMapX = d.m_nMapX;
		m_nMapY = d.m_nMapY;
	}
}

void CBGEditView::EnableControls()
{
	BOOL bHandled;
	CWnd *pWnd = GetWindow(GW_CHILD);
	while(pWnd)
	{
		bHandled = TRUE;
		switch(pWnd->GetDlgCtrlID())
		{
			case IDC_CHAR1 :
				pWnd->EnableWindow(m_nNumChars >= 1);
				break;
			case IDC_CHAR2 :
				pWnd->EnableWindow(m_nNumChars >= 2);
				break;
			case IDC_CHAR3 :
				pWnd->EnableWindow(m_nNumChars >= 3);
				break;
			case IDC_CHAR4 :
				pWnd->EnableWindow(m_nNumChars >= 4);
				break;
			case IDC_CHAR5 :
				pWnd->EnableWindow(m_nNumChars >= 5);
				break;
			case IDC_CHAR6 :
				pWnd->EnableWindow(m_nNumChars >= 6);
				break;
			case IDC_EDIT_LOCATION :
				if (m_nNumChars)
					pWnd->EnableWindow(GetDocument()->IsExported() == FALSE);
				else
					pWnd->EnableWindow(FALSE);
				break;
			default :
				bHandled = FALSE;
				break;
		}

		if (!bHandled)
			pWnd->EnableWindow(m_nNumChars != 0);

		pWnd = pWnd->GetNextWindow();
	}
}

void CBGEditView::OnEditAppearance() 
{
	CAppearanceDlg d;

	d.m_chAvatar = m_chAvatar;
	d.m_chAvatarClass = m_chAvatarClass;
	if (d.DoModal() == IDOK)
	{
		m_chAvatar = d.m_chAvatar;
		m_chAvatarClass = d.m_chAvatarClass;
	}
}

void CBGEditView::OnEditMiscAbilities() 
{
	CMiscAbilitiesDlg d;
	
	d.m_chClass = m_chClass;
	d.m_chRacialEnemy = m_chRacialEnemy;
	d.m_nThac0 = m_chThac0;
	d.m_chNumberOfAttacks = m_chNumberOfAttacks;
	d.m_nAc = m_chAC;
	d.m_nMagicResistance = m_chMagicResist;
	if (d.DoModal() == IDOK)
	{
		m_chClass = d.m_chClass;
		m_chRacialEnemy = d.m_chRacialEnemy;
		m_chThac0 = (unsigned char)d.m_nThac0;
		m_chNumberOfAttacks = d.m_chNumberOfAttacks;
		m_chAC = (unsigned char)d.m_nAc;
		m_chMagicResist = (unsigned char)d.m_nMagicResistance;
	}
}

void CBGEditView::GetCharName(int nNumber, CString &strName)
{
	if (nNumber < 0 || nNumber >= m_nNumChars)
		return;

	if (GetDocument()->IsExported())
		strName = GetDocument()->m_pChrHeader->szName;
	else
	{
		NPC_INFO *pInfo;
		pInfo = (NPC_INFO*)(GetDocument()->m_pData+GetDocument()->m_pFileHeader->nPartyOffset+sizeof(NPC_INFO)*nNumber);
		if (!strcmp(pInfo->szName,""))
			strName = GetNpcHeader(nNumber)->szName;
		else
			strName = pInfo->szName;
	}
	return;
}

void CBGEditView::SetCharName(int nNumber, CString &strName)
{
	if (nNumber < 0 || nNumber >= m_nNumChars)
		return;

	if (strName.GetLength() > 20)
		strName = strName.Left(20);

	if (GetDocument()->IsExported())
		strcpy(GetDocument()->m_pChrHeader->szName,strName);
	else
	{
		NPC_INFO *pInfo;
		pInfo = (NPC_INFO*)(GetDocument()->m_pData+GetDocument()->m_pFileHeader->nPartyOffset+sizeof(NPC_INFO)*nNumber);
		if (!strcmp(pInfo->szName,""))
			strcpy(GetNpcHeader(nNumber)->szName,strName);
		else
			strcpy(pInfo->szName,strName);
	}
	return;
}

BOOL CBGEditView::IsNpc(int nNumber)
{
	if (GetDocument()->IsExported())
		return(FALSE);
	NPC_INFO *pInfo;
	pInfo = (NPC_INFO*)(GetDocument()->m_pData+GetDocument()->m_pFileHeader->nPartyOffset+sizeof(NPC_INFO)*nNumber);
	if (!strcmp(pInfo->szName,""))
		return(TRUE);
	return(FALSE);
}

void CBGEditView::OnHelpViewreadmetxt() 
{
	ShellExecute(NULL,"open","notepad.exe","ReadMe.txt",NULL,SW_SHOWNORMAL);
}
