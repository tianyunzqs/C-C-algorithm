#include <iostream>
#include <string>
using namespace std;
class Student 
{ 
public: 
  Student() {} 
  Student( const string& nm, int sc = 0 ) : name( nm ), score( sc ) {} 
  void set_student( const string& nm, int sc = 0 ) { name = nm; score = sc; } 
  // ����ǰ���const��Ϊ�˱��ⷵ�ص����øı�private����ֵ�������÷��ص�����Ϊֻ��
  // ���������const�����޸�������ݳ�Ա������const��Ա���������ں����е�����������const�ĺ���
  const string& get_name() const { return name; } 
  int get_score() const { return score;} 
private: 
  string name; 
  int score; 
}; 

// output student's name and score 
void output_student( const Student& student ) 
{ 
  cout << student.get_name() << "\t"; 
  cout << student.get_score() << endl;  // ���get_score�����󲻼�const����ô�����Ƿ�
} 

int main() 
{ 
  Student stu( "Wang", 85 ); 
  //stu.get_name() = "Li"; // ���get_name����ǰ�󶼲���const���Σ���ô����ͨ�����øı�nameֵ
  cout<<stu.get_name()<<ends<<stu.get_score()<<endl;
  //output_student( stu ); 
}