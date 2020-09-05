// LaoKaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LaoKa.h"
#include "LaoKaDlg.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
static HINSTANCE hinstDLL; 
//static HMODULE hinstDLL;
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

typedef void(CALLBACK *createPopDlg)(HWND h);
createPopDlg createPop;

typedef void(CALLBACK *destroyPopDlg)();
destroyPopDlg destroyPop;
//
CString LaoDLL=(CString)"LaoDLL.dll";

// CLaoKaDlg dialog




CLaoKaDlg::CLaoKaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaoKaDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDD_LAOKA_DIALOG);		
}

void CLaoKaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_RADIO2,optUnicode);
	DDX_Control(pDX,IDC_COMBO1,cbFontType);
	//DDX_Control(pDX,IDD_PROPPAGE_SMALL,abouDlg);
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
END_MESSAGE_MAP()

bool LoadLaoKaDLL(CString DLLNAME)
{
	hinstDLL=NULL;
	hinstDLL = LoadLibrary(DLLNAME); 
	instkbhook = (inshook)GetProcAddress(hinstDLL, "installhook"); 
	UnHook = (unhook)GetProcAddress(hinstDLL, "UnHook"); 
	DISPLAYUNICODEMODE=(DisplayUnicodeMode)GetProcAddress(hinstDLL, "DisplayUnicodeMode");
	DISPLAYFONTINDEX=(DisplayIndex)GetProcAddress(hinstDLL, "DisplayIndex");	
	destroyPop=(destroyPopDlg)GetProcAddress(hinstDLL,"destroyPopDlg");
	createPop=(createPopDlg)GetProcAddress(hinstDLL,"createPopDlg");
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
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	if(!LoadLaoKaDLL(LaoDLL))
	{
		MessageBeep(0);
		MessageBox((CString)"Library not found! please reinstall LaoKa",0,0);
		return false;
	}
	createPop(::GetDesktopWindow());
	int fontIndex=DISPLAYFONTINDEX();
	bool unicodemode=DISPLAYUNICODEMODE();	
	SETUNICODEMODE(true);
	USEFONTTYPE(LAOKA_UNICODE_FONT_INDEX);
	fontIndex=DISPLAYFONTINDEX();
	unicodemode=DISPLAYUNICODEMODE();
	cbFontType.AddString((CString)"Unicode");
	cbFontType.AddString((CString)"2000");
	cbFontType.SetCurSel(1);
	optUnicode.SetCheck(1);
	if(instkbhook!=NULL)
		instkbhook();
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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaoKaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CLaoKaDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_MINIMIZE);
	//OnOK();
}

void CLaoKaDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CLaoKaDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
CString text;
	cbFontType.GetLBText(cbFontType.GetCurSel(),text);	
	if(UnHook!=NULL)
	{
		if(!UnHook())
		FreeLibrary(hinstDLL);	
	}
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
	{
		if(!UnHook())
		FreeLibrary(hinstDLL);	
	}
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
	{
		if(!UnHook())
		FreeLibrary(hinstDLL);	
	}
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
	destroyPop();
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
