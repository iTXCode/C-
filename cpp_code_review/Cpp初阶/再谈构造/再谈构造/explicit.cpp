
#if 0
#include<iostream>

using namespace std;
class Person{
public:
	/*Person(int age)
		:_age(age)
		{

		}*/
	//���캯���������Թ������ʼ��
	//���󣬶��ڵ��������Ĺ��캯����������
	//����ת��������
	//���������캯���ڵ��Թ����в��ᱨ��

	explicit Person(int age)
		:_age(age)
	{

	}
	//����explicit�ؼ���֮�󽫻��ֹ���ι��캯��
	//����ʽת��������������ִ�л���ʾ����
private:
	char _name;
	int _sex;
	double _age;
};

int main(){
	Person p(12);
	//p= 13;
	//���ڵ��εĹ��캯�������ӹؼ���explicit�൱�ڷ�������ʽ����ת��
	//���˹ؼ���explicit֮����ֹ����ʽ����ת��
	return 0;
}
#endif
