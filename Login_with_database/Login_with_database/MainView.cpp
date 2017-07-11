// MainView.cpp : 实现文件
//

#include "stdafx.h"
#include "Login_with_database.h"
#include "MainView.h"
#include "afxdialogex.h"
#include "Login_with_databaseDlg.h"


// MainView 对话框

IMPLEMENT_DYNAMIC(MainView, CDialog)

MainView::MainView(CWnd* pParent /*=NULL*/)
	: CDialog(MainView::IDD, pParent)
{

}

MainView::~MainView()
{
}

void MainView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_ctrlTree);
}


BEGIN_MESSAGE_MAP(MainView, CDialog)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &MainView::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// MainView 消息处理程序


void MainView::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
