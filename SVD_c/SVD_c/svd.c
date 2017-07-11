#include"mpi.h"
#include"matrix.h"
#include<string.h>
#include<stdlib.h>
#include<math.h>      //gcc编译的时候需要加-lm选项

#define THREASHOLD 1e-8
#define ITERATION 20
#define  ROW 3  //每个计算节点上的矩阵块有3行4列
#define COL 3
#define LINELEN 5*COL       //矩阵文件每一行的长度

int sign(double number) {
	if(number<0)
		return -1;
	else
		return 1; 
}

int myRank;     //计算结点的序号
int procSize;   //计算结点的数目
MPI_Status status;      //存储状态变量

/*从文件中读取矩阵*/
void readFromFile(double **matrix,int row,int col,char* file){
	FILE *fp;
	int len=col*10;
	char *buf=(char*)calloc(len,sizeof(char));
	if((fp=fopen(file,"r"))==NULL){
		perror("fopen");
		printf("%s\n",file);
		exit(1);
	}
	int i,j;
	for(i=0;i<row;++i){
		if(fgets(buf,len,fp)==NULL){
			fprintf(stderr,"文件的行数小于矩阵需要的行数\n");
			exit(1);
		}
		char *seg=strtok(buf,"\t");
		double ele=atof(seg);
		matrix[i][0]=ele;
		for(j=1;j<col;++j){
			if((seg=strtok(NULL,"\t"))==NULL){
				fprintf(stderr,"文件的列数小于矩阵需要的列数\n");
				exit(1);
			}
			ele=atof(seg);
			matrix[i][j]=ele;
		}
		memset(buf,0x00,len);
	}
	free(buf);
	fclose(fp);
}

