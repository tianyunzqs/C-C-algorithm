// RegisterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManageSystem.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"
#include "VerificationCode.h"
#include "MysqlOperation.h"

// CRegisterDlg �Ի���

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialogEx)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegisterDlg::IDD, pParent)
	, RvcNum(_T(""))
{

}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RVCPIC, m_RvcPic);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SIGINOVER, &CRegisterDlg::OnBnClickedSiginover)
	ON_STN_CLICKED(IDC_RVCPIC, &CRegisterDlg::OnStnClickedRvcpic)
	ON_BN_CLICKED(IDC_RTEST, &CRegisterDlg::OnBnClickedRtest)
END_MESSAGE_MAP()


// CRegisterDlg ��Ϣ�������


void CRegisterDlg::OnBnClickedSiginover()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString usrname, password1, password2, vcnum;
	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
	GetDlgItem(IDC_RPASSWORD)->GetWindowText(password1);
	GetDlgItem(IDC_RPASSWORD2)->GetWindowText(password2);
	GetDlgItem(IDC_RVC)->GetWindowText(vcnum);
	if(usrname.IsEmpty())
	{
		MessageBox(_T("�û�������Ϊ�գ�"), _T("ע����ʾ"));
		GetDlgItem(IDC_RUSERNAME)->SetFocus();
		return;
	}
	if(password1.IsEmpty())
	{
		MessageBox(_T("���벻��Ϊ�գ�"), _T("ע����ʾ"));
		GetDlgItem(IDC_RPASSWORD)->SetFocus();
		return;
	}
	if(password1 != password2)
	{
		MessageBox(_T("������������벻һ�£��������������룡"), _T("ע����ʾ"));
		GetDlgItem(IDC_RPASSWORD2)->SetFocus();
		return;
	}
	if (vcnum != RvcNum)
	{
		MessageBox(_T("��֤���������"), _T("ע����ʾ"));
		GetDlgItem(IDC_RVC)->SetFocus();
		return;
	}

	CString sqlCommand0 = "insert into logininfo values('" 
		+ usrname + "', " + "'"+password1 + "', 0, now(), 0);";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand0;

	CMysqlOperation *sql = new CMysqlOperation();
	sql->CMysqlConnect();
	sql->UpdateDatabase(sqlCommand);
	MessageBox(_T("ע��ɹ���"), _T("ע��ɹ�"));
	sql->CMysqlClose();
	delete sql;
}


BOOL CRegisterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// ���ɲ���ʾ��ʼ��֤��
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	RvcNum = VC->Generate4RandNum();
	VC->ShengChengYanZhenMa(RvcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_RvcPic.SetBitmap(bitmap);	


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRegisterDlg::OnStnClickedRvcpic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	RvcNum = VC->Generate4RandNum(); // vcNum�ǳ�Ա����
	VC->ShengChengYanZhenMa(RvcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_RvcPic.SetBitmap(bitmap);	
}


void CRegisterDlg::OnBnClickedRtest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString usrname, password1, password2;
	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
	if(usrname.IsEmpty())
	{
		MessageBox(_T("�û�������Ϊ�գ�"), _T("ע����ʾ"));
		return;
	}
	CString sqlCommand0 = "select * from logininfo where username=";
	CString sqlCommand1 = sqlCommand0 + "'" + usrname + "'";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand1;

	CMysqlOperation *mysql = new CMysqlOperation();
	mysql->CMysqlConnect();
	MYSQL_RES *res = mysql->QueryDatabase(sqlCommand);
	if (0 == mysql_num_rows(res))
	{
		MessageBox(_T("���û�������ע�ᣡ"), _T("ע����ʾ"));
	} else 
	{
		MessageBox(_T("�û�����ע�ᣬ��ѡ�������û�����"), _T("ע����ʾ"));
	}
	mysql->CMysqlClose();
	delete mysql;
}
