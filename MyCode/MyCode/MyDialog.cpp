// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MyCode.h"
#include "MyDialog.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialog::IDD, pParent)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
END_MESSAGE_MAP()


// MyDialog 消息处理程序
