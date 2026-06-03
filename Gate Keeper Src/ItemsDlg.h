#if !defined(AFX_ITEMSDLG_H__280D3A81_A5CD_11D2_9611_F7321732EF05__INCLUDED_)
#define AFX_ITEMSDLG_H__280D3A81_A5CD_11D2_9611_F7321732EF05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ItemsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CItemsDlg dialog

class CItemsDlg : public CDialog
{
// Construction
public:
	CItemsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CItemsDlg)
	enum { IDD = IDD_ITEMS };
	CButton	m_btnMaxQty;
	CButton	m_edWeapons;
	CButton	m_edWands;
	CButton	m_edShields;
	CButton	m_edScrolls;
	CButton	m_edRings;
	CButton	m_edPotions;
	CButton	m_edMissiles;
	CButton	m_edMisc;
	CButton	m_edHelms;
	CButton	m_edGauntlets;
	CButton	m_edBoots;
	CButton	m_edCloaks;
	CButton	m_edBooks;
	CButton	m_edBelts;
	CButton	m_edArmor;
	CButton	m_edAmulets;
	CEdit	m_edQty;
	CEdit	m_edCurrentItem;
	CListCtrl	m_lcItems;
	BOOL	m_bAmulets;
	BOOL	m_bArmor;
	BOOL	m_bBelts;
	BOOL	m_bBooks;
	BOOL	m_bBoots;
	BOOL	m_bCloaks;
	BOOL	m_bGauntlets;
	BOOL	m_bHelms;
	BOOL	m_bMisc;
	BOOL	m_bMissiles;
	BOOL	m_bPotions;
	BOOL	m_bRings;
	BOOL	m_bScrolls;
	BOOL	m_bShields;
	BOOL	m_bWands;
	BOOL	m_bWeapons;
	UINT	m_nQty;
	//}}AFX_DATA

	// Defaults to -1. This is set when the dialog is exited with IDOK.
	// It can also be set by the caller to auto-load an item.
	int	m_nSelectedItem;

	void FillList();
	void DoClick();
	void SelectNone()							{ OnNone(); }
	void SelectAll()							{ OnAll(); }


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CItemsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CItemsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnViewAmulets();
	afx_msg void OnViewArmor();
	afx_msg void OnViewBelts();
	afx_msg void OnViewBooks();
	afx_msg void OnViewBoots();
	afx_msg void OnViewCloaks();
	afx_msg void OnViewGauntlets();
	afx_msg void OnViewHelms();
	afx_msg void OnViewMisc();
	afx_msg void OnViewMissiles();
	afx_msg void OnViewPotions();
	afx_msg void OnViewRings();
	afx_msg void OnViewScrolls();
	afx_msg void OnViewShields();
	afx_msg void OnViewWands();
	afx_msg void OnViewWeapons();
	afx_msg void OnAll();
	afx_msg void OnNone();
	afx_msg void OnClickItems(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnMaxQty();
	afx_msg void OnDblclkItems(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITEMSDLG_H__280D3A81_A5CD_11D2_9611_F7321732EF05__INCLUDED_)
