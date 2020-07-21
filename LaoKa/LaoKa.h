// LaoKa.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "LaoDLLExport.h"
#define LAOKA_UNICODE_FONT_INDEX 0
#define LAOKA_2000_FONT_INDEX 1
/////////////////////////////////////////////////////////////////////////////
// CInstallhookApp:
// See installhook.cpp for the implementation of this class
//
//#define DLLIMPORT __declspec(dllimport)
#pragma comment(lib,"../Release/LaoDLL.lib")
//DLLIMPORT bool UNICODE_MODE;
//DLLIMPORT int LAOKA_CURRENT_FONT_INDEX;
/*DLLIMPORT int  DisplayIndex();
DLLIMPORT bool  DisplayUnicodeMode();*/

// CLaoKaApp:
// See LaoKa.cpp for the implementation of this class
//

class CLaoKaApp : public CWinApp
{
public:
	CLaoKaApp();
// Overrides
	public:
	virtual BOOL InitInstance();
// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaoKaApp theApp;