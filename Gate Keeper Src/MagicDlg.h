#if !defined(AFX_MAGICDLG_H__60404903_A8AD_11D2_9611_444553540000__INCLUDED_)
#define AFX_MAGICDLG_H__60404903_A8AD_11D2_9611_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MagicDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMagicDlg dialog

class CMagicDlg : public CDialog
{
// Construction
public:
	CMagicDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMagicDlg)
	enum { IDD = IDD_MAGIC };
	CComboBox	m_cbLevel;
	CComboBox	m_cbMagic;
	CButton	m_btnFromKnown;
	CButton	m_btnToKnown;
	CListCtrl	m_lcAvailable;
	CListCtrl	m_lcKnown;
	UINT	m_nCanMemorize;
	UINT	m_nMemorized;
	//}}AFX_DATA

	CBitmap m_bmpToKnown;
	CBitmap m_bmpFromKnown;

	// Needs to be filled in before dialog comes up.
	NPC_MEMORIZEDINFO m_memorizedInfo[MAX_MEMORIZEDINFO];
	// Needs to be set before dialog comes up.
	int m_nMemorizedInfo;

	// Needs to be filled in before dialog comes up.
	CHARSPELL m_spells[MAX_SPELLS];

	void FillLevels();
	void FillAvailable();
	void FillKnown();
	void FillData();

	void GetData();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMagicDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeMagicType();
	afx_msg void OnSelchangeMagicLevel();
	afx_msg void OnAddToKnown();
	afx_msg void OnRemoveFromKnown();
	afx_msg void OnChangeCanMemorize();
	afx_msg void OnDblclkKnown(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnDblclkAvailable(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetMem();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAGICDLG_H__60404903_A8AD_11D2_9611_444553540000__INCLUDED_)
