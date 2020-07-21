// LaoKaDlg.cpp : implementation file
//
#include <afxpriv.h>
#include "stdafx.h"
#include "LaoKa.h"
#include "LaoKaDlg.h"
#include "AboutDlg.h"
#include "MouseMsgHandlerImpl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
static HINSTANCE hinstDLL; 
//NotifyICON
HWND hWnd= GetForegroundWindow();
//ISRULE2,ISUNICODE
//set up hook
typedef BOOL (CALLBACK *inshook)(); 
inshook instkbhook;
//Unhook
typedef BOOL (CALLBACK *unhook)(); 
unhook UnHook;
//
typedef int(CALLBACK *DisplayIndex)();
DisplayIndex DISPLAYFONTINDEX;
typedef bool(CALLBACK *DisplayUnicodeMode)();
DisplayUnicodeMode DISPLAYUNICODEMODE;
//
CString LaoDLL=(CString)"LaoDLL.dll";


// CLaoKaDlg dialog
CLaoKaDlg::CLaoKaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaoKaDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(ID_LAOKA_ICON);	
	
}

void CLaoKaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_RADIO2,optUnicode);
	DDX_Control(pDX,IDC_COMBO1,cbFontType);	
}

BEGIN_MESSAGE_MAP(CLaoKaDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CLaoKaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLaoKaDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLaoKaDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, &CLaoKaDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CLaoKaDlg::OnBnClickedRadio2)
	ON_COMMAND(ID_FILE_EXIT, &CLaoKaDlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUTUS, &CLaoKaDlg::OnHelpAboutus)
	ON_COMMAND(ID_HELP_USERGUIDE, &CLaoKaDlg::OnHelpUserguide)
	ON_COMMAND(ID_TASKBARMENU_GUIDE, &CLaoKaDlg::OnTaskbarmenuGuide)
	ON_COMMAND(ID_Menu, &CLaoKaDlg::OnMenu)
	ON_COMMAND(ID_TASKBARMENU_SHOWLAOKA, &CLaoKaDlg::OnTaskbarmenuShowlaoka)
	ON_COMMAND(ID_TASKBARMENU_EXIT, &CLaoKaDlg::OnTaskbarmenuExit)
END_MESSAGE_MAP()

bool LoadLaoKaDLL(CString DLLNAME)
{
	hinstDLL=NULL;
	hinstDLL = LoadLibrary(DLLNAME); 
	instkbhook = (inshook)GetProcAddress(hinstDLL, "installhook"); 
	UnHook = (unhook)GetProcAddress(hinstDLL, "UnHook"); 
	DISPLAYUNICODEMODE=(DisplayUnicodeMode)GetProcAddress(hinstDLL, "DisplayUnicodeMode");
	DISPLAYFONTINDEX=(DisplayIndex)GetProcAddress(hinstDLL, "DisplayIndex");	
	if(hinstDLL==NULL)
		return false;
	return true;
}
// CLaoKaDlg message handlers
BOOL CLaoKaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	if(!LoadLaoKaDLL(LaoDLL))
	{
		MessageBeep(0);
		MessageBox((CString)"Library not found! please reinstall LaoKa",0,0);
		return false;
	}
	int fontIndex=DISPLAYFONTINDEX();
	bool unicodemode=DISPLAYUNICODEMODE();	
	SETUNICODEMODE(true);
	USEFONTTYPE(LAOKA_2000_FONT_INDEX);
	fontIndex=DISPLAYFONTINDEX();
	unicodemode=DISPLAYUNICODEMODE();
	cbFontType.AddString((CString)"Unicode");
	cbFontType.AddString((CString)"2000");
	cbFontType.SetCurSel(0);
	optUnicode.SetCheck(1);
	if(instkbhook!=NULL)
		instkbhook();	

	//NotifyICON
	// Declare an array of MouseMsgHandlerPtr of size 3, to handle three types of mouse events
	MouseMsgHandlerPtr *pHandler = new MouseMsgHandlerPtr [3];
	
	// Define an object of CRightMouseClickMsgHandler for handling right mouse button click events
	MouseMsgHandlerPtr rbcHandler = new CRightMouseClickMsgHandler();

	// Define an object of CLeftMouseDblClickMsgHandler for handling left mouse button double click events
	MouseMsgHandlerPtr lbcHandler = new CLeftMouseDblClickMsgHandler();

	// Define an object of CMouseHoverMsgHandler for handling mouse hover events
	MouseMsgHandlerPtr mhHandler = new CMouseHoverMsgHandler(m_pTrayIcon);

	pHandler[0] = lbcHandler;
	pHandler[1] = rbcHandler;
	pHandler[2] = mhHandler;

	// Declare an array of IconDataPtr of size 2, to add two sets of icons. 
	// Only one will be active though.
	IconDataPtr *pIconData = new IconDataPtr[2];
	LPSTR laokamode="LaoKa mode";
	LPSTR englishmode="English mode";
	// Define an object of LaoKa MFC icon
	pIconData[0] = new CIconData(IDD_LAOKA_DIALOG, laokamode, ID_LAOKA_ICON);	
	
	// Define an object of English MFC icon
	pIconData[1] = new CIconData(IDD_LAOKA_DIALOG, englishmode, ID_LAOKA_ICON_E);	

	// Define the CTrayIcon object
	m_pTrayIcon = new CTrayIcon(pHandler, 3, pIconData, 2, 0, SECOND);
	

	// Refer the CTrayIcon object to the CMouseHoverMsgHandler object, for handling mouse events
	((CMouseHoverMsgHandler*)mhHandler)->SetTrayIcon(m_pTrayIcon);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLaoKaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

