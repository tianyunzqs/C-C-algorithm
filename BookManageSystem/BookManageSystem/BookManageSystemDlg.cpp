
// BookManageSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManageSystem.h"
#include "BookManageSystemDlg.h"
#include "afxdialogex.h"
#include "VerificationCode.h"
#include "MysqlOperation.h"
#include "RegisterDlg.h"
#include "SystemViewDlg.h"

#include <io.h>  
#include <fcntl.h>   


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBookManageSystemDlg �Ի���




CBookManageSystemDlg::CBookManageSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBookManageSystemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBookManageSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ROLE, m_RoleCon);
	DDX_Control(pDX, IDC_VERIFICATIONCODE, m_Bitmap);
}

BEGIN_MESSAGE_MAP(CBookManageSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, &CBookManageSystemDlg::OnBnClickedLogin)
	ON_STN_CLICKED(IDC_VERIFICATIONCODE, &CBookManageSystemDlg::OnStnClickedVerificationcode)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_REGISTER, &CBookManageSystemDlg::OnBnClickedRegister)
END_MESSAGE_MAP()


void OpenConsole()  
{  
	AllocConsole();  
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	int hCrt = _open_osfhandle((long)handle,_O_TEXT);  
	FILE * hf = _fdopen( hCrt, "w" );  
	*stdout = *hf;  
} 


// CBookManageSystemDlg ��Ϣ�������

BOOL CBookManageSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	Sleep(10);
	this->CenterWindow(GetDesktopWindow()); // ������ʾ
	ShowWindow(SW_SHOW);

	m_RoleCon.AddString(_T("ѧ��"));
	m_RoleCon.AddString(_T("��ʦ"));
	m_RoleCon.AddString(_T("����Ա"));
	m_RoleCon.SetCurSel(0);


	// ���ɲ���ʾ��ʼ��֤��
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	vcNum = VC->Generate4RandNum();
	VC->ShengChengYanZhenMa(vcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_Bitmap.SetBitmap(bitmap);	

	//OpenConsole();  


	CRect rect;      
	GetClientRect(&rect);     //ȡ�ͻ�����С    
	old.x = rect.right - rect.left;  
	old.y = rect.bottom - rect.top; 


	// �ؼ�����
	CFont * m_pFont;
	m_pFont = new CFont;
	m_pFont->CreateFont(32,            // nHeight
		0,           // nWidth
		0,           // nEscapement
		0,           // nOrientation
		FW_BOLD,     // nWeight
		FALSE,        // bItalic
		FALSE,       // bUnderline
		0,           // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("����"));              // lpszFac
	GetDlgItem(IDC_TITLE)->SetFont(m_pFont,false);

	// ��ס�û��������빦��
	CMysqlOperation *myInitSql = new CMysqlOperation();
	myInitSql->CMysqlConnect();
	CString sqlCommand = "select * from \
						 (select * from logininfo order by logintime desc) NOname limit 1";
	char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
	MYSQL_RES *res = myInitSql->QueryDatabase(sqlC);
	MYSQL_ROW col = mysql_fetch_row(res);
	CString UserName = col[0];
	CString PassWord = col[1];
	int NextTpye = atoi(col[2]);
	if(NextTpye==1) // ��ס�û���
		GetDlgItem(IDC_USERNAME)->SetWindowText(UserName);
	else // ��ס�û��������룬���߶�ûѡ
	{
		GetDlgItem(IDC_USERNAME)->SetWindowText(UserName);
		GetDlgItem(IDC_PASSWORD)->SetWindowText(PassWord);
	}
	delete myInitSql;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CBookManageSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBookManageSystemDlg::OnPaint()
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
		// CDialogEx::OnPaint();
		CPaintDC dc(this);
		CRect rc;
		GetClientRect(&rc);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1);

		BITMAP bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBookManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBookManageSystemDlg::OnBnClickedLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString UserNameInput, PassWordInput, UserInputVcNum;
	GetDlgItem(IDC_USERNAME)->GetWindowText(UserNameInput);
	GetDlgItem(IDC_PASSWORD)->GetWindowText(PassWordInput);
	GetDlgItem(IDC_VC)->GetWindowText(UserInputVcNum);

	if (UserNameInput.IsEmpty())
	{
		MessageBox(_T("�û�������Ϊ�գ�"), _T("��¼��ʾ"));
		return;
	}
	if(PassWordInput.IsEmpty())
	{
		MessageBox(_T("���벻��Ϊ�գ�"), _T("��¼��ʾ"));
		return;
	}

	int nIndex = m_RoleCon.GetCurSel();
	char LoginRole[2];
	itoa(nIndex, LoginRole, 10);

	CString sqlCommand = "select * from logininfo where username='" \
		+ UserNameInput  + "' AND password='" + PassWordInput + "' AND loginrole=" \
		+ LoginRole;
	char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;

	CMysqlOperation *mysql = new CMysqlOperation();
	mysql->CMysqlConnect();
	MYSQL_RES *res = mysql->QueryDatabase(sqlC);
	if (0 == mysql_num_rows(res))
	{
		MessageBox(_T("�û������������"), _T("��¼��ʾ"));
	} else
	{
		if (UserInputVcNum != vcNum)
		{
			MessageBox(_T("��֤���������"), _T("��¼��ʾ"));
		} else
		{   // ��½�ɹ�
			// ��ֵ��ȫ�ֱ���
			CBookManageSystemApp *p = (CBookManageSystemApp *)AfxGetApp();
			p->LoginUserNameApp = UserNameInput;
			p->LoginPassWordApp = PassWordInput;

			CButton* pRemName = (CButton*)GetDlgItem(IDC_REMNAME);
			CButton* pRemBoth = (CButton*)GetDlgItem(IDC_REMBOTH);
			if(pRemName->GetCheck()==0 && pRemBoth->GetCheck()==0) 
			{	// ��ûѡ�����¿��û���ʱ�䣬����ʱ��ȵ�½ʱ���ͺ�1s
				CString sqlCommand1 = "update logininfo set logintime= \
									 (select date_add(now(), interval 1 second)) where \
									 username= '' AND password=''";
				CString sqlCommand2 = "update logininfo set logintime=now(), nexttype=0 \
									 where UserName='" + UserNameInput + "'";
				char *sqlC1 = (LPSTR)(LPCTSTR)sqlCommand1;
				char *sqlC2 = (LPSTR)(LPCTSTR)sqlCommand2;
				mysql->UpdateDatabase(sqlC1);
				mysql->UpdateDatabase(sqlC2);
				p->NextTypeApp = 0;
			}
			else if(pRemName->GetCheck()==1 && pRemBoth->GetCheck()==0)
			{	// ��ס�û��������¸��û�����ʱ����´ε�½����
				CString sqlCommand = "update logininfo set logintime=now(), nexttype=1 \
									  where UserName='" + UserNameInput + "'";
				char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
				mysql->UpdateDatabase(sqlC);
				p->NextTypeApp = 1;
			}
			else if(pRemBoth->GetCheck()==1) 
			{	// ��ס�û��������룬���¸��û�����ʱ����´ε�½����
				CString sqlCommand = "update logininfo set logintime=now(), nexttype=2 \
									 where UserName='" + UserNameInput + "'";
				char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
				mysql->UpdateDatabase(sqlC);
				p->NextTypeApp = 2;
			}

			this->ShowWindow(SW_HIDE);
			CSystemViewDlg *pTD = new CSystemViewDlg();
			pTD->Create(IDD_SYSTEMVIEWDLG, GetDesktopWindow()); //����һ����ģ̬�Ի���
			pTD->ShowWindow(SW_SHOW); //��ʾ��ģ̬�Ի���	
			HTREEITEM hItem, hSubItem;
			hItem = pTD->m_MyTree.InsertItem(_T("���˻�����Ϣ"),TVI_ROOT); //�ڸ���������Parent1
			hSubItem = pTD->m_MyTree.InsertItem(_T("������Ϣ��ѯ"),hItem); //��Parent1�����һ���ӽ��
			hSubItem = pTD->m_MyTree.InsertItem(_T("�޸ĸ�����Ϣ"),hItem,hSubItem); //��Parent1�����һ���ӽ�㣬����Child1_1����
			hSubItem = pTD->m_MyTree.InsertItem(_T("�޸�����"),hItem,hSubItem);
			hItem = pTD->m_MyTree.InsertItem(_T("ͼ����Ϣ"),TVI_ROOT,hItem);
			hSubItem = pTD->m_MyTree.InsertItem(_T("ͼ���ѯ"),hItem);
			hSubItem = pTD->m_MyTree.InsertItem(_T("���ͼ��"),hItem, hSubItem);
			hItem = pTD->m_MyTree.InsertItem(_T("�"),TVI_ROOT,hItem);
		}
	}
	mysql->CMysqlClose();
	delete mysql;
}


