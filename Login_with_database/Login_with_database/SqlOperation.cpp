#include "StdAfx.h"
#include "SqlOperation.h"


CSqlOperation::CSqlOperation(void)
{
}


CSqlOperation::~CSqlOperation(void)
{
}

void CSqlOperation::ConnectSql(void)
{
	//这里的参数就是上面配置ODBC数据源时的一些配置,uid是用户名，pwd是密码
	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
	::CoInitialize(NULL);//初始化COM库
	
	if(FAILED(m_pConnection.CreateInstance(__uuidof(Connection)))) //创键Connection对象
		printf("创键Connection对象时出错\n");
	try
	{
		m_pConnection->Open(strConnect,"","", adModeUnknown); //连接数据库
	}
	catch(_com_error e) 
	{
		printf("连接数据库时出错\n");
	}
}

_variant_t CSqlOperation::ExecuteSql(char *SqlCommand)
{
	_variant_t t;
	m_pConnection->Execute(SqlCommand, &t, 1);//执行SQL语句
	return t;
}

void CSqlOperation::CloseSql()
{
	m_pConnection->Close(); 
	::CoUninitialize(); //释放程序占用的COM 资源 
}