/*把矩阵写入文件*/
void writeToFile(double **matrix,int rows,int columns,char* file){
	FILE *fp;
	if((fp=fopen(file,"w"))==NULL){
		perror("fopen");
		exit(1);
	}
	fprintf(fp,"%d\t%d\n",rows,columns);        //文件首行记录矩阵的行数和列数
	int i,j;
	for(i=0;i<rows;++i){
		for(j=0;j<columns;++j){
			fprintf(fp,"%-10f\t",matrix[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

/*把向量写入文件*/
void vectorToFile(double *vector,int len,char* file){
	FILE *fp;
	if((fp=fopen(file,"w"))==NULL){
		perror("fopen");
		exit(1);
	}
	int i;
	for(i=0;i<len;++i){
		fprintf(fp,"%-10f\t",vector[i]);
	}
	fclose(fp);
}

/*两个向量进行单边Jacobi正交变换*/
void orthogonalVector(double *Ci,double *Cj,int len1,double *Vi,double *Vj,int len2,int *pass){
	double ele=vectorProduct(Ci,Cj,len1);
	if(fabs(ele)<THREASHOLD)
		return;     //如果两列已经正交，不需要进行变换，则返回true
	*pass=0;
	double ele1=vectorProduct(Ci,Ci,len1);
	double ele2=vectorProduct(Cj,Cj,len1);



	double tao=(ele1-ele2)/(2*ele);
	double tan=sign(tao)/(fabs(tao)+sqrt(1+pow(tao,2)));
	double cos=1/sqrt(1+pow(tan,2));
	double sin=cos*tan;

	int row;
	for(row=0;row<len1;++row){
		double var1=Ci[row]*cos+Cj[row]*sin;
		double var2=Cj[row]*cos-Ci[row]*sin;

		Ci[row]=var1;
		Cj[row]=var2;

	}
	for(row=0;row<len2;++row){
		double var1=Vi[row]*cos+Vj[row]*sin;
		double var2=Vj[row]*cos-Vi[row]*sin;

		Vi[row]=var1;
		Vj[row]=var2;

	}
}

/*矩阵的两列进行单边Jacobi正交变换。V是方阵，行/列数为columns*/
void orthogonal(double **matrix,int rows,int columns,int i,int j,int *pass,double **V){
	assert(i<j);

	double* Ci=getColumn(matrix,rows,columns,i);
	double* Cj=getColumn(matrix,rows,columns,j);
	double* Vi=getColumn(V,columns,columns,i);
	double* Vj=getColumn(V,columns,columns,j);
	orthogonalVector(Ci,Cj,rows,Vi,Vj,columns,pass);

	int row;
	for(row=0;row<rows;++row){
		matrix[row][i]=Ci[row];
		matrix[row][j]=Cj[row];
	}
	for(row=0;row<columns;++row){
		V[row][i]=Vi[row];
		V[row][j]=Vj[row];
	}
	free(Ci);
	free(Cj);
	free(Vi);
	free(Vj);
}

void normalize(double **A,int rows,int columns){
	double *sigular=(double*)calloc(columns,sizeof(double));
	int i,j;
	for(i=0;i<columns;++i){
		double *vector=getColumn(A,rows,columns,i);
		double norm=sqrt(vectorProduct(vector,vector,rows));
		sigular[i]=norm;
	}
	char outFileS[7]={'S','X','.','m','a','t','\0'};
	outFileS[1]='0'+myRank;
	vectorToFile(sigular,columns,outFileS);
	double **U=getMatrix(rows,columns);
	for(j=0;j<columns;++j){
		if(sigular[j]==0)
			for(i=0;i<rows;++i)
				U[i][j]=0;
		else
			for(i=0;i<rows;++i)
				U[i][j]=A[i][j]/sigular[j];
	}
	char outFileU[7]={'U','X','.','m','a','t','\0'};
	outFileU[1]='0'+myRank;
	writeToFile(U,rows,columns,outFileU);
	free(sigular);
	freeMatrix(U,rows);
}

void main(int argc, char *argv[])
{
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&myRank);
	MPI_Comm_size(MPI_COMM_WORLD,&procSize);

	assert(myRank<10);
	int totalColumn=COL*procSize;       //算出原矩阵总共有多少列

	/*准备矩阵块A和V*/
	char matrixFile[11]={'b','l','o','c','k','X','.','m','a','t','\0'};
	matrixFile[5]='0'+myRank;
	double **A=getMatrix(ROW,COL);
	readFromFile(A,ROW,COL,matrixFile);
	double **V=getMatrix(totalColumn,COL);
	int j;
	for(j=0;j<COL;++j){
		V[COL*myRank+j][j]=1.0;
	}

	/*开始进行单边Jacobi旋转迭代*/
	int iteration=ITERATION;
	while(iteration-->0){
		/*奇数次迭代后矩阵按列范数从大到小排列；偶数次迭代后矩阵按列范数从小到大排列*/
		int pass=1;
		int allpass=0;
		/*每个计算节点上相邻两列进行单边Jacobi变换*/
		int i;
		for(i=1;i<=totalColumn;++i){     //原矩阵有几列就需要做几轮的交换
			int j;
			int send=0,recv=0;  //send记录是否要把本矩阵块的最后一列发送给下一个计算结点；recv记录是否要从上一个计算结点接收一列数据
			int mod1=i%2;       //余数为0时是奇序，否则为偶序
			int mod2=(myRank*COL)%2;    //判断本块的第1列(首列)是否为原矩阵的第奇数列，为0则是，为1则不是
			if(mod1^mod2){      //融合了奇序和偶序的情况
				j=0;        //首列可以和第二列进行正交变换
			}
			else{
				j=1;        //首列需要和上一个计算结点的最后一列进行正交变换
				if(myRank>0){        //不是第1个计算节点
					recv=1;     //需要从上一个计算节点接收最后一列
				}
			}
			for(++j;j<COL;j+=2){     //第j列与j-1列进行单边Jacobi正交变换
				orthogonal(A,ROW,COL,j-1,j,&pass,V,totalColumn);
				exchangeColumn(A,ROW,COL,j-1,j);        //正交变换之后交换两列
				exchangeColumn(V,totalColumn,COL,j-1,j);
			}
			if(j==COL){     //最后一列剩下了，无法配对，它需要发送给下一个计算节点
				if(myRank<procSize-1){   //如果不是最后1个计算节点
					send=1;         //需要把最后一列发给下一个计算节点
				}
			}
			if(send){
				//把最后一列发给下一个计算节点
				double *lastColumnA=getColumn(A,ROW,COL,COL-1);
				double *lastColumnV=getColumn(V,totalColumn,COL,COL-1);
				MPI_Send(lastColumnA,ROW,MPI_DOUBLE,myRank+1,59,MPI_COMM_WORLD);
				MPI_Send(lastColumnV,totalColumn,MPI_DOUBLE,myRank+1,60,MPI_COMM_WORLD);
				free(lastColumnA);
				free(lastColumnV);
			}
			if(recv){
				//从上一个计算节点接收最后一列
				double* preColumnA=(double*)calloc(ROW,sizeof(double));
				double* preColumnV=(double*)calloc(totalColumn,sizeof(double));
				MPI_Recv(preColumnA,ROW,MPI_DOUBLE,myRank-1,59,MPI_COMM_WORLD,&status);
				MPI_Recv(preColumnV,totalColumn,MPI_DOUBLE,myRank-1,60,MPI_COMM_WORLD,&status);
				//本行首列与上一个计算节点末列进行正交变换
				double* firstColumnA=getColumn(A,ROW,COL,0);
				double* firstColumnV=getColumn(V,totalColumn,COL,0);
				orthogonalVector(preColumnA,firstColumnA,ROW,preColumnV,firstColumnV,totalColumn,&pass);
				//把preColumn留下
				setColumn(A,ROW,COL,0,preColumnA);
				setColumn(V,totalColumn,COL,0,preColumnV);
				//把firstColumn发送给上一个计算结点
				MPI_Send(firstColumnA,ROW,MPI_DOUBLE,myRank-1,49,MPI_COMM_WORLD);
				MPI_Send(firstColumnV,totalColumn,MPI_DOUBLE,myRank-1,50,MPI_COMM_WORLD);
				free(preColumnA);
				free(preColumnV);
				free(firstColumnA);
				free(firstColumnV);
			}
			if(send){
				//把最后一列发给下一个计算节点后，下一个计算节点做完了正交变换，又把一列发送回来了，现在需要接收
				double* nextColumnA=(double*)calloc(ROW,sizeof(double));
				double* nextColumnV=(double*)calloc(totalColumn,sizeof(double));
				MPI_Recv(nextColumnA,ROW,MPI_DOUBLE,myRank+1,49,MPI_COMM_WORLD,&status);
				MPI_Recv(nextColumnV,totalColumn,MPI_DOUBLE,myRank+1,50,MPI_COMM_WORLD,&status);
				//把接收到的那一列赋给本块的最后一列
				setColumn(A,ROW,COL,COL-1,nextColumnA);
				setColumn(V,totalColumn,COL,COL-1,nextColumnV);
				free(nextColumnA);
				free(nextColumnV);
			}
		}
		MPI_Barrier(MPI_COMM_WORLD);        //各个计算节点都完成一次迭代后，汇总一上是不是所有的都pass了
		MPI_Reduce(&pass,&allpass,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		MPI_Bcast(&allpass,1,MPI_INT,0,MPI_COMM_WORLD);         //把是否allpass告知所有节点
		if(allpass==procSize)
			break;      //退出迭代
	}
	if(myRank==0){
		printf("迭代次数:%d\n",ITERATION-iteration-1);
	}
	char outFileV[7]={'V','X','.','m','a','t','\0'};
	outFileV[1]='0'+myRank;
	writeToFile(V,totalColumn,COL,outFileV);
	normalize(A,ROW,COL);
	freeMatrix(A,ROW);
	freeMatrix(V,totalColumn);
	MPI_Finalize();
}