// BGEdit.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BGEdit.h"
#include "GameLocationDlg.h"
#include "MainFrm.h"
#include "BGEditDoc.h"
#include "BGEditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBGEditApp

BEGIN_MESSAGE_MAP(CBGEditApp, CWinApp)
	//{{AFX_MSG_MAP(CBGEditApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_SETTINGS_GAMELOCATION, OnSettingsGamelocation)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBGEditApp construction

CBGEditApp::CBGEditApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBGEditApp object

CBGEditApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBGEditApp initialization

int CBGEditApp::ExitInstance() 
{
	CString strSection;
	strSection = "Settings";
	WriteProfileString(strSection,"Game Path",_strGamePath);

	return CWinApp::ExitInstance();
}

BOOL CBGEditApp::InitInstance()
{
#ifdef _DEBUG
	afxMemDF = allocMemDF | checkAlwaysMemDF;
#endif

	AfxEnableControlContainer();

	// If the Shift key is being held down whent he program starts let the 
	// user edit .chr files.
/*	if (GetKeyState(VK_SHIFT) & 0x80000000)
		_bAllowChrEdit = TRUE;*/
	_bAllowChrEdit = TRUE;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("AIO"));

	CString strSection;
	strSection = "Settings";
	_strGamePath = GetProfileString(strSection,"Game Path","");

	if (_strGamePath.IsEmpty())
	{
		CRegKey rkSoftware, rkMicrosoft, rkDirectPlay;
		CRegKey rkApps, rkBaldur;

		if (rkSoftware.Open(HKEY_LOCAL_MACHINE,"Software") == ERROR_SUCCESS)
			if (rkMicrosoft.Open(rkSoftware.m_hKey,"Microsoft") == ERROR_SUCCESS)
				if (rkDirectPlay.Open(rkMicrosoft.m_hKey,"DirectPlay") == ERROR_SUCCESS)
					if (rkApps.Open(rkDirectPlay.m_hKey,"Applications") == ERROR_SUCCESS)
						if (rkBaldur.Open(rkApps.m_hKey,"Baldur's Gate") == ERROR_SUCCESS)
						{
							DWORD dwSize = _MAX_PATH;
							if (rkBaldur.QueryValue(_strGamePath.GetBufferSetLength(dwSize),"Path",&dwSize) == ERROR_SUCCESS)
								_strGamePath.ReleaseBuffer(dwSize);
							else
								_strGamePath.ReleaseBuffer(0);
						}
	}

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CBGEditDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CBGEditView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// If not allowing editing of .chr files, remove the menu item.
/*	if (!_bAllowChrEdit)
	{
		CMenu *pMenu = AfxGetMainWnd()->GetMenu();
		if (pMenu)
			pMenu->DeleteMenu(ID_FILE_OPEN_CHR,MF_BYCOMMAND);
	} */

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CBGEditApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBGEditApp message handlers

void CBGEditApp::OnSettingsGamelocation() 
{
	CGameLocationDlg d;
	
	d.m_strGamePath = _strGamePath;
	if (d.DoModal() == IDOK)
		_strGamePath = d.m_strGamePath;
}

