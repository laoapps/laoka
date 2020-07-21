// LaoKa.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "LaoKa.h"
#include "LaoKaDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define ICON_ID				100			// ID for our systray icon
#define SYSTRAY_MSG			101			// Message send to the DlgProc when something happend
										// with the icon. When someone clicks on it, for example

// CLaoKaApp

BEGIN_MESSAGE_MAP(CLaoKaApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLaoKaApp construction

CLaoKaApp::CLaoKaApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CLaoKaApp object

CLaoKaApp theApp;


// CLaoKaApp initialization
BOOL CLaoKaApp::InitInstance()
{
	CWinApp::InitInstance();

	HANDLE hMutex = CreateMutex(NULL, FALSE, _T("Local\\LaoKa"));

_ASSERTE(hMutex != NULL); // CreateMutex shouldn't fail.


// Check if we created a new mutex or opened an existing.

if (GetLastError() == ERROR_ALREADY_EXISTS)

    exit(0);
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("LaoKa of Green Team Anousone,Somnuc"));

	CLaoKaDlg dlg;
	//Set font
	 /**/
	//
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
