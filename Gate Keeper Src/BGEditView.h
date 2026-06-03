// BGEditView.h : interface of the CBGEditView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BGEDITVIEW_H__DC8AAB0D_A406_11D2_9611_8C5D1421B743__INCLUDED_)
#define AFX_BGEDITVIEW_H__DC8AAB0D_A406_11D2_9611_8C5D1421B743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBGEditView : public CFormView
{
protected: // create from serialization only
	CBGEditView();
	DECLARE_DYNCREATE(CBGEditView)

public:
	//{{AFX_DATA(CBGEditView)
	enum { IDD = IDD_BGEDIT_FORM };
	CEdit	m_edStr;
	CButton	m_btnThief;
	CButton	m_btnSaves;
	CButton	m_btnProficiencies;
	CButton	m_btnMagic;
	CButton	m_btnLocation;
	CButton	m_btnDualOnly;
	CListCtrl	m_lcInventory;
	CSpinButtonCtrl	m_sbtnWis;
	CSpinButtonCtrl	m_sbtnInt;
	CSpinButtonCtrl	m_sbtnCon;
	CSpinButtonCtrl	m_sbtnCha;
	CSpinButtonCtrl	m_sbtnDex;
	CSpinButtonCtrl	m_sbtnStrBonus;
	CSpinButtonCtrl	m_sbtnStr;
	CButton	m_btnChar6;
	CButton	m_btnChar5;
	CButton	m_btnChar4;
	CButton	m_btnChar3;
	CButton	m_btnChar2;
	CButton	m_btnChar1;
	UINT	m_nStr;
	UINT	m_nStrBonus;
	UINT	m_nDex;
	UINT	m_nCha;
	UINT	m_nCon;
	UINT	m_nInt;
	UINT	m_nWis;
	UINT	m_nExp;
	UINT	m_nGold;
	UINT	m_nMaxHp;
	//}}AFX_DATA

	// Current class and multiclass.
	UINT m_nProfLgSword;
	UINT m_nProfSmSword;
	UINT m_nProfBow;
	UINT m_nProfSpear;
	UINT m_nProfBlunt;
	UINT m_nProfSpiked;
	UINT m_nProfAxe;
	UINT m_nProfMissile;

	// These determine the location of the party. This is stored in the 
	// INFO record, not with the rest of the character's data. The whole
	// party gets moved if any character is moved.
	CString m_strArea;
	unsigned short m_nMapX;
	unsigned short m_nMapY;

	// Used for the first class of a dual class character only.
	// These two sets of proficiencies are split and combined in the
	// fetch and put.
	UINT m_nProfLgSword2;
	UINT m_nProfSmSword2;
	UINT m_nProfBow2;
	UINT m_nProfSpear2;
	UINT m_nProfBlunt2;
	UINT m_nProfSpiked2;
	UINT m_nProfAxe2;
	UINT m_nProfMissile2;

	unsigned char m_chAvatar;
	unsigned char m_chAvatarClass;

	unsigned char m_chSex;
	unsigned char m_chAlignment;
	unsigned char m_chClass;
	short			  m_nMageSpecialty;	
	unsigned char m_chRace;

	char m_chAC;

	unsigned char m_chThac0;
	unsigned char m_chNumberOfAttacks;
	unsigned char m_chMagicResist;
	unsigned char m_chLore;
	unsigned char m_chRacialEnemy;

	unsigned char m_chSavePPD;
	unsigned char m_chSaveRSW;
	unsigned char m_chSavePP;
	unsigned char m_chSaveBW;
	unsigned char m_chSaveS;

	unsigned char m_chOpenLocks;
	unsigned char m_chStealth;
	unsigned char m_chFindTraps;
	unsigned char m_chPickPockets;

	// Levels for each of the 3 classes.
	unsigned char m_chLevel[3];

	// The number of characters in this file. Fetched from the document
	// in FileLoaded().
	int m_nNumChars;

	int m_nCurrentChar;
	KNOWNITEM m_inv[NUM_ITEM_SLOTS];

	CHARSPELL m_spells[MAX_SPELLS];

	NPC_MEMORIZEDINFO m_memorizedInfo[MAX_MEMORIZEDINFO];
	// Number of above blocks being stored.
	int m_nMemorizedInfo;

	void FileLoaded();

	// Pass in 0 based index. Returns a pointer to the NPC header.
	NPC_HEADER* GetNpcHeader(int nIndex);
	NPC_INFO* GetNpcInfo(int nIndex);

	// Returns a pointer to the item slot data.
	NPC_ITEMSLOTS* GetNpcItemSlots(NPC_HEADER *pHeader);

	// Gets the values outta the buffer.
	void FetchValues(int nIndex);

	// Gets the EQ list outta the currently selected character.
	void FetchItems(int nIndex);

	//  Adds the spell to the list of known spells.
	BOOL AddKnownSpell(SPELL *pSpell, int nIndex);

	// Gets the list of known and memorized spells out of the character.
	BOOL FetchSpells(int nIndex);

	// Sticks data back into the buffer.
	void PutValues(int nIndex);

	// Clears out the invenotry list and adds the basics.
	void ClearInventory();

	// Clears out both the known and memorized lists.
	void ClearSpells();

	// Fills in the info in the list control for that position.
	void PutInList(int nPos);

	// Takes a pointer to an item raw from the save game file and 
	// converts it to a more workable form.
	void ConvertBufferItem(int nPos, ITEM* pItem);

	// Returns the number of items that will be written out (ones in the list).
	UINT GetItemCount();

	// Returns the number of known or memorized spells.
	UINT GetSpellCount(BOOL bKnown);

	// Pass in a pointer to an NPC_ITEMSLOT, it fills in the values from the
	// m_inv data.
	void CreateItemSlots(NPC_ITEMSLOTS *pSlots);

	// Given a pointer to the first items, creates consecutive items until all
	// the items in m_inv have been written. Returns TRUE if it worked.
	BOOL CreateItems(ITEM *pItem);

	// Given a pointer of where to write the first spell, creates consecutive
	// spells until all the spells are written. bKnown is TRUE to write out the
	// KNOWN spells list, FALSE and it creates the MEMORIZED spell list. They
	// get their data from the same place (m_spells) but they are written
	// a little differently. Returns the number of spells written.
	int CreateSpells(SPELL *pSpell, BOOL bKnown);

	// Creates the table of memorized info blocks.
	BOOL CreateMemorizedInfo(NPC_MEMORIZEDINFO *pMemInfo);

	// Clears the m_inv item. Update the list control if bUpdateList is TRUE.
	void ClearItem(int nPos, BOOL bUpdateList=TRUE);

	// Clears out the form so you cannot edit it.
	void ClearAll();

	// Goes through all the controls and enables or disables them depending on
	// the state of the data.
	void EnableControls();

	// Does the actual indicating or removal of inidication for a button about
	// the character's selection state.
	void MarkButton(CButton *pBtn, BOOL bMark);

	// Takes care of the indication on the buttons for which character is the
	// active character.
	void SetCurrentChar(int nNumber);

	void GetCharName(int nNumber, CString &strName);
	void SetCharName(int nNumber, CString &strName);

	// Returns TRUE if the character is an NPC.
	BOOL IsNpc(int nNumber);

// Attributes
public:
	CBGEditDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBGEditView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBGEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBGEditView)
	afx_msg void OnChar1();
	afx_msg void OnChar2();
	afx_msg void OnChar3();
	afx_msg void OnChar4();
	afx_msg void OnChar5();
	afx_msg void OnChar6();
	afx_msg void OnMaxQty();
	afx_msg void OnDeleteitem();
	afx_msg void OnEdititem();
	afx_msg void OnDblclkInventory(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditProficiencies();
	afx_msg void OnEditMagic();
	afx_msg void OnEditCharacteristics();
	afx_msg void OnEditSaves();
	afx_msg void OnEditDual();
	afx_msg void OnEditThief();
	afx_msg void OnEditLocation();
	afx_msg void OnEditAppearance();
	afx_msg void OnEditMiscAbilities();
	afx_msg void OnHelpViewreadmetxt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BGEditView.cpp
inline CBGEditDoc* CBGEditView::GetDocument()
   { return (CBGEditDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BGEDITVIEW_H__DC8AAB0D_A406_11D2_9611_8C5D1421B743__INCLUDED_)
