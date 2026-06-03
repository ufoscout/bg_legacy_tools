#if !defined(AFX_CHANGENAMEDLG_H__AB36E6A2_B3FF_11D2_9611_B210CC6B6335__INCLUDED_)
#define AFX_CHANGENAMEDLG_H__AB36E6A2_B3FF_11D2_9611_B210CC6B6335__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangeNameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangeNameDlg dialog

class CChangeNameDlg : public CDialog
{
// Construction
public:
	CChangeNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeNameDlg)
	enum { IDD = IDD_CHANGE_NAME };
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangeNameDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGENAMEDLG_H__AB36E6A2_B3FF_11D2_9611_B210CC6B6335__INCLUDED_)
