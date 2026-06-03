#if !defined(AFX_PROFICIENCIESDLG_H__60404904_A8AD_11D2_9611_444553540000__INCLUDED_)
#define AFX_PROFICIENCIESDLG_H__60404904_A8AD_11D2_9611_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProficienciesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProficienciesDlg dialog

class CProficienciesDlg : public CDialog
{
// Construction
public:
	CProficienciesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProficienciesDlg)
	enum { IDD = IDD_PROFICIENCIES };
	CSpinButtonCtrl	m_sbtnProfSmSword;
	CSpinButtonCtrl	m_sbtnProfSpiked;
	CSpinButtonCtrl	m_sbtnProfSpear;
	CSpinButtonCtrl	m_sbtnProfMissile;
	CSpinButtonCtrl	m_sbtnProfLgSword;
	CSpinButtonCtrl	m_sbtnProfBow;
	CSpinButtonCtrl	m_sbtnProfBlunt;
	CSpinButtonCtrl	m_sbtnProfAxe;
	UINT	m_nProfAxe;
	UINT	m_nProfBlunt;
	UINT	m_nProfBow;
	UINT	m_nProfLgSword;
	UINT	m_nProfMissile;
	UINT	m_nProfSmSword;
	UINT	m_nProfSpear;
	UINT	m_nProfSpiked;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProficienciesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProficienciesDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROFICIENCIESDLG_H__60404904_A8AD_11D2_9611_444553540000__INCLUDED_)
