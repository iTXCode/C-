//#include<iostream>
//
//using namespace std;
//
//int main(){
//	int *p = (int *)malloc(sizeof(int));
//	cout << (&p) << endl;
//	cout << sizeof(p) << endl;
//	free(p);
//
//	void *p1 = (void*)malloc(sizeof(0xfffff));
//	cout << (&p1) << endl;
//	cout << sizeof(p1) << endl;
//	//ָ��p1ָ����Ƕ�̬����Ŀռ���׵�ַ����СΪ4�ֽ�
//	free(p1);
//	
//	void *p2 = NULL;
//	p2 = (void*)malloc(sizeof(int));
//	cout << sizeof(p2) << endl;
//	cout << &p2 << endl;
//	return 0;
//}