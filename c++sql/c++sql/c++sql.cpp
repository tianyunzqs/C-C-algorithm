//Windows�����£�Visual C++ 6.0����SQLServer 2005���ݿ��ADO����,��VS2008�б�д�������£�

#pragma once


#define WIN32_LEAN_AND_MEAN  // Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>

 
// ʹ��#import�Ѷ�̬���ӿ�msado15.dll����Visual C++Ӧ�ó���
// �����ɶ���ADO�������C++ͷ�ļ���msado15.tlh��ado15.tli������


#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")

void main()
{
	// ע������ʹ����ɾ����������ѡ����ң���Ϊѡ����ҷ��ص���һ�����ϣ�Ҫ�õ��α�ȣ��Ƚ��鷳��
	// ��������ֻ����һ���򵥵Ĳ���,���Ƿ��������ݿ�ɹ���
	char * sqlCommand = "select * from student where sage=200";
	//����Ĳ���������������ODBC����Դʱ��һЩ����,uid���û�����pwd������
	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
	::CoInitialize(NULL);//��ʼ��COM��
	//���һ��ָ��Connection�����ָ��m_pConnection
	_ConnectionPtr m_pConnection(__uuidof(Connection));

	if( FAILED( m_pConnection.CreateInstance(__uuidof(Connection)) ) ) //����Connection����
		printf("����Connection����ʱ����\n");
	try
	{
		m_pConnection->Open (strConnect,"","", adModeUnknown); //�������ݿ�
	}
	catch(_com_error e) 
	{
		printf("�������ݿ�ʱ����\n");
	}
	_variant_t t;
	m_pConnection->Execute(sqlCommand, &t, 1);//ִ��SQL���
	int a = t.iVal;
	m_pConnection->Close(); 
	::CoUninitialize(); //�ͷų���ռ�õ�COM ��Դ 
}