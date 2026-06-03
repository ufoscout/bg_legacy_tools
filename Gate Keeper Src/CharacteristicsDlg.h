#if !defined(AFX_CHARACTERISTICSDLG_H__46760BC2_A968_11D2_9611_CC48A814FC4A__INCLUDED_)
#define AFX_CHARACTERISTICSDLG_H__46760BC2_A968_11D2_9611_CC48A814FC4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CharacteristicsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCharacteristicsDlg dialog

class CCharacteristicsDlg : public CDialog
{
// Construction
public:
	CCharacteristicsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCharacteristicsDlg)
	enum { IDD = IDD_CHARACTERISTICS };
	CComboBox	m_cboSpecialty;
	CButton	m_btnOk;
	CComboBox	m_cboSex;
	CComboBox	m_cboRace;
	CComboBox	m_cboClass;
	CComboBox	m_cboAlignment;
	//}}AFX_DATA

	unsigned char m_chRace;
	unsigned char m_chClass;
	unsigned char m_chSex;
	unsigned char m_chAlignment;
	short m_nMageSpecialty;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharacteristicsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCharacteristicsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeClass();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARACTERISTICSDLG_H__46760BC2_A968_11D2_9611_CC48A814FC4A__INCLUDED_)
