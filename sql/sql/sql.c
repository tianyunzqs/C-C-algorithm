#include <stdio.h>   
#include <string.h>   
#include <windows.h>   
#include <sql.h>   
#include <sqlext.h>   
#include <sqltypes.h>   
#include <odbcss.h>   

SQLHENV henv = SQL_NULL_HENV;   
SQLHDBC hdbc1 = SQL_NULL_HDBC;   
SQLHSTMT hstmt1 = SQL_NULL_HSTMT; 

/*
    cpp�ļ�����˵����
    1.���ݿ�����е���ӣ��޸ģ�ɾ������Ҫ������SQL�����
    2.����ֱ��ִ�з�ʽ�Ͳ���Ԥ����ִ�з�ʽ����
*/
int main(){   
    char a[200]="bbb";
    char b[200]="200";
    SQLINTEGER   p;
    RETCODE retcode;   
    UCHAR szDSN[SQL_MAX_DSN_LENGTH+1] = "csql";   
    UCHAR szUID[MAXNAME]              = "sa"; 
    UCHAR szAuthStr[MAXNAME]          = "2502";  

        //ֱ��SQL���
    UCHAR sql[] = "select * from student";
        //Ԥ����SQL���
    UCHAR pre_sql[] = "insert into student values('200215180','����','��',26,'CA')";
    //1.��������Դ
        //����ODBC�������
    retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);   
	// ����ODBC����һ��3.0��׼��Ӧ�ó���  
	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);   
        // �������Ӿ������������
    retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);   
    retcode = SQLConnect(hdbc1, szDSN, (SWORD)strlen(szDSN), szUID, 
		(SWORD)strlen(szUID), szAuthStr,(SWORD)strlen(szAuthStr));
   
	//�ж������Ƿ�ɹ�
    if((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO))   
        printf("����ʧ��!\n");
	else   
	{   
		int set_num = 0;
		SQLINTEGER ID;  
		SQLSMALLINT col_num;  
		SQLCHAR szNo[9], szName[20], szSex[2]; 
		SQLSMALLINT szAge;
		SQLCHAR szDept[20];
		SQLINTEGER cbNO,cbName,cbSex, cbAge, cbDept;  
           
 
        //2.������ִ��һ�������SQL���
        /*
        1.����һ�������(statement handle)
        2.����SQL���
        3.ִ�����
        4.�������
        */
        /*retcode   =   SQLAllocHandle(SQL_HANDLE_STMT,   hdbc1,   &hstmt1); 
		SQLExecDirect (hstmt1,sql,sizeof(sql));*/
		//�õ������������  
		SQLNumResultCols(hstmt1,&col_num);  
		printf("column number is: %d\n",col_num);

		//Ҫ�������еĽ����������������ķ�����  
		while(SQL_NO_DATA_FOUND != SQLFetch(hstmt1)) //�ƶ���꣬һֱ������ĩβ  
		{  
			//�õ���괦ĳ�е�ֵ  
			SQLGetData(hstmt1, 1, SQL_C_CHAR, szNo, 9, &cbNO);  
			SQLGetData(hstmt1, 2, SQL_C_CHAR, szName,20,&cbName);  
			SQLGetData(hstmt1, 3, SQL_C_CHAR, szSex, 4, &cbSex);
			SQLGetData(hstmt1, 4, SQL_C_SHORT, &szAge, 0, &cbAge);  
			SQLGetData(hstmt1, 5, SQL_C_CHAR, szDept, 20, &cbDept);  
			//����ODBCû��MoveNext��MoveLast API����������ȡ���ݼ�����  
			set_num++;  
			printf("%s, %s, %s, %d, %s\n", szNo, szName, szSex, szAge, szDept);  
  
		}  
		printf("the numbers of set is: %d\n",set_num);



        //��һ�ַ�ʽ
        //ֱ��ִ��
        //��Ӳ���
        
        
        //�ڶ��ַ�ʽ
        //�󶨲�����ʽ
         
        // p   =   SQL_NTS;
        ////1Ԥ����
        //SQLPrepare(hstmt1,pre_sql,sizeof(pre_sql)); //�����������������С��ͬ�����������ݿ�����ͬ
        ////2�󶨲���ֵ
        //SQLBindParameter(hstmt1,1,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,200,0,&a,0,&p);
        //SQLBindParameter(hstmt1,2,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,200,0,&b,0,&p);
        ////3 ִ��
        //SQLExecute(hstmt1);
        
        printf("�����ɹ�!\n");
        //�ͷ������
        SQLCloseCursor (hstmt1);
        SQLFreeHandle (SQL_HANDLE_STMT, hstmt1);
    
    }   
    //3.�Ͽ�����Դ
    /*
     1.�Ͽ�������Դ������.
     2.�ͷ����Ӿ��.
     3.�ͷŻ������(���������Ҫ���������������������)
    */
    SQLDisconnect(hdbc1);    
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc1);   
    SQLFreeHandle(SQL_HANDLE_ENV, henv);   
    system("pause");
    return(0);   
} 