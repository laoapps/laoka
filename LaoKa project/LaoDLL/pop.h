#pragma once


// pop dialog
#include "Resource.h"
class pop : public CDialog
{
	DECLARE_DYNAMIC(pop)

public:
	pop(CWnd* pParent = NULL);   // standard constructor
	virtual ~pop();
	

// Dialog Data
	enum { IDD = IDD_OLE_PROPPAGE_SMALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
//declare object on dialog box==========
public: 
	CStatic laoka;
public: 
	CStatic lao;
	CEdit editlao;
public:
	void showModaless(CString sxlk,CString sxl);
	void setInit();
	void setlaokanlaoText (CString lk,CString l);	
};

