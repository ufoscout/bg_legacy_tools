// BGEdit.h : main header file for the BGEDIT application
//

#if !defined(AFX_BGEDIT_H__DC8AAB05_A406_11D2_9611_8C5D1421B743__INCLUDED_)
#define AFX_BGEDIT_H__DC8AAB05_A406_11D2_9611_8C5D1421B743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBGEditApp:
// See BGEdit.cpp for the implementation of this class
//

class CBGEditApp : public CWinApp
{
public:
	CBGEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBGEditApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBGEditApp)
	afx_msg void OnAppAbout();
	afx_msg void OnSettingsGamelocation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BGEDIT_H__DC8AAB05_A406_11D2_9611_8C5D1421B743__INCLUDED_)
