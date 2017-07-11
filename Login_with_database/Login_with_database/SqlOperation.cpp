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
}

_variant_t CSqlOperation::ExecuteSql(char *SqlCommand)
{
	_variant_t t;
	m_pConnection->Execute(SqlCommand, &t, 1);//ִ��SQL���
	return t;
}

void CSqlOperation::CloseSql()
{
	m_pConnection->Close(); 
	::CoUninitialize(); //�ͷų���ռ�õ�COM ��Դ 
}