#pragma once
#include <stdio.h>
#include <tchar.h>

// 使用#import把动态连接库msado15.dll导入Visual C++应用程序，
// 并生成定义ADO库的两个C++头文件：msado15.tlh和ado15.tli。即：
#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")
//添加一个指向Connection对象的指针m_pConnection
//_ConnectionPtr m_pConnection(__uuidof(Connection));


class CSqlOperation
{
public:
	//添加一个指向Connection对象的指针m_pConnection
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	

public:
	CSqlOperation(void);
	~CSqlOperation(void);

	// 数据库连接函数
	_ConnectionPtr ConnectSql();
	// SQL语句执行函数
	_variant_t ExecuteSql(char *SqlCommand);
	// 获取数据库表中数据
	_variant_t GetSqlData(char *sqlC, char *ColName);
	// 数据库关闭函数
	void CloseSql();
};

