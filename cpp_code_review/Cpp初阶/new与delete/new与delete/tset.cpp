#if 0
#include<iostream>

using namespace std;

class A{
public:
	A(){
		cout << "A(int)" << endl;
	}
	~A(){
		cout << "~A()" << endl;
	}
private:
	int _a;
};


int main(){
	/*A *pa = (A*)malloc(sizeof(A));
	free(pa);*/
	//free ���������������
	
	//A *pb = new A;
	//new������Զ������͹��캯����malloc����
	//new-->operator new -->���캯��
	//delete pb;
	//delete-->����-->operator delete
	 //delete������Զ������͵�����������free���� 
	//A *pc = new A[10];

	//delete[] pc;

	int *p = new int(2);
	//����ռ䲢�ҽ��г�ʼ��
	delete p;
	//���ַ�ʽ�ᱨ��
	//int *p = (int*)operator new(sizeof(int));
	//operator delete(p);
	return 0;
}

//operator new �ײ㣺malloc+�쳣
//operator delete :free

#endif

//���ܽ᡿new/delete:
//�Զ�������:new malloc delete free
// new :operator new--->malloc +����
//malloc:malloc

//new[N]:operator new [N]-->operator new -->malloc +N�ι���

//delete������+operator delete--��free
//free:free

//delete[]:N(����+operator delete --->free)


//�������ͣ�
//new ;malloc+�쳣
//malloc:malloc

//delete:��װfree
//free:free