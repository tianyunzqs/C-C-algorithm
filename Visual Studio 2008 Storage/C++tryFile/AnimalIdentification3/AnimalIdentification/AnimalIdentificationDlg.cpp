// AnimalIdentificationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AnimalIdentification.h"
#include "AnimalIdentificationDlg.h"

#include "AnimalFeature.h"

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


// CAnimalIdentificationDlg �Ի���




CAnimalIdentificationDlg::CAnimalIdentificationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimalIdentificationDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimalIdentificationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
}

BEGIN_MESSAGE_MAP(CAnimalIdentificationDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CAnimalIdentificationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CAnimalIdentificationDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CAnimalIdentificationDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK2, &CAnimalIdentificationDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK4, &CAnimalIdentificationDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CAnimalIdentificationDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CAnimalIdentificationDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CAnimalIdentificationDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CAnimalIdentificationDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CAnimalIdentificationDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CAnimalIdentificationDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CAnimalIdentificationDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &CAnimalIdentificationDlg::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &CAnimalIdentificationDlg::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &CAnimalIdentificationDlg::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &CAnimalIdentificationDlg::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &CAnimalIdentificationDlg::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK17, &CAnimalIdentificationDlg::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK18, &CAnimalIdentificationDlg::OnBnClickedCheck18)
	ON_BN_CLICKED(IDC_CHECK19, &CAnimalIdentificationDlg::OnBnClickedCheck19)
END_MESSAGE_MAP()


// CAnimalIdentificationDlg ��Ϣ�������

BOOL CAnimalIdentificationDlg::OnInitDialog()
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

void CAnimalIdentificationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAnimalIdentificationDlg::OnPaint()
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
HCURSOR CAnimalIdentificationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

AnimalFeature AF;

void CAnimalIdentificationDlg::OnBnClickedButton1()
{
	AF.Rule1(AF.UserInputFeature);
	AF.Rule2(AF.UserInputFeature);
	AF.Rule3(AF.UserInputFeature);
	AF.Rule4(AF.UserInputFeature);
	AF.Rule5(AF.UserInputFeature);
	AF.Rule6(AF.UserInputFeature);
	AF.Rule7(AF.UserInputFeature);
	AF.Rule8(AF.UserInputFeature);
	AF.Rule9(AF.UserInputFeature);
	AF.Rule10(AF.UserInputFeature);
	AF.Rule11(AF.UserInputFeature);
	AF.Rule12(AF.UserInputFeature);
	AF.Rule13(AF.UserInputFeature);
	AF.Rule14(AF.UserInputFeature);
	AF.Rule15(AF.UserInputFeature);


	CBitmap bitmap;  // CBitmap�������ڼ���λͼ
	HBITMAP hBmp;    // ����CBitmap���ص�λͼ�ľ��
	int IsResult=0;
	for (int i=23; i<30; i++)
	{
		if (AF.UserInputFeature[i])
			IsResult++;
	}
	if (IsResult>1) // �Ƴ��Ľ����ֹһ�ֶ���
	{
		GetDlgItem(IDC_SHOW)->SetWindowText(_T("������Ϣ�������������룡"));
		bitmap.LoadBitmap(IDB_NORESULT);  // ��λͼIDB_BITMAP1���ص�bitmap 
		hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
		m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1
		goto over;
	}

	if (IsResult==1)
	{
		if(AF.UserInputFeature[23])
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("��Ǯ��"));
			bitmap.LoadBitmap(IDB_LEOPARD);  // ��λͼIDB_BITMAP1���ص�bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
			m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
		}
		if(AF.UserInputFeature[24])
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("�ϻ�"));
			bitmap.LoadBitmap(IDB_TIGER);  // ��λͼIDB_BITMAP1���ص�bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
			m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1
		}
		if(AF.UserInputFeature[25])
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("����¹"));
			bitmap.LoadBitmap(IDB_GIRAFFE);  // ��λͼIDB_BITMAP1���ص�bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
			m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
		}
		if(AF.UserInputFeature[26])
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("����"));
			bitmap.LoadBitmap(IDB_ZEBRA);  // ��λͼIDB_BITMAP1���ص�bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
			m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
		}
		if(AF.UserInputFeature[27])
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("����"));
			bitmap.LoadBitmap(IDB_OSTRICH);  // ��λͼIDB_BITMAP1���ص�bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
			m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1
		}
		if(AF.UserInputFeature[28])
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("���"));
			bitmap.LoadBitmap(IDB_PENGUIN);  // ��λͼIDB_BITMAP1���ص�bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
			m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
		}
		if(AF.UserInputFeature[29])
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("������"));
			bitmap.LoadBitmap(IDB_ALBATROSS);  // ��λͼIDB_BITMAP1���ص�bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
			m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1 
		}
	}

	if (IsResult<1) // �Ʋ����������ĳ�ֶ���
	{
		CString str("�����������Ϣ�������������ֶ���ö�������ǣ�");
		if(AF.UserInputFeature[19])
			str += "���鶯�� ";
		if(AF.UserInputFeature[20])
			str += "��";
		if(AF.UserInputFeature[21])
			str += "ʳ�⶯�� ";
		if(AF.UserInputFeature[22])
			str += "���㶯��";
		GetDlgItem(IDC_SHOW)->SetWindowText(str);
		bitmap.LoadBitmap(IDB_NORESULT);  // ��λͼIDB_BITMAP1���ص�bitmap 
		hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��
		m_pic.SetBitmap(hBmp);// ����ͼƬ�ؼ�m_Pic��λͼΪIDB_BITMAP1
	}

over: AF.Clear();
}






void CAnimalIdentificationDlg::OnBnClickedCheck1()
{
	AF.UserInputFeature[0] = !AF.UserInputFeature[0];
}

void CAnimalIdentificationDlg::OnBnClickedCheck2()
{
	AF.UserInputFeature[1] = !AF.UserInputFeature[1];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck3()
{
	AF.UserInputFeature[2] = !AF.UserInputFeature[2];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck4()
{
	AF.UserInputFeature[3] = !AF.UserInputFeature[3];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck5()
{
	AF.UserInputFeature[4] = !AF.UserInputFeature[4];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck6()
{
	AF.UserInputFeature[5] = !AF.UserInputFeature[5];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck7()
{
	AF.UserInputFeature[6] = !AF.UserInputFeature[6];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck8()
{
	AF.UserInputFeature[7] = !AF.UserInputFeature[7];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck9()
{
	AF.UserInputFeature[8] = !AF.UserInputFeature[8];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck10()
{
	AF.UserInputFeature[9] = !AF.UserInputFeature[9];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck11()
{
	AF.UserInputFeature[10] = !AF.UserInputFeature[10];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck12()
{
	AF.UserInputFeature[11] = !AF.UserInputFeature[11];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck13()
{
	AF.UserInputFeature[12] = !AF.UserInputFeature[12];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck14()
{
	AF.UserInputFeature[13] = !AF.UserInputFeature[13];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck15()
{
	AF.UserInputFeature[14] = !AF.UserInputFeature[14];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck16()
{
	AF.UserInputFeature[15] = !AF.UserInputFeature[15];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck17()
{
	AF.UserInputFeature[16] = !AF.UserInputFeature[16];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck18()
{
	AF.UserInputFeature[17] = !AF.UserInputFeature[17];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck19()
{
	AF.UserInputFeature[18] = !AF.UserInputFeature[18];	
}
