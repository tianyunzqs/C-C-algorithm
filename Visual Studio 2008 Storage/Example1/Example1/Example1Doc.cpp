// Example1Doc.cpp : CExample1Doc 类的实现
//

#include "stdafx.h"
#include "Example1.h"

#include "Example1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExample1Doc

IMPLEMENT_DYNCREATE(CExample1Doc, CDocument)

BEGIN_MESSAGE_MAP(CExample1Doc, CDocument)
END_MESSAGE_MAP()


// CExample1Doc 构造/析构

CExample1Doc::CExample1Doc()
{
	// TODO: 在此添加一次性构造代码

}

CExample1Doc::~CExample1Doc()
{
}

BOOL CExample1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CExample1Doc 序列化

void CExample1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CExample1Doc 诊断

#ifdef _DEBUG
void CExample1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExample1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExample1Doc 命令
