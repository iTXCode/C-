#include<iostream>

using namespace std;

//1.�����ռ��п��Զ���������������ṹ�塢��
namespace A{
	int a = 10;  //�����˱���
	void b(){   //���庯��

	}
	struct test_struct {  //�����˽ṹ��

	};
	class Person{   //������

	};
}


//2. �����ռ����Ƕ�������ռ�
namespace A{

	namespace B{   //Ƕ�׵������ռ�
		int a = 10;
	}
}

//�����ռ��ǿ��ŵģ�������ʱ�������������
namespace  A{ 
	//����֮ǰ�������ռ�A �ϲ�
	int c = 10;
}
//5.�����ռ������������
namespace {
	int d = 10;
	int e = 20;
}  //�൱�ڶ�����static int d=10 �� static int e=20;

//6.�����ռ���������

namespace C{
	int a = 520;
}

void test1(){
	namespace D = C;
	cout << "�����ռ�C�µ�a=" << C::a << endl;
	cout << "�����ռ�D�µ�a=" << D::a << endl;
}

//void test(){
//	cout << "�����ռ�A�е�A="<<A::a << endl;
//	cout << "�����ռ�A�е�A="<<A::B::a << endl;
//	cout << A::a << A::c << endl;
//}


int main(){
	test1();
	return 0;
}