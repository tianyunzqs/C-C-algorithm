// Example1View.h : CExample1View ��Ľӿ�
//


#pragma once
#include "afxwin.h"


class CExample1View : public CView
{
protected: // �������л�����
	CExample1View();
	DECLARE_DYNCREATE(CExample1View)

// ����
public:
	CExample1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CExample1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	// �����ļ���
	CString strFileName;
	CString strPathName;
	afx_msg void OnHorrial();
	BITMAP bmpProperties;
	HBITMAP bmpHandle;
	CBitmap bmpPicture;
	CBitmap bmpFromHandle;
};

#ifndef _DEBUG  // Example1View.cpp �еĵ��԰汾
inline CExample1Doc* CExample1View::GetDocument() const
   { return reinterpret_cast<CExample1Doc*>(m_pDocument); }
#endif

