#pragma once
#include "mysql.h"

class CMysqlOperation
{
public:
	CMysqlOperation(void);
	~CMysqlOperation(void);

	BOOL CMysqlConnect();
	void CMysqlClose();
	//��ʵ���е����ݿ����������д��sql��䣬Ȼ����mysql_query(&mysql,query)����ɣ������������ݿ�����ɾ�Ĳ�
	//��ѯ����
	MYSQL_RES *QueryDatabase(char *query);
	bool UpdateDatabase(char *mysqlcom);

public:
	MYSQL m_sqlCon;
};

