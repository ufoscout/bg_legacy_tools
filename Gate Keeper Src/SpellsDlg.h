#if !defined(AFX_SPELLSDLG_H__60404902_A8AD_11D2_9611_444553540000__INCLUDED_)
#define AFX_SPELLSDLG_H__60404902_A8AD_11D2_9611_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpellsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpellsDlg dialog

class CSpellsDlg : public CDialog
{
// Construction
public:
	CSpellsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpellsDlg)
	enum { IDD = IDD_SPELLS };
	CEdit	m_edMemorized;
	CEdit	m_edCurrentSpell;
	CButton	m_btnWizard;
	CButton	m_btnPriest;
	CButton	m_btnInnate;
	CListCtrl	m_lcSpells;
	BOOL	m_bInnate;
	BOOL	m_bPriest;
	BOOL	m_bWizard;
	UINT	m_nMemorized;
	//}}AFX_DATA

	void DoClick();
	void FillList();

	// Set it to something to have the dialog auto-pick from the list.
	// When OK is pushed, this is the entry that was chosen.
	int m_nSelectedSpell;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpellsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpellsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSepllInnate();
	afx_msg void OnSpellPriest();
	afx_msg void OnSpellWizard();
	afx_msg void OnClickSpells(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkSpells(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPELLSDLG_H__60404902_A8AD_11D2_9611_444553540000__INCLUDED_)
