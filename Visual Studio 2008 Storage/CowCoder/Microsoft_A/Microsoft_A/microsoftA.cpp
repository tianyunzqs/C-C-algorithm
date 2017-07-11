#include <iostream>
using namespace std; 
//class A{ 
//public: 
//	virtual void f() { cout << "A::f() "; } 
//	void f() const { cout << "A::f() const "; } // (2)
//}; 
//
//class B : public A { 
//public: 
//	void f() { cout << "B::f() "; } // （1）
//	void f() const { cout << "B::f() const "; } 
//}; 
//
//void g(const A* a) { 
//	a->f(); 
//} 
//
//int main(int argc, char *argv[]) { 
//	A* p = new B(); 
//	p->f(); // 调用（1）
//	g(p);  // 调用（2）
//	delete(p); 
//	return 0; 
//}
//
//
class A{ 
public: 
	long a; 
}; 
class B : public A { 
public: 
	long b; 
}; 
void seta(A* data, int idx) { 
	data[idx].a = 2; 
} 
int main(int argc, char *argv[]) { 
	B data[2]; 
	for(int i=0; i<2; ++i){ 
		data[i].a = 1; 
		data[i].b = 1; 
		seta(data, i); 
	} 
	for(int i=0; i<2; ++i){ 
		std::cout << data[i].a << data[i].b; 
	} 

	//data[0].a = 1; 
	//data[0].b = 1; 
	//seta(data, 0); 
	//std::cout << data[0].a << data[0].b << endl;
	//data[1].a = 1; 
	//data[1].b = 1; 
	//seta(data, 1); 
	//std::cout << data[1].a << data[1].b << endl;
	return 0; 
}