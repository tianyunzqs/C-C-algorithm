//Windows环境下，Visual C++ 6.0连接SQLServer 2005数据库的ADO方法,在VS2008中编写代码如下：

#pragma once


#define WIN32_LEAN_AND_MEAN  // Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>

 
// 使用#import把动态连接库msado15.dll导入Visual C++应用程序，
// 并生成定义ADO库的两个C++头文件：msado15.tlh和ado15.tli。即：


#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")

void main()
{
	// 注意这里使用了删除，而不是选择查找，因为选择查找返回的是一个集合，要用到游标等，比较麻烦，
	// 在这里我只是做一个简单的测试,看是否连接数据库成功。
	char * sqlCommand = "select * from student where sage=200";
	//这里的参数就是上面配置ODBC数据源时的一些配置,uid是用户名，pwd是密码
	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
	::CoInitialize(NULL);//初始化COM库
	//添加一个指向Connection对象的指针m_pConnection
	_ConnectionPtr m_pConnection(__uuidof(Connection));

	if( FAILED( m_pConnection.CreateInstance(__uuidof(Connection)) ) ) //创键Connection对象
		printf("创键Connection对象时出错\n");
	try
	{
		m_pConnection->Open (strConnect,"","", adModeUnknown); //连接数据库
	}
	catch(_com_error e) 
	{
		printf("连接数据库时出错\n");
	}
	_variant_t t;
	m_pConnection->Execute(sqlCommand, &t, 1);//执行SQL语句
	int a = t.iVal;
	m_pConnection->Close(); 
	::CoUninitialize(); //释放程序占用的COM 资源 
}