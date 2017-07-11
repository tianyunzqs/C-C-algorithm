// Example2View.h : CExample2View 类的接口
//


#pragma once


class CExample2View : public CView
{
protected: // 仅从序列化创建
	CExample2View();
	DECLARE_DYNCREATE(CExample2View)

// 属性
public:
	CExample2Doc* GetDocument() const;

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
	virtual ~CExample2View();
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
	afx_msg void On32771();
	CString strFileName;
	CString strPathName;
	afx_msg void OnHorrial();
	afx_msg void OnFileNew();
};

#ifndef _DEBUG  // Example2View.cpp 中的调试版本
inline CExample2Doc* CExample2View::GetDocument() const
   { return reinterpret_cast<CExample2Doc*>(m_pDocument); }
#endif

