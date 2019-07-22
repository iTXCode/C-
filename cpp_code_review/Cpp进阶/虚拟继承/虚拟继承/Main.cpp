#if 0
#include<iostream>

class Person{
public:
	int _id=123;
};

class Student:public Person
{
public:
	char* name="peter";
};
class Teacher : public Person
{
	public:
		char* sex="男";
};

class Assistant:public Teacher,public Student
{
public:
	int age=20;
};

/*
     Person
	 /   \
	/     \
 Student  Teacher
    \      /
	 \    /
	Assistant
	菱形继承的二义性:Assistant类既继承自Student,又继承自Teacher
	当访问Student和Teacher共同的基类Person中的成员是产生二义性
	菱形继承的数据冗余:Assistant类既继承自Student,又继承自Teacher
	则Assistant中就有两份来自Person类中的内容 
*/
void test(){
	Assistant ast;
	std::cout << ast.name << std::endl;
	std::cout << ast.sex << std::endl;
	std::cout << ast.age << std::endl;
	//std::cout << ast._id << std::endl;//提示_id访问不明确
	std::cout <<ast.Student::_id << std::endl;
	std::cout << ast.Teacher::_id << std::endl;
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	
}
int main(){
	Assistant ast;
	test();
	return 0;
}
#endif 


#if 0
#include<iostream>

class Person{
public:
	int _id = 123;
};

class Student :virtual public Person
{
public:
	char* name = "peter";
};
class Teacher :virtual  public Person
{
public:
	char* sex = "男";
};

class Assistant :public Student, public Teacher
{
public:
	int age = 20;
};


void test(){
	Assistant ast;
	std::cout << ast.name << std::endl;
	std::cout << ast.sex << std::endl;
	std::cout << ast.age << std::endl;
	std::cout << ast._id << std::endl;
	//利用虚拟继承解决了访问不明确的问题
	//(菱形继承的二义性和数据冗余问题)
}
int main(){
	Assistant ast;
	test();
	return 0;
}
#endif

