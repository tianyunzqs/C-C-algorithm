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
	//����Ĳ���������������ODBC����Դʱ��һЩ����,uid���û�����pwd������
	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
	::CoInitialize(NULL);//��ʼ��COM��
	
	if(FAILED(m_pConnection.CreateInstance(__uuidof(Connection)))) //����Connection����
		printf("����Connection����ʱ����\n");
	try
	{
		m_pConnection->Open(strConnect,"","", adModeUnknown); //�������ݿ�
	}
	catch(_com_error e) 
	{
		printf("�������ݿ�ʱ����\n");
	}
	return m_pConnection;
}

_variant_t CSqlOperation::ExecuteSql(char *SqlCommand)
{
	_variant_t t;
	m_pConnection->Execute(SqlCommand, &t, 1);//ִ��SQL���
	return t;
}

_variant_t CSqlOperation::GetSqlData(char *sqlC, char *ColName)
{
	//ִ��SQL��䣬�õ���¼��, connection�����Ѻ����ݿ�����
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	_ConnectionPtr Connection = ConnectSql();  // Connection�������������ݿ�
    m_pRecordset->Open(sqlC, Connection.GetInterfacePtr(),
		adOpenStatic,adLockOptimistic,adCmdText);
	return m_pRecordset->GetCollect(ColName);
}


void CSqlOperation::CloseSql()
{
	m_pConnection->Close(); 
	::CoUninitialize(); //�ͷų���ռ�õ�COM��Դ 
}