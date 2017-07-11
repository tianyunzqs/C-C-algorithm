// Example2Doc.cpp : CExample2Doc 类的实现
//

#include "stdafx.h"
#include "Example2.h"

#include "Example2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExample2Doc

IMPLEMENT_DYNCREATE(CExample2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExample2Doc, CDocument)
END_MESSAGE_MAP()


// CExample2Doc 构造/析构

CExample2Doc::CExample2Doc()
{
	// TODO: 在此添加一次性构造代码

}

CExample2Doc::~CExample2Doc()
{
}

BOOL CExample2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CExample2Doc 序列化

void CExample2Doc::Serialize(CArchive& ar)
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


// CExample2Doc 诊断

#ifdef _DEBUG
void CExample2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExample2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExample2Doc 命令
