#include<iostream>

using namespace std;

int  main(){
	int d = 10;
	 const int * p = &d;
	 int const *t = &d;
	 //��const�����͵��������Ҳ�ʱconst���ε���ָ��ָ���ַ�ڵ�����
	 //��ָ����ָ�ĵ�ַ�ɱ䣬��ַ�ڵ����ݲ��ɸ���
	//*p = 20;//������ʽ�����ǿ��޸ĵ���ֵ
	 //ָ��p��tָ��ͬһƬ�ռ䣬���ߵ�Ч����һ����
	 int i = 10;
	 int *const q = &i;
	 //��const����"*"�Ҳ��ʱʱ��const���ε���ָ����ָ��ĵ�ַ
	 //��ָ����ָ��ĵ�ַ���ɱ䣬���ǵ�ַ�ڵ����ݿɱ�
	 *q = 20;
	return 0;
}