#if !defined(AFX_OPENGAMEDLG_H__DC8AAB18_A406_11D2_9611_8C5D1421B743__INCLUDED_)
#define AFX_OPENGAMEDLG_H__DC8AAB18_A406_11D2_9611_8C5D1421B743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenGameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COpenGameDlg dialog

class COpenGameDlg : public CDialog
{
// Construction
public:
	COpenGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpenGameDlg)
	enum { IDD = IDD_OPEN_GAME };
	CListBox	m_lbGames;
	int		m_nGameType;
	CString	m_strGameName;
	//}}AFX_DATA

	// Name of the file to open once OK has been pushed.
	CString m_strFile;

	void FindGames();

	BOOL GetPath();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnGametype();
	afx_msg void OnGametype2();
	afx_msg void OnDblclkSavedGames();
	virtual void OnOK();
	afx_msg void OnVerify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGAMEDLG_H__DC8AAB18_A406_11D2_9611_8C5D1421B743__INCLUDED_)
