#include<iostream>
//ֻ����ջ�ϴ�������
using namespace std;

class Stack{
public:
	static Stack getStack(){
		return Stack();
	}
private:
	Stack(){

	}
	//���캯��˽�л������ܴ�������ֻ��ͨ�������ķ�ʽȥ����
};


class Stack2{
public:

	//new-->operator new
	void* operator new(size_t n) = delete;
};

int main(){
	Stack s = Stack::getStack();
	Stack s1(s);
	//Stack2 s2 = new Stack2;
	return 0;
}
//���ܽ᡿
//new--->operator new-->����
//һ��
//1.���캯��˽�л��������ֹnew�ؼ��ֵ�ִ���߼�
//2.�ṩ�����ӿڣ��ڶ��ϴ�������
//3.�������޷��������������������ã������ӿڱ�����static�ӿ�

//����
//1.����operator new ����������˽�г�Ա�����Ҳ�ʵ��
//2.���칫��