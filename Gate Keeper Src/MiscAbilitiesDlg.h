#if !defined(AFX_MISCABILITIESDLG_H__EA7E1F02_B3CC_11D2_9611_CBA312EB435E__INCLUDED_)
#define AFX_MISCABILITIESDLG_H__EA7E1F02_B3CC_11D2_9611_CBA312EB435E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MiscAbilitiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMiscAbilitiesDlg dialog

class CMiscAbilitiesDlg : public CDialog
{
// Construction
public:
	CMiscAbilitiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMiscAbilitiesDlg)
	enum { IDD = IDD_MISC_ABILITIES };
	CSpinButtonCtrl	m_sbtnMagicResistance;
	CSpinButtonCtrl	m_sbtnAc;
	CComboBox	m_cboAttacks;
	CSpinButtonCtrl	m_sbtnThac0;
	CComboBox	m_cboRacialEnemy;
	UINT	m_nThac0;
	int		m_nAc;
	UINT	m_nMagicResistance;
	//}}AFX_DATA

	unsigned char m_chClass;
	unsigned char m_chRacialEnemy;
	unsigned char m_chNumberOfAttacks;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMiscAbilitiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMiscAbilitiesDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MISCABILITIESDLG_H__EA7E1F02_B3CC_11D2_9611_CBA312EB435E__INCLUDED_)
