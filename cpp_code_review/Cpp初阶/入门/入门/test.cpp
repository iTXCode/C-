#include<iostream>
#include<stdlib.h>

using  namespace std;

void swap(int *pa, int *pb){
	int temp=*pa;
	*pa = *pb;
	*pb = temp;
	//����������������ԭ����ַ�ռ��е�ֵ��
	//��ԭ�����ж���ı���x,y�ĵ�ַ�ռ��е�ֵ��������
}

//void swap(int &a, int &b){
//	int temp = a;
//	a = b;
//	b = temp;
//   //����������������ԭ����ַ�ռ��е�ֵ��
//   //��ԭ�����ж���ı���x,y�ĵ�ַ�ռ��е�ֵ��������
//}


void  swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	//����������ʱ���������Ŀռ����ֵ
	//��ԭ��ַ�ռ��ڵ�ֵ��û�б����� 
}
int main(){
	int x = 10;
	int y = 20;
	swap(&x, &y);
	swap(x, y);
	system("pause");
	return 0;
}