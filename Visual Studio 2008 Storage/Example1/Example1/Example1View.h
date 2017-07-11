// Example1View.h : CExample1View 类的接口
//


#pragma once
#include "afxwin.h"


class CExample1View : public CView
{
protected: // 仅从序列化创建
	CExample1View();
	DECLARE_DYNCREATE(CExample1View)

// 属性
public:
	CExample1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CExample1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	// 保持文件名
	CString strFileName;
	CString strPathName;
	afx_msg void OnHorrial();
	BITMAP bmpProperties;
	HBITMAP bmpHandle;
	CBitmap bmpPicture;
	CBitmap bmpFromHandle;
};

#ifndef _DEBUG  // Example1View.cpp 中的调试版本
inline CExample1Doc* CExample1View::GetDocument() const
   { return reinterpret_cast<CExample1Doc*>(m_pDocument); }
#endif

