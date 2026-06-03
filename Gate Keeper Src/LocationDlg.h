#if !defined(AFX_LOCATIONDLG_H__AA585DA2_ABD4_11D2_9611_444553540000__INCLUDED_)
#define AFX_LOCATIONDLG_H__AA585DA2_ABD4_11D2_9611_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LocationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLocationDlg dialog

// Value of the item data for the quadrant selection.
#define MAPQUAD	0xFFFFFFFF

class CQuadButton;
class CLocationDlg : public CDialog
{
// Construction
public:
	CLocationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLocationDlg)
	enum { IDD = IDD_LOCATION };
	CComboBox	m_cbLocation;
	CComboBox	m_cbArea;
	//}}AFX_DATA

	CString m_strArea;
	unsigned short m_nMapX;
	unsigned short m_nMapY;

	CQuadButton m_btnA1;
	CQuadButton m_btnA2;
	CQuadButton m_btnA3;
	CQuadButton m_btnA4;
	CQuadButton m_btnB1;
	CQuadButton m_btnB2;
	CQuadButton m_btnB3;
	CQuadButton m_btnB4;
	CQuadButton m_btnC1;
	CQuadButton m_btnC2;
	CQuadButton m_btnC3;
	CQuadButton m_btnC4;
	CQuadButton m_btnD1;
	CQuadButton m_btnD2;
	CQuadButton m_btnD3;
	CQuadButton m_btnD4;

	void FillLocations();
	void ShowQuadrant(int nMapInfo);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLocationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLocationDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeLocation();
	afx_msg void OnSelchangeArea();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCATIONDLG_H__AA585DA2_ABD4_11D2_9611_444553540000__INCLUDED_)
