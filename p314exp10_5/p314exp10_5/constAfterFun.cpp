#include <iostream>
#include <string>
using namespace std;
class Student 
{ 
public: 
  Student() {} 
  Student( const string& nm, int sc = 0 ) : name( nm ), score( sc ) {} 
  void set_student( const string& nm, int sc = 0 ) { name = nm; score = sc; } 
  // 函数前面加const是为了避免返回的引用改变private变量值，即设置返回的引用为只读
  // 函数后面加const不能修改类的数据成员，对于const成员函数不能在函数中调用其他不是const的函数
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
  cout << student.get_score() << endl;  // 如果get_score函数后不加const，那么该语句非法
} 

int main() 
{ 
  Student stu( "Wang", 85 ); 
  //stu.get_name() = "Li"; // 如果get_name函数前后都不加const修饰，那么可以通过引用改变name值
  cout<<stu.get_name()<<ends<<stu.get_score()<<endl;
  //output_student( stu ); 
}