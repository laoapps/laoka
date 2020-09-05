// pop.cpp : implementation file
//

#include "stdafx.h"
#include "pop.h"

// pop dialog

IMPLEMENT_DYNAMIC(pop, CDialog)

pop::pop(CWnd* pParent /*=NULL*/)
	: CDialog(pop::IDD, pParent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//CDialog::OnInitDialog();
	//CDialog::m_hWnd=*CWnd::GetDesktopWindow();
}

pop::~pop()
{
}

void pop::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//mapping object on dialogbox and resources
	DDX_Control(pDX,/*MAKEINTRESOURCEW*/(IDC_STATIC1),laoka);
	DDX_Control(pDX,/*MAKEINTRESOURCEW*/(IDC_STATIC2),lao);
	DDX_Control(pDX,/*MAKEINTRESOURCEW*/(IDC_EDIT1),editlao);
}
BOOL pop::OnInitDialog()
{	
	return true;
}
void pop::setlaokanlaoText (CString xlk,CString xl)
{
	
	pop::laoka.SetWindowText(xlk);
	pop::lao.SetWindowText(xl);
	
	pop::editlao.SetWindowText(xlk+_T("//")+xl);
	pop::UpdateData(false);
}
void pop::showModaless(CString sxlk,CString sxl)
{
	POINT pt;
	CPoint ptx= CWnd::GetActiveWindow()->GetCaretPos();	
	GetCursorPos(&pt);
	pop::SetWindowPos(&pop::wndTopMost,pt.x,pt.y,150,150,SWP_SHOWWINDOW);
	CString tl;
	CString tlk;
	tlk.Format(_T("%d"), /*pt.x*/sxlk);
	//pop::laoka.SetWindowTextW(tlk);	
	tl.Format(_T("%d"), /*pt.y*/sxl);
	//pop::lao.SetWindowTextW(tl);
	pop::setlaokanlaoText(tlk,tl);

	
}

void pop::setInit()
{
	
	//pop::InitControlContainer(1);
}
BEGIN_MESSAGE_MAP(pop, CDialog)
END_MESSAGE_MAP()


// pop message handlers
