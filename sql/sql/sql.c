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
    cpp文件功能说明：
    1.数据库操作中的添加，修改，删除，主要体现在SQL语句上
    2.采用直接执行方式和参数预编译执行方式两种
*/
int main(){   
    char a[200]="bbb";
    char b[200]="200";
    SQLINTEGER   p;
    RETCODE retcode;   
    UCHAR szDSN[SQL_MAX_DSN_LENGTH+1] = "csql";   
    UCHAR szUID[MAXNAME]              = "sa"; 
    UCHAR szAuthStr[MAXNAME]          = "2502";  

        //直接SQL语句
    UCHAR sql[] = "select * from student";
        //预编译SQL语句
    UCHAR pre_sql[] = "insert into student values('200215180','给勇','男',26,'CA')";
    //1.连接数据源
        //分配ODBC环境句柄
    retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);   
	// 告诉ODBC这是一个3.0标准的应用程序  
	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);   
        // 分配连接句柄并建立连接
    retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);   
    retcode = SQLConnect(hdbc1, szDSN, (SWORD)strlen(szDSN), szUID, 
		(SWORD)strlen(szUID), szAuthStr,(SWORD)strlen(szAuthStr));
   
	//判断连接是否成功
    if((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO))   
        printf("连接失败!\n");
	else   
	{   
		int set_num = 0;
		SQLINTEGER ID;  
		SQLSMALLINT col_num;  
		SQLCHAR szNo[9], szName[20], szSex[2]; 
		SQLSMALLINT szAge;
		SQLCHAR szDept[20];
		SQLINTEGER cbNO,cbName,cbSex, cbAge, cbDept;  
           
 
        //2.创建并执行一条或多条SQL语句
        /*
        1.分配一个语句句柄(statement handle)
        2.创建SQL语句
        3.执行语句
        4.销毁语句
        */
        /*retcode   =   SQLAllocHandle(SQL_HANDLE_STMT,   hdbc1,   &hstmt1); 
		SQLExecDirect (hstmt1,sql,sizeof(sql));*/
		//得到结果集中列数  
		SQLNumResultCols(hstmt1,&col_num);  
		printf("column number is: %d\n",col_num);

		//要遍历所有的结果集可以利用下面的方法：  
		while(SQL_NO_DATA_FOUND != SQLFetch(hstmt1)) //移动光标，一直到集合末尾  
		{  
			//得到光标处某列的值  
			SQLGetData(hstmt1, 1, SQL_C_CHAR, szNo, 9, &cbNO);  
			SQLGetData(hstmt1, 2, SQL_C_CHAR, szName,20,&cbName);  
			SQLGetData(hstmt1, 3, SQL_C_CHAR, szSex, 4, &cbSex);
			SQLGetData(hstmt1, 4, SQL_C_SHORT, &szAge, 0, &cbAge);  
			SQLGetData(hstmt1, 5, SQL_C_CHAR, szDept, 20, &cbDept);  
			//有与ODBC没有MoveNext和MoveLast API所以这样获取数据集行数  
			set_num++;  
			printf("%s, %s, %s, %d, %s\n", szNo, szName, szSex, szAge, szDept);  
  
		}  
		printf("the numbers of set is: %d\n",set_num);



        //第一种方式
        //直接执行
        //添加操作
        
        
        //第二种方式
        //绑定参数方式
         
        // p   =   SQL_NTS;
        ////1预编译
        //SQLPrepare(hstmt1,pre_sql,sizeof(pre_sql)); //第三个参数与数组大小相同，而不是数据库列相同
        ////2绑定参数值
        //SQLBindParameter(hstmt1,1,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,200,0,&a,0,&p);
        //SQLBindParameter(hstmt1,2,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,200,0,&b,0,&p);
        ////3 执行
        //SQLExecute(hstmt1);
        
        printf("操作成功!\n");
        //释放语句句柄
        SQLCloseCursor (hstmt1);
        SQLFreeHandle (SQL_HANDLE_STMT, hstmt1);
    
    }   
    //3.断开数据源
    /*
     1.断开与数据源的连接.
     2.释放连接句柄.
     3.释放环境句柄(如果不再需要在这个环境中作更多连接)
    */
    SQLDisconnect(hdbc1);    
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc1);   
    SQLFreeHandle(SQL_HANDLE_ENV, henv);   
    system("pause");
    return(0);   
} 