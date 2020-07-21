// AboutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LaoKa.h"
#include "AboutDlg.h"


// AboutDlg dialog

IMPLEMENT_DYNAMIC(AboutDlg, CDialog)

AboutDlg::AboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AboutDlg::IDD, pParent)
{

}

AboutDlg::~AboutDlg()
{
}
BOOL AboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	return TRUE;
}
void AboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_BUTTON1,clsButton);
}

BEGIN_MESSAGE_MAP(AboutDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &AboutDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// AboutDlg message handlers

void AboutDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
