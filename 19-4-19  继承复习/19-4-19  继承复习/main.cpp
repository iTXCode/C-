//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
// 
//class Student : public Person  //�̳���Person ������
//{
//public:
//	
//protected:
//	int _stuid= 4170903; // ѧ��
//};
//
//class Teacher : public Person
//{
//public:
//	
//protected:
//	int _jobid=147632; // ����
//};
//int main(){
//	Person p;
//	Student s;
//	s.Print();
//	Teacher t;
//	t.Print();
//	system("pause");
//	return 0;
//}
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // ����
//private:
//	int _age; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stunum; // ѧ��
//};
//
//int main(){
//	Person p;
//	Student s;
//	p = s;//��Ƭ:���������Ը�ֵ���������
//	s.Print();
//	system("pause");
//	return 0;
//}


// Student��_num��Person��_num�������ع�ϵ��
//���Կ�������������Ȼ���ܣ����Ƿǳ����׻���

//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
  

//int main(){
//	Test();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//class Person
//{
//public:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//public:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//int main(){
//	Person p;
//	Student s;
//	cout << s._num << endl;
//	cout << s.Person::_num << endl;
//	cout << p._num << endl;
//	cout << s.Student::_num << endl;
//	system("pause");
//	return 0;
//}



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
//}
//
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}

//���أ�������ͬ�������򣬺�������ͬ��������ͬ
//�ض��壺�ض���/���أ����ຯ���͸��ຯ������ͬ�ͻṹ������

//
//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	//��ɸ������ĳ�ʼ��������Ĺ��캯���ȵ��û���Ĺ��캯����
//	//��ִ������Ĺ��캯��
//	//�����ȵ��ø���Ĺ��캯���Ϳ���������г�ʼ��
//	Student(const char* name, int num)
//		: Person(name)
//		
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	//������಻��ʾ�ĵ��ø���Ŀ������죬����ø����Ĭ�Ϲ��캯��
//	//���������ʾ�ĵ��ø�����Ŀ������죬�Ͳ�����ȥ���ø����Ĭ�Ϲ���
//	Student(const Student& s) 
//		//(Student *this,const Student &s)��������ָ�����ƭ��
//		: Person(s)//�˴���һ����Ƭ�Ĳ��������ø���Ŀ�������
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//����ĳ�Ա��������ֱ��������ĸ�ֵ��������غ�������ֱ�Ӹ�ֵ
//	//����Ǳ�����Ĭ�����ɵ����ำֵ��������غ���������ø����
//	//��ֵ��������غ������и�ֵ
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			//����ֱ����ʾ���ø���ĸ�ֵ��������غ��������븴��
//			//operator =(s);����������д
//			Person::operator =(s);//�˴����õ�thisָ��Ϊ��������thisָ��
//			_num = s._num;
//		}
//		return *this; //��if��û����ʾ��д������ĸ�ֵ��������صĻ���
//		//�����в�����ø���ĸ�ֵ���������
//	}
//	//��������:��������ʾ���ø������������
//	~Student()
//	{
//		//~Person();��:ͬ�����أ��������ײ��������������������
//		//�޸�Ϊ��ʹ�ö���������
//		//Person::~Person(); //���Ե���
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //ѧ��
//};
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}