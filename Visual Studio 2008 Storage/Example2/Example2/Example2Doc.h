// Example2Doc.h : CExample2Doc ��Ľӿ�
//


#pragma once


class CExample2Doc : public CDocument
{
protected: // �������л�����
	CExample2Doc();
	DECLARE_DYNCREATE(CExample2Doc)

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
	virtual ~CExample2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


