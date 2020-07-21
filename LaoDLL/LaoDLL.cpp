// LaoDLL.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "LaoDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
BEGIN_MESSAGE_MAP(CLaoDLLApp, CWinApp)
END_MESSAGE_MAP()
//uninstall hook
BOOL DLLEXPORT __stdcall UnHook()
    {    	
    BOOL unhookedKB = UnhookWindowsHookEx(hkb);   
	BOOL unhookedM= UnhookWindowsHookEx(hm);	
	hkb=NULL;
	hm=NULL;
    return unhookedKB;
} 
//INSTALL HOOK
BOOL DLLEXPORT __stdcall installhook()
{	
	//set up hook
	if(UNICODE_MODE)
	{
		if(LAOKA_CURRENT_FONT_INDEX==LAOKA_UNICODE_FONT_INDEX)
			hkb=SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyboardProcUnicode_UnicodeFont,hins,0);
		else if(LAOKA_CURRENT_FONT_INDEX==LAOKA_2000_FONT_INDEX)
			hkb=SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyboardProcUnicode_2000Font,hins,0);
	}	
	else
	{
		if(LAOKA_CURRENT_FONT_INDEX==LAOKA_UNICODE_FONT_INDEX)
			hkb=SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyboardProcSimple_UnicodeFont,hins,0);
		else if(LAOKA_CURRENT_FONT_INDEX==LAOKA_2000_FONT_INDEX)
			hkb=SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyboardProcSimple_2000Font,hins,0);
			

	}
	hm=SetWindowsHookEx(WH_MOUSE,(HOOKPROC)MouseProc,hins,0);
return TRUE;
}
DLLEXPORT int  DisplayIndex()
{
	return LAOKA_CURRENT_FONT_INDEX;	
}
DLLEXPORT bool  DisplayUnicodeMode()
{
	return UNICODE_MODE;
}
CLaoDLLApp::CLaoDLLApp()
{

}


CLaoDLLApp theApp;

//init the instances
BOOL CLaoDLLApp::InitInstance()
{
	CWinApp::InitInstance();
	INIT_LAOKA_CHAR_VALUE();
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	hins=AfxGetInstanceHandle();
	VK_BACK_SCAN = MapVirtualKey(VK_BACK, 0);
	VK_LEFT_SCAN = MapVirtualKey(VK_LEFT, 0);
	VK_RETURN_SCAN=MapVirtualKey(VK_RETURN, 0);
	VK_RIGHT_SCAN=MapVirtualKey(VK_RIGHT, 0);
	return TRUE;
}
