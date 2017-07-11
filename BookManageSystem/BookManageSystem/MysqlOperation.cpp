#include "StdAfx.h"
#include "MysqlOperation.h"
#include "mysql.h"
#include <winsock.h> 
#pragma comment(lib,"libmySQL.lib")

CMysqlOperation::CMysqlOperation(void)
{}

CMysqlOperation::~CMysqlOperation(void)
{}

BOOL CMysqlOperation::CMysqlConnect()
{
	//MYSQL m_sqlCon;
	//连接MySql数据库
	mysql_init(&m_sqlCon);  
	// localhost:服务器 root为账号密码 test为数据库名 3306为端口  
	if(!mysql_real_connect(&m_sqlCon, "localhost","root","2502","zqsdatabase",3306,NULL,0))  
	{  
		AfxMessageBox(_T("数据库连接失败!\n"));  
		return FALSE;  
	}   
	return TRUE;
}

void CMysqlOperation::CMysqlClose()
{
	mysql_close(&m_sqlCon);
}

//其实所有的数据库操作都是先写个sql语句，然后用mysql_query(&mysql,query)来完成，包括创建数据库或表，增删改查
//查询数据
MYSQL_RES* CMysqlOperation::QueryDatabase(char *query)
{
	MYSQL_RES *res; //这个结构代表返回行的一个查询结果集
	//mysql_query(&m_sqlCon, "set names utf8"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	//返回0 查询成功，返回1查询失败
	if(mysql_query(&m_sqlCon, query))        //执行SQL语句
	{
		CString ErrorInfo;
		ErrorInfo.Format(_T("Query Failed: %s"), mysql_error(&m_sqlCon));
		AfxMessageBox(ErrorInfo);
		return res;
	}
	//获取结果集
	if (!(res=mysql_store_result(&m_sqlCon)))    // 获得sql语句结束后返回的结果集
	{
		CString ErrorInfo;
		ErrorInfo.Format(_T("Couldn't get result from %s"), mysql_error(&m_sqlCon));
		AfxMessageBox(ErrorInfo);
	}
	return res;
}

//插入数据
bool CMysqlOperation::UpdateDatabase(char *mysqlcom)
{
	if(mysql_query(&m_sqlCon, mysqlcom))        //执行SQL语句
	{
		printf("Update Database failed (%s)\n",mysql_error(&m_sqlCon));
		return false;
	}
	return true;
}