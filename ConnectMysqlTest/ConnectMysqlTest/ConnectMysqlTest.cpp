//mysql所需的头文件和库文件  
#include <stdio.h>
#include <winsock.h> 
#include "mysql.h" 

#pragma comment(lib,"libmySQL.lib")
void main()
{
	MYSQL m_sqlCon;
	//连接MySql数据库
	mysql_init(&m_sqlCon);  
	// localhost:服务器 root为账号密码 test为数据库名 3306为端口  
	if(!mysql_real_connect(&m_sqlCon, "localhost","root","2502","zqsdatabase",3306,NULL,0))  
	{  
		printf("数据库连接失败!\n");  
		return;  
	}   
	else
	{
		printf("数据库连接成功！\n");
		return;
	}
	mysql_close(&m_sqlCon);
}