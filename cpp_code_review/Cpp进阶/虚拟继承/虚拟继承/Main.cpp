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
		char* sex="��";
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
	���μ̳еĶ�����:Assistant��ȼ̳���Student,�ּ̳���Teacher
	������Student��Teacher��ͬ�Ļ���Person�еĳ�Ա�ǲ���������
	���μ̳е���������:Assistant��ȼ̳���Student,�ּ̳���Teacher
	��Assistant�о�����������Person���е����� 
*/
void test(){
	Assistant ast;
	std::cout << ast.name << std::endl;
	std::cout << ast.sex << std::endl;
	std::cout << ast.age << std::endl;
	//std::cout << ast._id << std::endl;//��ʾ_id���ʲ���ȷ
	std::cout <<ast.Student::_id << std::endl;
	std::cout << ast.Teacher::_id << std::endl;
	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	
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
	char* sex = "��";
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
	//��������̳н���˷��ʲ���ȷ������
	//(���μ̳еĶ����Ժ�������������)
}
int main(){
	Assistant ast;
	test();
	return 0;
}
#endif

