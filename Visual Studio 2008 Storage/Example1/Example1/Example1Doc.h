// Example1Doc.h : CExample1Doc ��Ľӿ�
//


#pragma once


class CExample1Doc : public CDocument
{
protected: // �������л�����
	CExample1Doc();
	DECLARE_DYNCREATE(CExample1Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CExample1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


