// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CREATEDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CREATEDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CREATEDLL_EXPORTS
//#define CREATEDLL_API
#define CREATEDLL_API __declspec(dllexport)
#else
#define CREATEDLL_API __declspec(dllimport)
#endif

extern "C" CREATEDLL_API void printMax2(int&,int&);  
extern "C" CREATEDLL_API void printMax3(int&,int&,int&); 



//// �����Ǵ� CreateDLL.dll ������
//class CREATEDLL_API CCreateDLL {
////class CCreateDLL {
//public:
//	CCreateDLL(void);
//	// TODO: �ڴ�������ķ�����
//	CCreateDLL(int n);
//	virtual ~CCreateDLL();
//	virtual void SetNum(int n){m_nNum = n;};
//	virtual int GetNum(){return m_nNum;};
//private:  
//	int m_nNum;
//};

//extern "C" CREATEDLL_API CCreateDLL* CreateObjectofA(void);
//extern "C" CREATEDLL_API CCreateDLL* CreateObjectofA1(int n);

//typedef CCreateDLL* (__cdecl *PFNCreateA1)(void);  
//typedef CCreateDLL* (*PFNCreateA1)();

//extern CREATEDLL_API int nCreateDLL;
//
//CREATEDLL_API int fnCreateDLL(void);



class CREATEDLL_API TestClass  
{  
public:  
    virtual void VirtualFunction(void);  
      
    void NormalFunction(void);    
};  
  
CREATEDLL_API void func(void);  