#if !defined(AFX_APPEARANCEDLG_H__EF8DD705_AEF0_11D2_9611_A447F2B02B0E__INCLUDED_)
#define AFX_APPEARANCEDLG_H__EF8DD705_AEF0_11D2_9611_A447F2B02B0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AppearanceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAppearanceDlg dialog

class CAppearanceDlg : public CDialog
{
// Construction
public:
	CAppearanceDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAppearanceDlg)
	enum { IDD = IDD_APPEARANCE };
	CComboBox	m_cboClass;
	CComboBox	m_cboSex;
	CComboBox	m_cboRace;
	//}}AFX_DATA

	unsigned char m_chAvatar;
	unsigned char m_chAvatarClass;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppearanceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAppearanceDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPEARANCEDLG_H__EF8DD705_AEF0_11D2_9611_A447F2B02B0E__INCLUDED_)
