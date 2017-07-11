#include"matrix.h"
#include<cmath>
  
using namespace std;
  
const double THRESHOLD = 1E-8;
const int ITERATION = 30;   //迭代次数的上限
  
inline int sign(double number)
{
    if (number < 0)
        return -1;
    else
        return 1;
}
  
void orthogonal (Matrix < double >&matrix, int i, int j, bool & pass,Matrix < double >&V)
{
    assert(i<j);
    Matrix<double> Ci=matrix.getColumn(i);
    Matrix<double> Cj=matrix.getColumn(j);
    double ele = ((Ci.getTranspose())*Cj).get(0,0);
    if(fabs(ele)<THRESHOLD)          //i,j两列已经正交
        return;
    int rows=matrix.getRows();
    int columns=matrix.getColumns();    
      
    pass = false;
    double ele1 = ((Ci.getTranspose())*Ci).get(0,0);
    double ele2 = ((Cj.getTranspose())*Cj).get(0,0);
      
    /*只要每次旋转前都把范数大的列放在前面，就可以保证求出的奇异值是递减排序的*/
    if(ele1<ele2){           //如果matrix第i列的范数小于第j列，则交换两列.同时V矩阵也作相应的调换
        for(int row=0;row<rows;++row){
            matrix.put(row,i,Cj.get(row,0));
            matrix.put(row,j,Ci.get(row,0));
        }
        for(int row=0;row<columns;++row){
            double tmp=V.get(row,i);
            V.put(row,i,V.get(row,j));
            V.put(row,j,tmp);
        }
    }
          
    double tao = (ele1 - ele2) / (2 * ele);
    double tan = sign(tao) / (fabs(tao) + sqrt(1 + pow(tao, 2)));
    double cos = 1 / sqrt(1 + pow(tan, 2));
    double sin = cos * tan;
    for(int row=0;row<rows;++row){
        double var1=matrix.get(row,i)*cos+matrix.get(row,j)*sin;
        double var2=matrix.get(row,j)*cos-matrix.get(row,i)*sin;
        matrix.put(row,i,var1);
        matrix.put(row,j,var2);
    }
    for(int col=0;col<columns;++col){
        double var1=V.get(col,i)*cos+V.get(col,j)*sin;
        double var2=V.get(col,j)*cos-V.get(col,i)*sin;
        V.put(col,i,var1);
        V.put(col,j,var2);
    }
}
  
void hestens_jacobi(Matrix < double >&matrix, Matrix < double >&V)
{
    int rows=matrix.getRows();
    int columns=matrix.getColumns();
      
    int iteration = ITERATION;
    while (iteration-- > 0) {
        bool pass = true;
        for (int i = 0; i < columns; ++i) {
            for (int j = i+1; j < columns; ++j) {
                orthogonal(matrix, i, j, pass, V);      //经过多次的迭代正交后，V就求出来了
            }
        }
        if (pass)   //当任意两列都正交时退出迭代
            break;
    }
    cout << "迭代次数：" << ITERATION - iteration << endl;
}
  
int svn(Matrix < double >&matrix, Matrix < double >&S, Matrix < double >&U, Matrix < double >&V)
{
    int rows=matrix.getRows();
    int columns=matrix.getColumns();
    assert(rows<=columns);
      
    hestens_jacobi(matrix,V);
      
    vector<double> E(columns);        //E中存放奇异值
    int none_zero=0;        //记录非0奇异值的个数
    for (int i = 0; i < columns; ++i) {
        double norm=sqrt((matrix.getColumn(i).getTranspose()*(matrix.getColumn(i))).get(0,0));
        if(norm>THRESHOLD){
            none_zero++;
        }
        E[i]=norm;              
    }
      
    /**
    * U矩阵的后(rows-none_zero)列以及V的后(columns-none_zero)列就不计算了，采用默认值0。
    * 对于奇异值分解A=U*Sigma*V^T，我们只需要U的前r列，V^T的前r行（即V的前r列），就可以恢复A了。r是A的秩
    */
    for(int row=0;row<rows;++row){
        S.put(row,row,E[row]);
        for(int col=0;col<none_zero;++col){
            U.put(row,col,matrix.get(row,col)/E[col]);
        }
    }
      
    return none_zero;   //非奇异值的个数亦即矩阵的秩
}
  
int main(int argc, char *argv[])
{
    const int ROW = 3;
    const int COL = 6;
    assert(ROW <= COL);
    double arr[ROW * COL] = {6,5,1,9,8,4,8,5,2,4,6,9,1,2,3,2,1,4};
    Matrix < double >A(ROW, COL);
    A = arr;
  
    Matrix < double >U(ROW, ROW);
    IdentityMatrix < double >V(COL, COL);     //V初始时是一个单位矩阵
    Matrix < double >S(ROW, COL);
    int rank=svn(A,S,U,V);
  
    cout << "U=" << endl << U;
    cout << "SIGMA=" << endl << S;
    cout << "V^T=" << endl << (V.getTranspose());
  
    Matrix < double >A_A = U * S * (V.getTranspose());
    cout << "reset A=" << endl << A_A;
  
    return 0;
}