
#include<iostream>

using namespace std;
class A{
public:
	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}
	A(const A& a){
		cout << "A(const A&)" << endl;
	}
	~A(){
		cout << "~A()" <<++_b<< endl;
	}

	int Add(int a,int b){
		return a + b;
	}
	static int sum(int a, int b){
		//this->_a = a;
		//提示错误this只能用于非静态变量函数内部
		//既类中的static修饰的函数没有this指针
		return a - b;
	}
private:
	int _a;
	static int _b;
};

int A::_b = 0;
//类的静态变量需要在类外进行初始化

int main(){
	A a(10);
	A b = a;
	cout<<a.Add(10, 20)<<endl;
	cout << a.sum(30, 10) << endl;
	return 0;
}

//【注意】
//实例化对象的顺序与析构的顺序是相反的
//先实例化的对象后进行析构

