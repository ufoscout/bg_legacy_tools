#if !defined(AFX_THIEFSKILLSDLG_H__42A72203_AA2F_11D2_9611_444553540000__INCLUDED_)
#define AFX_THIEFSKILLSDLG_H__42A72203_AA2F_11D2_9611_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThiefSkillsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThiefSkillsDlg dialog

class CThiefSkillsDlg : public CDialog
{
// Construction
public:
	CThiefSkillsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CThiefSkillsDlg)
	enum { IDD = IDD_THIEF_SKILLS };
	CSpinButtonCtrl	m_sbtnDetectTraps;
	CSpinButtonCtrl	m_sbtnStealth;
	CSpinButtonCtrl	m_sbtnPickPockets;
	CSpinButtonCtrl	m_sbtnOpenLocks;
	int		m_nDetectTrapsBase;
	int		m_nOpenLocksBase;
	int		m_nPickPocketsBase;
	int		m_nStealthBase;
	int		m_nDetectTrapsRace;
	int		m_nOpenLocksRace;
	int		m_nPickPocketsRace;
	int		m_nStealthRace;
	int		m_nDetectTrapsDex;
	int		m_nOpenLocksDex;
	int		m_nPickPocketsDex;
	int		m_nStealthDex;
	UINT	m_nDetectTraps;
	UINT	m_nOpenLocks;
	UINT	m_nPickPockets;
	UINT	m_nStealth;
	int		m_nDetectTrapsActual;
	int		m_nOpenLocksActual;
	int		m_nPickPocketsActual;
	int		m_nStealthActual;
	//}}AFX_DATA

	int m_nRace;
	int m_nDex;

	void CalculateTotals();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThiefSkillsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThiefSkillsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeDetectTraps();
	afx_msg void OnChangeOpenLocks();
	afx_msg void OnChangePickPockets();
	afx_msg void OnChangeStealth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THIEFSKILLSDLG_H__42A72203_AA2F_11D2_9611_444553540000__INCLUDED_)
