#include<iostream>

using namespace std;

#if 0
class BaseInfor{
public:
	char* _name;
protected:
	int _age;
private:
	char* _sex;
};
class Student : public BaseInfor{
private:
	void fun(){
		_name = "jack"; //�����еĹ��г�Ա�����������п��Է���
		_age = 13;  //�����еı�����Ա�����������п��Է���
		//_sex = "��"; //�����е�˽�г�Ա�����������в��ɷ���
	}
protected:
	int _id;
	char* _class_num;
};
//protected:�������޷����ʣ������������ڲ����Է���
//private:����������඼�޷�����
//public�̳�:���ı�����Ա�������еķ���Ȩ��
//protectes�̳У������Ա�������е���ͷ���Ȩ��Ϊprotected
//private�̳�:�����Ա�������е���ͷ���Ȩ��Ϊprivate

int main(){
	
	BaseInfor p;
	Student s;
	p = s;
	//���������Ը����������
	//s = p;
	//������󲻿��Ը����������

	
	Student *P2;
	BaseInfor* p1 = &s;
	//�������ÿ��Ը�ֵ������ָ��
	p1 = (BaseInfor*)&P2; //ǿ������ת��
	return 0;
}

#endif



#if 0
//ͬ������
class Person{
public:
	int _num = 101;
};
class Student:public Person
{
public:
	int _num = 200;
};
int main(){
	Person p;
	Student s;
	cout << p._num << endl;
	cout << s._num << endl;
	cout << s.Person::_num << endl;
	cout << s.Student::_num << endl;
	//������͸���ĳ�Ա����/��Ա����ͬ��ʱ��
	//����Ὣ�����е�ͬ������/�������ص�
	//���������Ҫ�����������޶���
	return 0;
}

#endif 



class A{
public:
	A( char* name="james")
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
	B( char *name = "jack")
		:_name(name)
		,A(name)
	{
		cout <<"B()" << endl;
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
