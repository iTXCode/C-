//#include<iostream>
//
//using namespace std;
//
//class Stack{
//public:
//	static Stack getStack(){
//		return Stack();
//	}
//private:
//	Stack(){
//
//	}
//};
//class stack2{
//	///new --> opeator new-->malloc;
//	void *operator new(size_t n) = delete;
//	//���ڹ����������£����ɲ��ɵ���
//	//�޷�ʹ�ñ�ɾ���ĺ���
//private:
//	void *operator new(size_t n);
//};
//
//
//int main(){
//	//Stack *ps=new Stack;//1.���ռ� 2.����(�Ѿ���delete����)
//	Stack s = Stack::getStack();
//	Stack cp(s);  //cp��ջ��
//	//stack2 ps = new stack2;
//	return 0;
//}
//
////1.���캯��˽�л��������ֹnew �ؼ��ֵ�ִ���߼�
////2.���칫���ӿڣ���ջ�ϴ�������
////3.���������޷��������󣬺������������ã�
////�����ӿڱ���Ϊstatic�ӿ�


#include<iostream>

using namespace std;

class Stack{
public:
	static Stack getStack(){
		return Stack();
	}
	//void *operator new(size_t n) = delete;
	//void operator delete(void *p) = delete;
private:
	Stack(){

	}
	void *operator new(size_t n);
	void operator delete(void *p);
};

int main(){
	Stack stack = Stack::getStack();
	Stack stack1(stack);
	//Stack stack3 = new Stack;
	//��new��·��ɾ��������ֻ������ʵ�֡�
	return 0;
}