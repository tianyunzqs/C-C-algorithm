#pragma once
#include <stdio.h>
#include <tchar.h>

// 使用#import把动态连接库msado15.dll导入Visual C++应用程序，
// 并生成定义ADO库的两个C++头文件：msado15.tlh和ado15.tli。即：
#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")


class CSqlOperation
{
public:
	//添加一个指向Connection对象的指针m_pConnection
	_ConnectionPtr m_pConnection;

public:
	CSqlOperation(void);
	~CSqlOperation(void);

	// 数据库连接函数
	void ConnectSql();
	// SQL语句执行函数
	_variant_t ExecuteSql(char *SqlCommand);
	// 数据库关闭函数
	void CloseSql();
};

