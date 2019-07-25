//#include<iostream>
//#include<string>
//#include<windows.h>
////����������
//using namespace std;
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();//ָ������
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//	//b.fun();//������fun()��������Ϊ�Ѿ���b�е�fun(int)����������
//	//��Ҫ�����������޶���,�������
//	b.A::fun();
//}
//
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}


#if 0
#include<iostream>

using namespace std;

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		std::cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};
class Student : public Person
{
public:
	//��ɸ������ĳ�ʼ��������Ĺ��캯���ȵ��û���Ĺ��캯����
	//��ִ������Ĺ��캯��
	//�����ȵ��ø���Ĺ��캯���Ϳ���������г�ʼ��
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	//������಻��ʾ�ĵ��ø���Ŀ������죬����ø����Ĭ�Ϲ��캯��
	//���������ʾ�ĵ��ø�����Ŀ������죬�Ͳ�����ȥ���ø����Ĭ�Ϲ���
	Student(const Student& s)
		//(Student *this,const Student &s)��������ָ�����ƭ��
		: Person(s)//�˴���һ����Ƭ�Ĳ��������ø���Ŀ�������
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	//����ĳ�Ա��������ֱ��������ĸ�ֵ��������غ�������ֱ�Ӹ�ֵ
	//����Ǳ�����Ĭ�����ɵ����ำֵ��������غ���������ø����
	//��ֵ��������غ������и�ֵ
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			//operator =(s);����������д
			Person::operator =(s);//�˴����õ�thisָ��Ϊ��������thisָ��
			_num = s._num;
		}
		return *this; //��if��û����ʾ��д������ĸ�ֵ��������صĻ���
		//�����в�����ø���ĸ�ֵ���������
	}
	//��������:��������ʾ���ø������������
	~Student()
	{
		//~Person();��:ͬ�����أ��������ײ���������������������޸�Ϊ��ʹ�ö���������
		//�༭����~Student()��~Person()���޸ĳ���~destructor
		//Person::~Person(); //���Ե���
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
};
void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}
int main(){
	Test();
	return 0;
}
//����˳�����ǻ��๹�졪�������������๹�� 
//����˳������������--����������
//ԭ��Ϊ����ջ֡������˳�� 

#endif


#include<iostream>

using namespace std;
class A{
public:
	A(char* name = "james")
		:_name(name)
	{
		cout << _name << endl;
		cout << "A()" << endl;
	}
	A& operator=(const A& a){
		cout << "A& operator=(const A&a)" << endl;
		if (this != &a){
			_name = a._name;
		}
		return *this;
	}
	~A(){
		cout << "~A()" << endl;
	}
	A(const A& a){
		cout << "A(const A&a)" << endl;
	}
private:
	char* _name;
};

//class B:public A{

//};

//�������಻��ʾ��д�����û���Ĺ�������������ʱ
//��������Զ����û���Ĺ������������


class B : public A{
public:
	//����ĳ�Ա����ֱ����������Ĺ���Ϳ���������ֱ�ӳ�ʼ����������ø���
	//�Ĺ���Ϳ���������г�ʼ��

	//�����๹�캯���ȵ��û��๹�캯������ִ�������๹�캯��
	/*B(const char* name="jack")
	:_name(name)
	{

	}*/
	//����Ķ��巽ʽ
	B(char *name = "jack")
		: A(name)
		,_name(name)
		
	{
		std::cout << "B()" << endl;
	}
	~B(){
		cout << "~B" << endl;
	}

	B(const B&b)
		//:A(b)//��ʾ��д�������ȵ��û���Ŀ�������
	{
		cout << "B(const B&b)" << endl;
	}
	//������಻��ʾ���ø���Ŀ������죬����ø����Ĭ�Ͽ�������
	//���������ʾ�ĵ��ø���Ŀ������죬�Ͳ�����ȥ���ø����Ĭ�Ͽ�������

	B& operator=(const B&b)
	{
		cout << "B&operator= (const B&b)" << endl;
		if (this != &b){
			//_name = b._name;
			A::operator=(b);
			//�����˻���ĸ�ֵ��������غ���
		}
		return *this;
	}
	//����ĳ�Ա��������ֱ��������� ��ֵ��������غ�����ֱ�Ӹ�ֵ
	//����Ǳ�����Ĭ�����ɵ������ำֵ��������غ���,
	//����û���ĸ�ֵ��������غ������и�ֵ
private:
	char* _name;
};
void test(){
	B b;
	B c(b);
	B d = c; //��������
	//��������û��д���������ʱ������˻���Ŀ�������
	//����������ʾ��д�����������ʱ����õ���������Ŀ�������
	d = c; //���ø�ֵ���������
	//��������û��д��ֵ��������ص�ʱ������˻���ĸ�ֵ���������
	//����������ʾ��д����ֵ��������ص�ʱ����õ���������ĸ�ֵ���������
}

int main(){
	test();
	return 0;
}