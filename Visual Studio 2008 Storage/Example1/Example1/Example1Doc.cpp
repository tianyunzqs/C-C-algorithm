// Example1Doc.cpp : CExample1Doc ���ʵ��
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


// CExample1Doc ����/����

CExample1Doc::CExample1Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CExample1Doc::~CExample1Doc()
{
}

BOOL CExample1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExample1Doc ���л�

void CExample1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CExample1Doc ���

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


// CExample1Doc ����
