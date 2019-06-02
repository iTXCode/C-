
#if 0
#include<iostream>

using namespace std;
class Person{
public:
	/*Person(int age)
		:_age(age)
		{

		}*/
	//构造函数不仅可以构造与初始化
	//对象，对于单个单数的构造函数，还具有
	//类型转换的作用
	//【上述构造函数在调试过程中不会报错】

	explicit Person(int age)
		:_age(age)
	{

	}
	//加了explicit关键字之后将会禁止单参构造函数
	//的隐式转换，【上述代码执行会提示错误】
private:
	char _name;
	int _sex;
	double _age;
};

int main(){
	Person p(12);
	//p= 13;
	//对于单参的构造函数，不加关键字explicit相当于发生了隐式类型转换
	//加了关键字explicit之后阻止了隐式类型转换
	return 0;
}
#endif
