// Example2Doc.cpp : CExample2Doc ���ʵ��
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


// CExample2Doc ����/����

CExample2Doc::CExample2Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CExample2Doc::~CExample2Doc()
{
}

BOOL CExample2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExample2Doc ���л�

void CExample2Doc::Serialize(CArchive& ar)
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


// CExample2Doc ���

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


// CExample2Doc ����
