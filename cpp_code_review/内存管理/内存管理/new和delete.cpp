#include<iostream>

using namespace std;

int main(){
	int *p = new int;
	//ֻ��������һ��int���͵Ŀռ��С
	delete p;
	int *p1 = new int(1);
	//������һ��int���͵Ŀռ��С���ҽ���ʼֵ����Ϊ1
	//int a = new int(2);
	//���ֱ�Ӹ����������ڴ����ʾ
    //int*���͵�ֵ�������ڳ�ʼ��int ���͵�ʵ��
	delete p1;
	int *a = new int(3);
	delete a;
	cout << a << endl;

	//��ΪaΪָ����������������һ����ַ
	return 0;
}