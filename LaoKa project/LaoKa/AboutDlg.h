#pragma once


// AboutDlg dialog

class AboutDlg : public CDialog
{
	DECLARE_DYNAMIC(AboutDlg)

public:
	AboutDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AboutDlg();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_SMALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
public:
	CButton clsButton;
protected:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
