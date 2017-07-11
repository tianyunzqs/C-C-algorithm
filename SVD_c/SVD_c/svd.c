#include"mpi.h"
#include"matrix.h"
#include<string.h>
#include<stdlib.h>
#include<math.h>      //gcc�����ʱ����Ҫ��-lmѡ��

#define THREASHOLD 1e-8
#define ITERATION 20
#define  ROW 3  //ÿ������ڵ��ϵľ������3��4��
#define COL 3
#define LINELEN 5*COL       //�����ļ�ÿһ�еĳ���

int sign(double number) {
	if(number<0)
		return -1;
	else
		return 1; 
}

int myRank;     //����������
int procSize;   //���������Ŀ
MPI_Status status;      //�洢״̬����

/*���ļ��ж�ȡ����*/
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
			fprintf(stderr,"�ļ�������С�ھ�����Ҫ������\n");
			exit(1);
		}
		char *seg=strtok(buf,"\t");
		double ele=atof(seg);
		matrix[i][0]=ele;
		for(j=1;j<col;++j){
			if((seg=strtok(NULL,"\t"))==NULL){
				fprintf(stderr,"�ļ�������С�ھ�����Ҫ������\n");
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

/*�Ѿ���д���ļ�*/
void writeToFile(double **matrix,int rows,int columns,char* file){
	FILE *fp;
	if((fp=fopen(file,"w"))==NULL){
		perror("fopen");
		exit(1);
	}
	fprintf(fp,"%d\t%d\n",rows,columns);        //�ļ����м�¼���������������
	int i,j;
	for(i=0;i<rows;++i){
		for(j=0;j<columns;++j){
			fprintf(fp,"%-10f\t",matrix[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

/*������д���ļ�*/
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

/*�����������е���Jacobi�����任*/
void orthogonalVector(double *Ci,double *Cj,int len1,double *Vi,double *Vj,int len2,int *pass){
	double ele=vectorProduct(Ci,Cj,len1);
	if(fabs(ele)<THREASHOLD)
		return;     //��������Ѿ�����������Ҫ���б任���򷵻�true
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

/*��������н��е���Jacobi�����任��V�Ƿ�����/����Ϊcolumns*/
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
	int totalColumn=COL*procSize;       //���ԭ�����ܹ��ж�����

	/*׼�������A��V*/
	char matrixFile[11]={'b','l','o','c','k','X','.','m','a','t','\0'};
	matrixFile[5]='0'+myRank;
	double **A=getMatrix(ROW,COL);
	readFromFile(A,ROW,COL,matrixFile);
	double **V=getMatrix(totalColumn,COL);
	int j;
	for(j=0;j<COL;++j){
		V[COL*myRank+j][j]=1.0;
	}

	/*��ʼ���е���Jacobi��ת����*/
	int iteration=ITERATION;
	while(iteration-->0){
		/*�����ε���������з����Ӵ�С���У�ż���ε���������з�����С��������*/
		int pass=1;
		int allpass=0;
		/*ÿ������ڵ����������н��е���Jacobi�任*/
		int i;
		for(i=1;i<=totalColumn;++i){     //ԭ�����м��о���Ҫ�����ֵĽ���
			int j;
			int send=0,recv=0;  //send��¼�Ƿ�Ҫ�ѱ����������һ�з��͸���һ�������㣻recv��¼�Ƿ�Ҫ����һ�����������һ������
			int mod1=i%2;       //����Ϊ0ʱ�����򣬷���Ϊż��
			int mod2=(myRank*COL)%2;    //�жϱ���ĵ�1��(����)�Ƿ�Ϊԭ����ĵ������У�Ϊ0���ǣ�Ϊ1����
			if(mod1^mod2){      //�ں��������ż������
				j=0;        //���п��Ժ͵ڶ��н��������任
			}
			else{
				j=1;        //������Ҫ����һ������������һ�н��������任
				if(myRank>0){        //���ǵ�1������ڵ�
					recv=1;     //��Ҫ����һ������ڵ�������һ��
				}
			}
			for(++j;j<COL;j+=2){     //��j����j-1�н��е���Jacobi�����任
				orthogonal(A,ROW,COL,j-1,j,&pass,V,totalColumn);
				exchangeColumn(A,ROW,COL,j-1,j);        //�����任֮�󽻻�����
				exchangeColumn(V,totalColumn,COL,j-1,j);
			}
			if(j==COL){     //���һ��ʣ���ˣ��޷���ԣ�����Ҫ���͸���һ������ڵ�
				if(myRank<procSize-1){   //����������1������ڵ�
					send=1;         //��Ҫ�����һ�з�����һ������ڵ�
				}
			}
			if(send){
				//�����һ�з�����һ������ڵ�
				double *lastColumnA=getColumn(A,ROW,COL,COL-1);
				double *lastColumnV=getColumn(V,totalColumn,COL,COL-1);
				MPI_Send(lastColumnA,ROW,MPI_DOUBLE,myRank+1,59,MPI_COMM_WORLD);
				MPI_Send(lastColumnV,totalColumn,MPI_DOUBLE,myRank+1,60,MPI_COMM_WORLD);
				free(lastColumnA);
				free(lastColumnV);
			}
			if(recv){
				//����һ������ڵ�������һ��
				double* preColumnA=(double*)calloc(ROW,sizeof(double));
				double* preColumnV=(double*)calloc(totalColumn,sizeof(double));
				MPI_Recv(preColumnA,ROW,MPI_DOUBLE,myRank-1,59,MPI_COMM_WORLD,&status);
				MPI_Recv(preColumnV,totalColumn,MPI_DOUBLE,myRank-1,60,MPI_COMM_WORLD,&status);
				//������������һ������ڵ�ĩ�н��������任
				double* firstColumnA=getColumn(A,ROW,COL,0);
				double* firstColumnV=getColumn(V,totalColumn,COL,0);
				orthogonalVector(preColumnA,firstColumnA,ROW,preColumnV,firstColumnV,totalColumn,&pass);
				//��preColumn����
				setColumn(A,ROW,COL,0,preColumnA);
				setColumn(V,totalColumn,COL,0,preColumnV);
				//��firstColumn���͸���һ��������
				MPI_Send(firstColumnA,ROW,MPI_DOUBLE,myRank-1,49,MPI_COMM_WORLD);
				MPI_Send(firstColumnV,totalColumn,MPI_DOUBLE,myRank-1,50,MPI_COMM_WORLD);
				free(preColumnA);
				free(preColumnV);
				free(firstColumnA);
				free(firstColumnV);
			}
			if(send){
				//�����һ�з�����һ������ڵ����һ������ڵ������������任���ְ�һ�з��ͻ����ˣ�������Ҫ����
				double* nextColumnA=(double*)calloc(ROW,sizeof(double));
				double* nextColumnV=(double*)calloc(totalColumn,sizeof(double));
				MPI_Recv(nextColumnA,ROW,MPI_DOUBLE,myRank+1,49,MPI_COMM_WORLD,&status);
				MPI_Recv(nextColumnV,totalColumn,MPI_DOUBLE,myRank+1,50,MPI_COMM_WORLD,&status);
				//�ѽ��յ�����һ�и�����������һ��
				setColumn(A,ROW,COL,COL-1,nextColumnA);
				setColumn(V,totalColumn,COL,COL-1,nextColumnV);
				free(nextColumnA);
				free(nextColumnV);
			}
		}
		MPI_Barrier(MPI_COMM_WORLD);        //��������ڵ㶼���һ�ε����󣬻���һ���ǲ������еĶ�pass��
		MPI_Reduce(&pass,&allpass,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		MPI_Bcast(&allpass,1,MPI_INT,0,MPI_COMM_WORLD);         //���Ƿ�allpass��֪���нڵ�
		if(allpass==procSize)
			break;      //�˳�����
	}
	if(myRank==0){
		printf("��������:%d\n",ITERATION-iteration-1);
	}
	char outFileV[7]={'V','X','.','m','a','t','\0'};
	outFileV[1]='0'+myRank;
	writeToFile(V,totalColumn,COL,outFileV);
	normalize(A,ROW,COL);
	freeMatrix(A,ROW);
	freeMatrix(V,totalColumn);
	MPI_Finalize();
}