#pragma once
#include <stdio.h>
#include <tchar.h>

// ʹ��#import�Ѷ�̬���ӿ�msado15.dll����Visual C++Ӧ�ó���
// �����ɶ���ADO�������C++ͷ�ļ���msado15.tlh��ado15.tli������
#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")
//���һ��ָ��Connection�����ָ��m_pConnection
//_ConnectionPtr m_pConnection(__uuidof(Connection));


class CSqlOperation
{
public:
	//���һ��ָ��Connection�����ָ��m_pConnection
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	

public:
	CSqlOperation(void);
	~CSqlOperation(void);

	// ���ݿ����Ӻ���
	_ConnectionPtr ConnectSql();
	// SQL���ִ�к���
	_variant_t ExecuteSql(char *SqlCommand);
	// ��ȡ���ݿ��������
	_variant_t GetSqlData(char *sqlC, char *ColName);
	// ���ݿ�رպ���
	void CloseSql();
};

