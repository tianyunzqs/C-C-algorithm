#include "StdAfx.h"
#include "SqlOperation.h"


CSqlOperation::CSqlOperation(void)
{
}


CSqlOperation::~CSqlOperation(void)
{
}

_ConnectionPtr CSqlOperation::ConnectSql(void)
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
	return m_pConnection;
}

_variant_t CSqlOperation::ExecuteSql(char *SqlCommand)
{
	_variant_t t;
	m_pConnection->Execute(SqlCommand, &t, 1);//执行SQL语句
	return t;
}

_variant_t CSqlOperation::GetSqlData(char *sqlC, char *ColName)
{
	//执行SQL语句，得到记录集, connection必须已和数据库连接
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	_ConnectionPtr Connection = ConnectSql();  // Connection必须已连接数据库
    m_pRecordset->Open(sqlC, Connection.GetInterfacePtr(),
		adOpenStatic,adLockOptimistic,adCmdText);
	return m_pRecordset->GetCollect(ColName);
}


void CSqlOperation::CloseSql()
{
	m_pConnection->Close(); 
	::CoUninitialize(); //释放程序占用的COM资源 
}