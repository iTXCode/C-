//ֻ���ڶ��ϴ�������
#if 0
#include<iostream>

using namespace std;


class Heap{
	friend void fun1();
public:
	static Heap *getheap(){
		return new Heap;
	}
	Heap(const Heap& hp) = delete;
private:
	Heap(){}
};

void fun1(){
	Heap *hp = Heap::getheap();
	//Heap hp2(*hp);
}
//��ֻ���ڶ��ϴ���������ࡿ
//1.���캯��˽�л�
//2.�ṩ�����ӿ�:�ڶ��ϴ�������
//3.�������޷��������󣬺���������ȥ���ã������ӿڱ���Ϊstatic�ӿ�
//4.��ֹ����
//<1>:��������˽�л���ֻ������ʵ��
//<2>:��������������delete����(c++11����)
int main(){
	Heap *hp = Heap::getheap();
	//Heap hp2(*hp);
	return 0;
}

#endif