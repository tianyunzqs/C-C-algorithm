#pragma once
#include <stdio.h>
#include <tchar.h>

// ʹ��#import�Ѷ�̬���ӿ�msado15.dll����Visual C++Ӧ�ó���
// �����ɶ���ADO�������C++ͷ�ļ���msado15.tlh��ado15.tli������
#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")


class CSqlOperation
{
public:
	//���һ��ָ��Connection�����ָ��m_pConnection
	_ConnectionPtr m_pConnection;

public:
	CSqlOperation(void);
	~CSqlOperation(void);

	// ���ݿ����Ӻ���
	void ConnectSql();
	// SQL���ִ�к���
	_variant_t ExecuteSql(char *SqlCommand);
	// ���ݿ�رպ���
	void CloseSql();
};

