#if !defined(AFX_GAMELOCATIONDLG_H__DC8AAB19_A406_11D2_9611_8C5D1421B743__INCLUDED_)
#define AFX_GAMELOCATIONDLG_H__DC8AAB19_A406_11D2_9611_8C5D1421B743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameLocationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameLocationDlg dialog

class CGameLocationDlg : public CDialog
{
// Construction
public:
	CGameLocationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGameLocationDlg)
	enum { IDD = IDD_GAME_LOCATION };
	CString	m_strGamePath;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameLocationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGameLocationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBrowseLocation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMELOCATIONDLG_H__DC8AAB19_A406_11D2_9611_8C5D1421B743__INCLUDED_)
