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
 DLLEXPORT  int DisplayIndex()
{
	return LAOKA_CURRENT_FONT_INDEX;	
}
 DLLEXPORT bool  DisplayUnicodeMode()
{
	return UNICODE_MODE;
}

void DLLEXPORT __stdcall createPopDlg(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//hWnd=GetDesktopWindow();
		CWnd *pParent = CWnd::FromHandle(hWnd);													
		if(mpop == NULL)
		{							
			mpop = new pop(pParent);	
		}	
		else
		{
			mpop->ShowWindow(SW_HIDE);
		}
		/*CStatic *lk=(CStatic *)mpop->GetDlgItem(IDC_STATIC1);
		CStatic *lak=(CStatic *)mpop->GetDlgItem(IDC_STATIC2);
		lk=new CStatic();
		lak=new CStatic();
		lk->SetWindowTextW(_T("Lao Ready"));
		lak->SetWindowTextW(_T("Laoka Ready"));*/
		//create an modaless dialogbox
		mpop->Create(MAKEINTRESOURCE(IDD_OLE_PROPPAGE_SMALL), pParent);		
		//create an Static text
		mpop->laoka.Create(_T("Lao ka Ready"),WS_VISIBLE,CRect(10,10,10,10),CWnd::FromHandle(mpop->GetSafeHwnd()));
		mpop->lao.Create(_T("Lao Ready"),WS_VISIBLE,CRect(0,0,20,20),CWnd::FromHandle(mpop->GetSafeHwnd()));
		//Create an edit boject
		mpop->editlao.Create(WS_VISIBLE,CRect(0,0,100,150),CWnd::FromHandle(mpop->GetSafeHwnd()),1);
		mpop->SetWindowPos(&pop::wndTopMost,0,0,50,50,SW_SHOW);
		mpop->ShowWindow(SW_SHOW);
		//mpop->DoModal();
}
void DLLEXPORT __stdcall destroyPopDlg()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
															
		if(mpop != NULL)
		{				
			mpop->DestroyWindow();
			delete mpop;			
			mpop = NULL;
		}	
}

CLaoDLLApp::CLaoDLLApp()
{

}


CLaoDLLApp theApp;

//init the instances
BOOL CLaoDLLApp::InitInstance()
{
	CWinApp::InitInstance();
	
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	hins=AfxGetInstanceHandle();
	INIT_LAOKA_CHAR_VALUE();
	VK_BACK_SCAN = MapVirtualKey(VK_BACK, 0);
	VK_LEFT_SCAN = MapVirtualKey(VK_LEFT, 0);
	VK_RETURN_SCAN=MapVirtualKey(VK_RETURN, 0);
	VK_RIGHT_SCAN=MapVirtualKey(VK_RIGHT, 0);
	
	return TRUE;
}
