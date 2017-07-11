// AnimalIdentification2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AnimalIdentification2.h"
#include "AnimalIdentification2Dlg.h"

#include "AnimalFeature2.h"

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


// CAnimalIdentification2Dlg �Ի���




CAnimalIdentification2Dlg::CAnimalIdentification2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimalIdentification2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimalIdentification2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
}

BEGIN_MESSAGE_MAP(CAnimalIdentification2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CAnimalIdentification2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CAnimalIdentification2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CAnimalIdentification2Dlg::OnBnClickedCheck2)
END_MESSAGE_MAP()


// CAnimalIdentification2Dlg ��Ϣ�������

BOOL CAnimalIdentification2Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CAnimalIdentification2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAnimalIdentification2Dlg::OnPaint()
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
HCURSOR CAnimalIdentification2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

AnimalFeature2 AF;
void CAnimalIdentification2Dlg::OnBnClickedButton1()
{
	CBitmap bitmap;  // CBitmap�������ڼ���λͼ
	HBITMAP hBmp;    // ����CBitmap���ص�λͼ�ľ��

	if (AF.UserInputFeature[0]==FALSE && AF.UserInputFeature[1]==FALSE)
	{	
		GetDlgItem(IDC_SHOW)->SetWindowText(_T("������"));
		bitmap.LoadBitmap(IDB_ALBATROSS);  // ��λͼIDB_BITMAP1���ص�bitmap 
		hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
		m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
	}
	if (AF.UserInputFeature[0]==FALSE && AF.UserInputFeature[1]==TRUE)
	{
		GetDlgItem(IDC_SHOW)->SetWindowText(_T("����¹"));
		bitmap.LoadBitmap(IDB_GIRAFFE);  // ��λͼIDB_BITMAP1���ص�bitmap 
		hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
		m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
	}
	if (AF.UserInputFeature[0]==TRUE && AF.UserInputFeature[1]==FALSE)
	{
		GetDlgItem(IDC_SHOW)->SetWindowText(_T("���"));
		bitmap.LoadBitmap(IDB_PENGUIN);  // ��λͼIDB_BITMAP1���ص�bitmap 
		hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
		m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
	}
	if (AF.UserInputFeature[0]==TRUE && AF.UserInputFeature[1]==TRUE)
	{
		GetDlgItem(IDC_SHOW)->SetWindowText(_T("�ϻ�"));

		bitmap.LoadBitmap(IDB_TIGER);  // ��λͼIDB_BITMAP1���ص�bitmap 
		hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
		m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1   
	}	
}

void CAnimalIdentification2Dlg::OnBnClickedCheck1()
{
	AF.UserInputFeature[0] = !AF.UserInputFeature[0];
}

void CAnimalIdentification2Dlg::OnBnClickedCheck2()
{
	AF.UserInputFeature[1] = !AF.UserInputFeature[1];
}

