//mysql�����ͷ�ļ��Ϳ��ļ�  
#include <stdio.h>
#include <winsock.h> 
#include "mysql.h" 

#pragma comment(lib,"libmySQL.lib")
void main()
{
	MYSQL m_sqlCon;
	//����MySql���ݿ�
	mysql_init(&m_sqlCon);  
	// localhost:������ rootΪ�˺����� testΪ���ݿ��� 3306Ϊ�˿�  
	if(!mysql_real_connect(&m_sqlCon, "localhost","root","2502","zqsdatabase",3306,NULL,0))  
	{  
		printf("���ݿ�����ʧ��!\n");  
		return;  
	}   
	else
	{
		printf("���ݿ����ӳɹ���\n");
		return;
	}
	mysql_close(&m_sqlCon);
}