int CLaoKaDlg::DoModal()
{
	int nResult;
	/*CDialog dlt;
   

   // load dialog template
   //if (!dlt.Load(MAKEINTRESOURCE(CLaoKaDlg::IDD))) return -1;

   // set your own font, for example "Arial", 10 pts.
   dlt.SetFont("Arial", 10);

   // get pointer to the modified dialog template
   LPSTR pdata = (LPSTR)GlobalLock(dlt.m_hTemplate);

   // let MFC know that you are using your own template
   m_lpszTemplateName = NULL;
   InitModalIndirect(pdata);

   // display dialog box
   

   // unlock memory object
   GlobalUnlock(dlt.m_hTemplate);*/
	nResult = CDialog::DoModal();
   return nResult;
}
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaoKaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLaoKaDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
	m_pTrayIcon->ShowIcon();
	//OnOK();		
}

void CLaoKaDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	delete m_pTrayIcon;	
	OnCancel();
}

void CLaoKaDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
CString text;
	cbFontType.GetLBText(cbFontType.GetCurSel(),text);	
	if(UnHook!=NULL)
		if(!UnHook()) return;
	FreeLibrary(hinstDLL);	
	if(!LoadLaoKaDLL(LaoDLL))
	{
		MessageBeep(0);
		MessageBox((CString)"Library not found! please reinstall LaoKa",0,0);
		return;
	}
	if(text=="2000")
		//LAOKA_CURRENT_FONT_INDEX=LAOKA_2000_FONT_INDEX;
		USEFONTTYPE(LAOKA_2000_FONT_INDEX);
	else
		//LAOKA_CURRENT_FONT_INDEX=LAOKA_UNICODE_FONT_INDEX;
		USEFONTTYPE(LAOKA_UNICODE_FONT_INDEX);
	if(instkbhook!=NULL)
		instkbhook();
	else
	{
		LoadLaoKaDLL(LaoDLL);
		if(instkbhook!=NULL)
		instkbhook();
	}			
	text.Format((LPCTSTR)"LaoKa Current font index: %d",DISPLAYFONTINDEX());
	//MessageBox(text,0,0);
}

void CLaoKaDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	CString text;
	if(UnHook!=NULL)
		if(!UnHook()) return;
	FreeLibrary(hinstDLL);
	if(!LoadLaoKaDLL(LaoDLL))
	{
		MessageBeep(0);
		MessageBox((CString)"Library not found! please reinstall LaoKa",0,0);
		return ;
	}
	//UNICODE_MODE=true;
	SETUNICODEMODE(false);
	if(instkbhook!=NULL)
		instkbhook();
	else
	{
		LoadLaoKaDLL(LaoDLL);
		if(instkbhook!=NULL)
		instkbhook();
	}
	text.Format((LPCTSTR)"non unicode LaoKa Unicode Mode: %d",DISPLAYUNICODEMODE());
	//MessageBox(text,0,0);
}

void CLaoKaDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	CString text;
	
	if(UnHook!=NULL)
		if(!UnHook()) return;	
	FreeLibrary(hinstDLL);
	if(!LoadLaoKaDLL(LaoDLL))
	{
		MessageBeep(0);
		MessageBox((CString)"Library not found! please reinstall LaoKa",0,0);
		return ;
	}
	//UNICODE_MODE=false;	
	SETUNICODEMODE(true);
	if(instkbhook!=NULL)
		instkbhook();
	else
	{
		LoadLaoKaDLL(LaoDLL);
		if(instkbhook!=NULL)
		instkbhook();
	}
	text.Format((LPCTSTR)"unicode LaoKa Unicode Mode: %d",DISPLAYUNICODEMODE());
	//MessageBox(text,0,0);
}

void CLaoKaDlg::OnFileExit()
{
	// TODO: Add your command handler code here
	OnCancel();
}

void CLaoKaDlg::OnHelpAboutus()
{
	// TODO: Add your command handler code here	
	AboutDlg about;			
	m_pParentWnd = &about;

	INT_PTR nResponse = about.DoModal();
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
}

void CLaoKaDlg::OnHelpUserguide()
{
	// TODO: Add your command handler code here
	
}


//NotifyICOn
void CLaoKaDlg::OnTaskbarmenuGuide()
{
	// TODO: Add your command handler code here
}
//aBOUT
void CLaoKaDlg::OnMenu()
{
	// TODO: Add your command handler code here
	AboutDlg about;			
	m_pParentWnd = &about;

	INT_PTR nResponse = about.DoModal();
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
}

void CLaoKaDlg::OnTaskbarmenuShowlaoka()
{
	// TODO: Add your command handler code here
	ShowWindow(SW_NORMAL);
	m_pTrayIcon->HideIcon();
}

void CLaoKaDlg::OnTaskbarmenuExit()
{
	// TODO: Add your command handler code here
	OnCancel();
}
