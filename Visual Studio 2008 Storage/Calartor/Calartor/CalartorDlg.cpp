// CalartorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calartor.h"
#include "CalartorDlg.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCalartorDlg �Ի���




CCalartorDlg::CCalartorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalartorDlg::IDD, pParent)
	, ShowString(_T(""))
	, OperatorNumLeft(0)
	, OperatorNumRight(0)
	, Loc(0)
	, SymbolLoc(0)
	, Result(0)
	, EqualNum(0)
	, SymbolFlag(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalartorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_show);
	DDX_Text(pDX, IDC_EDIT1, ShowString);
}

BEGIN_MESSAGE_MAP(CCalartorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_32773, &CCalartorDlg::AthurorInformation)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalartorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalartorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalartorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalartorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalartorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalartorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalartorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalartorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalartorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalartorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_SURE, &CCalartorDlg::OnBnClickedSure)
	ON_BN_CLICKED(IDC_DOT, &CCalartorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_PULS, &CCalartorDlg::OnBnClickedPuls)
	ON_BN_CLICKED(IDC_MINUS, &CCalartorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_TIME, &CCalartorDlg::OnBnClickedTime)
	ON_BN_CLICKED(IDC_DIV, &CCalartorDlg::OnBnClickedDiv)
END_MESSAGE_MAP()


// CCalartorDlg ��Ϣ�������

BOOL CCalartorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	ShowString = _T("");
	Loc = 0;
	SymbolLoc = 0;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalartorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalartorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalartorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalartorDlg::AthurorInformation()
{
	// TODO: �ڴ���������������
	MessageBox(_T("�����ߣ�����˹\n����ʱ�䣺2015-2-19"), _T("������"));
}

void CCalartorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("1");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("2");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("3");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("4");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("5");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("6");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("7");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("8");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("9");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T("0");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedDot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Loc++;
	ShowString += _T(".");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedPuls()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SymbolFlag = 1;  // �Ӻ�
	if (EqualNum > 0)
	{
		ShowString = _T("Ans+");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // �������ڵ�λ��
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // �������ڵ�λ��
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("+");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}

void CCalartorDlg::OnBnClickedMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SymbolFlag = 2;   // ����
	if (EqualNum > 0)
	{
		ShowString = _T("Ans-");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // �������ڵ�λ��
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // �������ڵ�λ��
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("-");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}

void CCalartorDlg::OnBnClickedTime()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SymbolFlag = 3;   // �˺�
	if (EqualNum > 0)
	{
		ShowString = _T("Ans*");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // �������ڵ�λ��
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // �������ڵ�λ��
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("*");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}

void CCalartorDlg::OnBnClickedDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SymbolFlag = 4;   // ����
	if (EqualNum > 0)
	{
		ShowString = _T("Ans/");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // �������ڵ�λ��
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // �������ڵ�λ��
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("/");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}


void CCalartorDlg::OnBnClickedSure()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EqualNum++;
	CString SecNum = _T("");
	for (int i=SymbolLoc; i<Loc; i++)
		SecNum += ShowString[i];
	OperatorNumRight = _wtof(SecNum.GetBuffer());
	switch(SymbolFlag)
	{
	case 1: 
		Result = OperatorNumLeft + OperatorNumRight;
		break;
	case 2:
		Result = OperatorNumLeft - OperatorNumRight;
		break;
	case 3:
		Result = OperatorNumLeft * OperatorNumRight;
		break;
	case 4:
		Result = OperatorNumLeft / OperatorNumRight;
		break;
	default:
		break;
	}
	CString Resultstr;
	Resultstr.Format(_T("%lf"), Result);
	GetDlgItem(IDC_EDIT1)->SetWindowText(Resultstr);
}