// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, recieve(_T(""))
	, transmit(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMPORT, comport);
	DDX_Control(pDX, IDC_BITRATE, bitrate);
	DDX_Control(pDX, IDC_DATABITS, databits);
	DDX_Control(pDX, IDC_PARITYBITS, paritybits);
	DDX_Control(pDX, IDC_STOPBITS, stopbits);
	DDX_Control(pDX, IDC_HANDSHAKING, handshaking);
	DDX_Text(pDX, IDC_EDIT_RECIEVE, recieve);
	DDX_Text(pDX, IDC_EDIT_TRANSMIT, transmit);
	DDX_Control(pDX, IDC_MSCOMM1, mscomm);
	DDX_Control(pDX, IDC_COMPORT, comport);
	DDX_Control(pDX, IDC_BITRATE, bitrate);
	DDX_Control(pDX, IDC_DATABITS, databits);
	DDX_Control(pDX, IDC_PARITYBITS, paritybits);
	DDX_Control(pDX, IDC_STOPBITS, stopbits);
	DDX_Control(pDX, IDC_HANDSHAKING, handshaking);
	DDX_Text(pDX, IDC_EDIT_RECIEVE, recieve);
	DDX_Text(pDX, IDC_EDIT_TRANSMIT, transmit);
	DDX_Control(pDX, IDC_COMPORT, comport);
	DDX_Control(pDX, IDC_BITRATE, bitrate);
	DDX_Control(pDX, IDC_DATABITS, databits);
	DDX_Control(pDX, IDC_PARITYBITS, paritybits);
	DDX_Control(pDX, IDC_STOPBITS, stopbits);
	DDX_Control(pDX, IDC_HANDSHAKING, handshaking);
	DDX_Text(pDX, IDC_EDIT_RECIEVE, recieve);
	DDX_Text(pDX, IDC_EDIT_TRANSMIT, transmit);
	DDX_Control(pDX, IDC_MSCOMM1, mscomm);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CMFCApplication1Dlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMFCApplication1Dlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFCApplication1Dlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitCombobox();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//lay gia tri trong combobox
CString CMFCApplication1Dlg::GetCombobox(const CComboBox &a)
{
	CString str;
	a.GetLBText(a.GetCurSel(),str);
	return str;
}

void CMFCApplication1Dlg::InitCombobox ()
{
	CStringList ports;
	comport.ResetContent();
    for(int i=1; i<=16; i++)    
    {
        CString strPort;
        strPort.Format(_T("COM%d"),i);
		
        DWORD dwSize = 0;
        LPCOMMCONFIG lpCC = (LPCOMMCONFIG) new BYTE[1];
        BOOL ret = GetDefaultCommConfig(strPort, lpCC, &dwSize);
        delete [] lpCC;

        lpCC = (LPCOMMCONFIG) new BYTE[dwSize];
        ret = GetDefaultCommConfig(strPort, lpCC, &dwSize);
        if(ret)
            //ports.AddTail(strPort);
			comport.AddString(strPort);
		else
			comport.AddString(L"");
		comport.SetCurSel(i);

        delete [] lpCC;
    }

	bitrate.ResetContent();
	bitrate.InsertString(0,L"600");
	bitrate.InsertString(1,L"1200");
	bitrate.InsertString(2,L"2400");
	bitrate.InsertString(3,L"4800");
	bitrate.InsertString(4,L"9600");
	bitrate.InsertString(5,L"14400");
	bitrate.InsertString(6,L"19200");
	bitrate.InsertString(7,L"28800");
	bitrate.InsertString(8,L"38400");
	bitrate.InsertString(9,L"56000");
	bitrate.InsertString(10,L"57600");
	bitrate.InsertString(11,L"115200");
	bitrate.InsertString(12,L"128000");
	bitrate.InsertString(13,L"256000");
	bitrate.SetCurSel(4);

	databits.ResetContent();
	databits.AddString(L"5");
	databits.AddString(L"6");
	databits.AddString(L"7");
	databits.AddString(L"8");
	databits.SetCurSel(3);

	stopbits.ResetContent();
	stopbits.AddString(L"1");
	stopbits.AddString(L"1.5");
	stopbits.AddString(L"2");
	stopbits.SetCurSel(0);

	paritybits.ResetContent();
	paritybits.InsertString(0,L"None");
	paritybits.InsertString(1,L"Old");
	paritybits.InsertString(2,L"Even");
	paritybits.InsertString(3,L"Mark");
	paritybits.InsertString(4,L"Space");
	paritybits.SetCurSel(0);

	handshaking.ResetContent();
	handshaking.InsertString(0,L"None");
	handshaking.InsertString(1,L"XON/XOFF");
	handshaking.InsertString(2,L"RTS");
	handshaking.InsertString(3,L"RTS/CTS + XON/XOFF");
	handshaking.SetCurSel(0);
}

void CMFCApplication1Dlg::Setting()
{
	//kiem tra cong com: neu mo thi dong lai de thiet lap thong so
	if(mscomm.get_PortOpen()){
		mscomm.put_PortOpen(FALSE);
	}
	//Thiet lap cong com
	//int b = comport.GetCurSel()+1;
	mscomm.put_CommPort(comport.GetCurSel()+1); // Chon cong COM
	//
	mscomm.put_Handshaking(handshaking.GetCurSel());
	//cai dat thong so cho cong com
	CString strbitrate =  GetCombobox(bitrate);
	CString strparitybits = GetCombobox(paritybits);
	CString strdatabits = GetCombobox(databits);
	CString strstopbits = GetCombobox(stopbits);
	CString strsetting; 
	strsetting.Format(L"%s,%c,%s,%s",strbitrate,strparitybits[1],strdatabits,strstopbits);
	mscomm.put_Settings(strsetting);
	//
	mscomm.put_RThreshold(1);
	mscomm.put_InputLen(1);
	mscomm.put_InBufferSize(1024);
	mscomm.put_InputMode(0);
	mscomm.put_OutBufferSize(1024);
	mscomm.put_PortOpen(TRUE);
}



void CMFCApplication1Dlg::OnBnClickedButtonSend()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	Setting();
	mscomm.put_Output((COleVariant)transmit);
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButtonExit()
{
	// TODO: Add your control notification handler code here
	if(mscomm.get_PortOpen())
	{
		mscomm.put_PortOpen(FALSE);
	}
	OnOK();
}


void CMFCApplication1Dlg::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	recieve = "";
	UpdateData(false);
}


BEGIN_EVENTSINK_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_EVENT(CMFCApplication1Dlg, IDC_MSCOMM1, 1, CMFCApplication1Dlg::OnOncommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void CMFCApplication1Dlg::OnOncommMscomm1()
{
	// TODO: Add your message handler code here
	UpdateData();
	switch( mscomm.get_CommEvent()){
	case 1: // comEvSend
		break;
	case 2:// comEvReceive /// nhan data
	{
		VARIANT data = mscomm.get_Input();
		recieve += (CString)data.bstrVal;
		break;
	}
	case 3:{// comEvCTS
		break;}
	case 4://comEvDSR
		break;
	case 5: //comEvCD
		break;
	case 6://comEvRing
		break;
	case 7: //comEvEOF
		break;
	}
	UpdateData(false);
}
