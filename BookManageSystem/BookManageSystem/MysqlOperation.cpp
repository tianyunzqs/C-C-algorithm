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
	//����MySql���ݿ�
	mysql_init(&m_sqlCon);  
	// localhost:������ rootΪ�˺����� testΪ���ݿ��� 3306Ϊ�˿�  
	if(!mysql_real_connect(&m_sqlCon, "localhost","root","2502","zqsdatabase",3306,NULL,0))  
	{  
		AfxMessageBox(_T("���ݿ�����ʧ��!\n"));  
		return FALSE;  
	}   
	return TRUE;
}

void CMysqlOperation::CMysqlClose()
{
	mysql_close(&m_sqlCon);
}

//��ʵ���е����ݿ����������д��sql��䣬Ȼ����mysql_query(&mysql,query)����ɣ������������ݿ�����ɾ�Ĳ�
//��ѯ����
MYSQL_RES* CMysqlOperation::QueryDatabase(char *query)
{
	MYSQL_RES *res; //����ṹ�������е�һ����ѯ�����
	//mysql_query(&m_sqlCon, "set names utf8"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
	//����0 ��ѯ�ɹ�������1��ѯʧ��
	if(mysql_query(&m_sqlCon, query))        //ִ��SQL���
	{
		CString ErrorInfo;
		ErrorInfo.Format(_T("Query Failed: %s"), mysql_error(&m_sqlCon));
		AfxMessageBox(ErrorInfo);
		return res;
	}
	//��ȡ�����
	if (!(res=mysql_store_result(&m_sqlCon)))    // ���sql�������󷵻صĽ����
	{
		CString ErrorInfo;
		ErrorInfo.Format(_T("Couldn't get result from %s"), mysql_error(&m_sqlCon));
		AfxMessageBox(ErrorInfo);
	}
	return res;
}

//��������
bool CMysqlOperation::UpdateDatabase(char *mysqlcom)
{
	if(mysql_query(&m_sqlCon, mysqlcom))        //ִ��SQL���
	{
		printf("Update Database failed (%s)\n",mysql_error(&m_sqlCon));
		return false;
	}
	return true;
}