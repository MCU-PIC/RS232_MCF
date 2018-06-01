
// MFCApplication1Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"


// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

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
	
	CComboBox comport;
	CComboBox bitrate;
	CComboBox databits;
	CComboBox paritybits;
	CComboBox stopbits;
	CComboBox handshaking;
	CString recieve;
	CString transmit;
	CMscomm1 mscomm;
public:
	CString GetCombobox(const CComboBox &a);
	void InitCombobox ();
	void Setting();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonClear();
	DECLARE_EVENTSINK_MAP()
	void OnOncommMscomm1();
};
