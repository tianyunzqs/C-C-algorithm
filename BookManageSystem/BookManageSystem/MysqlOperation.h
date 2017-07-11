#pragma once
#include "mysql.h"

class CMysqlOperation
{
public:
	CMysqlOperation(void);
	~CMysqlOperation(void);

	BOOL CMysqlConnect();
	void CMysqlClose();
	//其实所有的数据库操作都是先写个sql语句，然后用mysql_query(&mysql,query)来完成，包括创建数据库或表，增删改查
	//查询数据
	MYSQL_RES *QueryDatabase(char *query);
	bool UpdateDatabase(char *mysqlcom);

public:
	MYSQL m_sqlCon;
};

