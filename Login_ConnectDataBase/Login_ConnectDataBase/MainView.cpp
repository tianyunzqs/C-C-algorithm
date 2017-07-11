// MainView.cpp : 实现文件
//

#include "stdafx.h"
#include "Login_ConnectDataBase.h"
#include "MainView.h"
#include "afxdialogex.h"
#include "Login_ConnectDataBaseDlg.h"
#include "ChangeCode.h"


// CMainView 对话框

IMPLEMENT_DYNAMIC(CMainView, CDialog)

CMainView::CMainView(CWnd* pParent /*=NULL*/)
	: CDialog(CMainView::IDD, pParent)
{

}

CMainView::~CMainView()
{
}

void CMainView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_MyTree);
}


BEGIN_MESSAGE_MAP(CMainView, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CMainView::OnBnClickedCancel)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CMainView::OnNMClickTree1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMainView 消息处理程序

void CMainView::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//this->GetParent()->PostMessage(WM_CLOSE,0,0);  // 根最小化有冲突
	AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0);
	PostQuitMessage(0);
}


//void CMainView::OnBnClickedButton2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//
//	DWORD dwStyle = m_ctllist.GetExtendedStyle();                    //添加列表框的网格线！！！
//
//    dwStyle |= LVS_EX_FULLROWSELECT;            
//    dwStyle |= LVS_EX_GRIDLINES;                
//    m_ctllist.SetExtendedStyle(dwStyle);
//
//
//
//    m_ctllist.InsertColumn(0,"姓名",LVCFMT_LEFT,80);              //添加列标题！！！！  这里的80,40,90用以设置列的宽度。！！！LVCFMT_LEFT用来设置对齐方式！！！
//    m_ctllist.InsertColumn(1,"性别",LVCFMT_LEFT,40);
//    m_ctllist.InsertColumn(2,"年龄",LVCFMT_LEFT,40);
//    m_ctllist.InsertColumn(3,"电话",LVCFMT_LEFT,90);
//    m_ctllist.InsertColumn(4,"工作单位",LVCFMT_LEFT,140);
//}


CChangeCode *pTD = new CChangeCode();
void CMainView::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
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
		pTD->ShowWindow(SW_SHOW);
	}
		

	//if(!m_MyTree.ItemHasChildren(hItem)) // 判断是否是叶子节点
	//	AfxMessageBox(m_MyTree.GetItemText(hItem));

	*pResult = 0;
}

BOOL CMainView::OnInitDialog()
{
	CDialog::OnInitDialog();

	CRect rect;    
	GetClientRect(&rect);     //取客户区大小  
	old.x=rect.right-rect.left;
	old.y=rect.bottom-rect.top;


	// TODO:  在此添加额外的初始化
	pTD->Create(IDD_CHANGECODE, this); //创建一个非模态对话框
	//根据获得主对话框上图片控件的尺寸,将子对话框嵌入到主对话框中
	CRect r;
	GetDlgItem(IDC_STATIC_PIC)->GetWindowRect(r);
	ScreenToClient(r);
	/*这里可以把图形控件销毁了,否则子对话框将不会响应你的鼠标消息*/
	GetDlgItem(IDC_STATIC_PIC)->DestroyWindow();
	// 定位属性页
	pTD->MoveWindow(r);
	//根据所要显示的控件进行对话框的消隐工作
	pTD->ShowWindow(SW_HIDE); //显示非模态对话框

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CMainView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CRect rc;
        GetClientRect(&rc);
        CDC dcMem;
        dcMem.CreateCompatibleDC(&dc);
        CBitmap bmpBackground;
        bmpBackground.LoadBitmap(IDB_BITMAP3);

        BITMAP bitmap;
        bmpBackground.GetBitmap(&bitmap);
        CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
        dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}


HBRUSH CMainView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(nCtlColor == CTLCOLOR_DLG) 
	{ 
		pDC->SetBkMode(TRANSPARENT);//设置背景透明 
		pDC->SetTextColor(RGB(0,0,0));//设置字体为黄色 
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CMainView::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (nType==SIZE_RESTORED||nType==SIZE_MAXIMIZED)  
    {  
        ReSize();  
    }
}

void CMainView::ReSize()
{
	float fsp[2];
	POINT Newp; //获取现在对话框的大小
	CRect recta;    
	GetClientRect(&recta);     //取客户区大小  
	Newp.x=recta.right-recta.left;
	Newp.y=recta.bottom-recta.top;
	fsp[0]=(float)Newp.x/old.x;
	fsp[1]=(float)Newp.y/old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint,TLPoint; //左上角
	CPoint OldBRPoint,BRPoint; //右下角
	HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //列出所有控件  
	while(hwndChild)    
	{    
		woc=::GetDlgCtrlID(hwndChild);//取得ID
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
