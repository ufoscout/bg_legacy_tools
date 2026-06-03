#if !defined(AFX_MAGICMEMORIZEDLG_H__60404908_A8AD_11D2_9611_444553540000__INCLUDED_)
#define AFX_MAGICMEMORIZEDLG_H__60404908_A8AD_11D2_9611_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MagicMemorizeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMagicMemorizeDlg dialog

class CMagicMemorizeDlg : public CDialog
{
// Construction
public:
	CMagicMemorizeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMagicMemorizeDlg)
	enum { IDD = IDD_MAGIC_MEMORIZE };
	UINT	m_nMemorized;
	//}}AFX_DATA

	CString m_strSpell;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagicMemorizeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMagicMemorizeDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAGICMEMORIZEDLG_H__60404908_A8AD_11D2_9611_444553540000__INCLUDED_)
