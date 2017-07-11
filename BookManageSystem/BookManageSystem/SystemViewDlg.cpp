// SystemViewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManageSystem.h"
#include "SystemViewDlg.h"
#include "afxdialogex.h"
#include "ChangeCode.h"


// CSystemViewDlg 对话框

IMPLEMENT_DYNAMIC(CSystemViewDlg, CDialogEx)

CSystemViewDlg::CSystemViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSystemViewDlg::IDD, pParent)
{
	
}

CSystemViewDlg::~CSystemViewDlg()
{
}


void CSystemViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_MyTree);
}


BEGIN_MESSAGE_MAP(CSystemViewDlg, CDialogEx)
	ON_COMMAND(IDCANCEL, &CSystemViewDlg::OnIdcancel)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CSystemViewDlg::OnNMClickTree1)
END_MESSAGE_MAP()


// CSystemViewDlg 消息处理程序

CChangeCode *pChangeCodeDlg = new CChangeCode();
BOOL CSystemViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	

	pChangeCodeDlg->Create(IDD_CHANGECODE, this); // 创建一个非模态对话框
	// 根据获得主对话框上图片控件的尺寸,将子对话框嵌入到主对话框中
	CRect r;
	GetDlgItem(IDC_STATIC_PIC)->GetWindowRect(r);
	ScreenToClient(r);
	/*这里可以把图形控件销毁了,否则子对话框将不会响应你的鼠标消息*/
	GetDlgItem(IDC_STATIC_PIC)->DestroyWindow();
	// 定位属性页
	pChangeCodeDlg->MoveWindow(r);
	//根据所要显示的控件进行对话框的消隐工作
	pChangeCodeDlg->ShowWindow(SW_HIDE); //显示非模态对话框

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

// 主页面对话框关闭后，整个程序退出
void CSystemViewDlg::OnIdcancel()
{
	// TODO: 在此添加命令处理程序代码
	//this->GetParent()->PostMessage(WM_CLOSE,0,0);  // 根最小化有冲突
	AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0);
	PostQuitMessage(0);
}


void CSystemViewDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint   pt;     
	UINT   nFlags;     
	//::GetCursorPos(&pt);     
	pt = GetCurrentMessage()->pt;   //获取当前鼠标点击消息的坐标点
	m_MyTree.ScreenToClient(&pt);
	//::ScreenToClient(m_MyTree.m_hWnd, &pt);
	HTREEITEM hItem = m_MyTree.HitTest(pt,&nFlags);

	if("修改密码" == m_MyTree.GetItemText(hItem))
	{
		pChangeCodeDlg->ShowWindow(SW_SHOW);
	}

	*pResult = 0;
}