void CBookManageSystemDlg::OnStnClickedVerificationcode()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	vcNum = VC->Generate4RandNum(); // vcNum�ǳ�Ա����
	VC->ShengChengYanZhenMa(vcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_Bitmap.SetBitmap(bitmap);	
}


// ͨ�����������ϢWM_CTLCOLOR����
HBRUSH CBookManageSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if(nCtlColor == CTLCOLOR_STATIC ) 
	{ 
		pDC->SetBkMode(TRANSPARENT);//���ñ���͸�� 
		pDC->SetTextColor(RGB(0,0,0));//��������Ϊ��ɫ 
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

void CBookManageSystemDlg::ReSize()
{  
	float fsp[2];  
	POINT Newp; //��ȡ���ڶԻ���Ĵ�С  
	CRect recta;      
	GetClientRect(&recta);     //ȡ�ͻ�����С    
	Newp.x=recta.right-recta.left;  
	Newp.y=recta.bottom-recta.top;  
	fsp[0]=(float)Newp.x/old.x;  
	fsp[1]=(float)Newp.y/old.y;  
	CRect Rect;  
	int woc;  
	CPoint OldTLPoint,TLPoint; //���Ͻ�  
	CPoint OldBRPoint,BRPoint; //���½�  
	HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //�г����пؼ�    
	while(hwndChild)      
	{      
		woc=::GetDlgCtrlID(hwndChild);//ȡ��ID  
		GetDlgItem(woc)->GetWindowRect(Rect);    
		ScreenToClient(Rect);    
		OldTLPoint = Rect.TopLeft();    
		TLPoint.x = long(OldTLPoint.x*fsp[0]);    
		TLPoint.y = long(OldTLPoint.y*fsp[1]);    
		OldBRPoint = Rect.BottomRight();    
		BRPoint.x = long(OldBRPoint.x *fsp[0]);    
		BRPoint.y = long(OldBRPoint.y *fsp[1]);    
		Rect.SetRect(TLPoint,BRPoint);    
		GetDlgItem(woc)->MoveWindow(Rect,TRUE);  
		hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);      
	}  
	old=Newp;  
}

void CBookManageSystemDlg::OnSize(UINT nType, int cx, int cy)
{
	//CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (nType==SIZE_RESTORED||nType==SIZE_MAXIMIZED)  
	{  
		ReSize();  
	}
}


void CBookManageSystemDlg::OnBnClickedRegister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRegisterDlg dlg;
	if(dlg.DoModal() == IDOK)
		dlg.ShowWindow(SW_SHOW); 
}
