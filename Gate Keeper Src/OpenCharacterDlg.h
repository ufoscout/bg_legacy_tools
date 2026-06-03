#if !defined(AFX_OPENCHARACTERDLG_H__4A4A5381_AD11_11D2_9611_444553540000__INCLUDED_)
#define AFX_OPENCHARACTERDLG_H__4A4A5381_AD11_11D2_9611_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenCharacterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COpenCharacterDlg dialog

class COpenCharacterDlg : public CDialog
{
// Construction
public:
	COpenCharacterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpenCharacterDlg)
	enum { IDD = IDD_OPEN_CHARACTER };
	CListCtrl	m_lcChars;
	//}}AFX_DATA

	// Set in OnOK. Complete path and filename.
	CString m_strFile;
	// Set in OnOK. Name of the character.
	CString m_strCharacter;

	CString m_strPath;
	void FindCharacters();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenCharacterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenCharacterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkCharacters(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENCHARACTERDLG_H__4A4A5381_AD11_11D2_9611_444553540000__INCLUDED_)
