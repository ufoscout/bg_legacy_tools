#if !defined(AFX_SAVINGTHROWDLG_H__46760BC3_A968_11D2_9611_CC48A814FC4A__INCLUDED_)
#define AFX_SAVINGTHROWDLG_H__46760BC3_A968_11D2_9611_CC48A814FC4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SavingThrowDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSavingThrowDlg dialog

class CSavingThrowDlg : public CDialog
{
// Construction
public:
	CSavingThrowDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSavingThrowDlg)
	enum { IDD = IDD_SAVINGTHROWS };
	CSpinButtonCtrl	m_sbtnSaveS;
	CSpinButtonCtrl	m_sbtnSaveRSW;
	CSpinButtonCtrl	m_sbtnSavePPD;
	CSpinButtonCtrl	m_sbtnSavePP;
	CSpinButtonCtrl	m_sbtnSaveBW;
	UINT	m_nSaveBW;
	UINT	m_nSavePP;
	UINT	m_nSavePPD;
	UINT	m_nSaveRSW;
	UINT	m_nSaveS;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSavingThrowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSavingThrowDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVINGTHROWDLG_H__46760BC3_A968_11D2_9611_CC48A814FC4A__INCLUDED_)
