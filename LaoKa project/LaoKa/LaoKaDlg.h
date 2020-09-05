// LaoKaDlg.h : header file
//

#pragma once

// CLaoKaDlg dialog
class CLaoKaDlg : public CDialog
{
// Construction
public:
	CLaoKaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LAOKA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnCbnSelchangeCombo1();
public:
	afx_msg void OnBnClickedRadio1();
public:
	afx_msg void OnBnClickedRadio2();
public:
	CComboBox cbFontType;
public:
	CButton optUnicode;
public:
	afx_msg void OnFileExit();
public:
	afx_msg void OnHelpAboutus();
public:
	afx_msg void OnHelpUserguide();
};
