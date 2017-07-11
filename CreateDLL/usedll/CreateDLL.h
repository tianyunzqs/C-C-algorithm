// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CREATEDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CREATEDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef CREATEDLL_EXPORTS
//#define CREATEDLL_API
#define CREATEDLL_API __declspec(dllexport)
#else
#define CREATEDLL_API __declspec(dllimport)
#endif

extern "C" CREATEDLL_API void printMax2(int&,int&);  
extern "C" CREATEDLL_API void printMax3(int&,int&,int&); 



//// 此类是从 CreateDLL.dll 导出的
//class CREATEDLL_API CCreateDLL {
////class CCreateDLL {
//public:
//	CCreateDLL(void);
//	// TODO: 在此添加您的方法。
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