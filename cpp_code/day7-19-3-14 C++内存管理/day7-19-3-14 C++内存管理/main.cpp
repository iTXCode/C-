//#include<iostream>
//using namespace std;
//int main(){
//	int *pa = new int;
//	//new Ϊ�ؼ��֣� ��int Ϊ��Ҫ����Ŀռ����� 
//	int *pb = new int(1);
//    //����һ��ռ䣬���ҳ�ʼֵ��Ϊ 1
//	delete pb;
//	//c++�ͷŵ����ռ�ķ�ʽ
//	int *pc = new int[10];
//	//����һ�������Ŀռ䣬�ռ�Ϊ10��int���͵Ŀռ��СΪ 40 �ֽ�
//	delete[]pc;
//	//c++�ͷ������ռ�ķ�ʽ
//	//new/delete     new[]/delete []
//	return 0;
//}




//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//class A{
//private:
//	int _a;
//	int _b;
//};
//int main(){
//	A* pa = (A *)malloc(sizeof(A));
//	free(pa);
//	A *pb = new A;
//	delete pb;
//	A *pc = new A[10];
//	delete[]pc;
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//#include<windows.h>
//using namespace std;
//
//class A{
//public:
//	~A(){
//		//�ͷſռ�
//		//if(_pi){
//		//free(_pi);
//		//_pi=nullptr;
//		//}
//		cout << "~A" << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int *_pi;
//	//���������˿ռ�
//};
//int main(){
//	A* pa = (A *)malloc(sizeof(A));
//	free(pa);
//	A *pb = new A;
//	delete pb;
//	A *pc = new A[10];
//	delete[] pc;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//#include<windows.h>
//using namespace std;
//
//class A{
//public:
//	A(){
//		cout << "A" << endl;
//	}
//
//	~A(){
//		//�ͷſռ�
//		//if(_pi){
//		//free(_pi);
//		//_pi=nullptr;
//		cout << "~A" << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int *_pi;
//	//���������˿ռ�
//};
//int main(){
//	/*A* pa = (A *)malloc(sizeof(A));
//	free(pa);*/
//	A *pb = new A;
//	//new �����Զ������͵Ĺ��캯����malloc����
//	delete pb;
//	//delete �����Զ������͵�����������free���� 
//	/*A *pc = new A[10];
//	delete[] pc;*/
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//int main(){
//	//���ִ����쳣�ķ�ʽ
//	cout << "malloc:" << endl;
//	char *p = (char*)malloc(0x7ffffffff);
//	cout << (void*)p << endl;
//	cout << "new:" << endl;
//	try{
//		char *p = new char[0X7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (exception& e){
//		cout << e.what() << endl;
//		//����ӿڣ�e.what()
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//int main(){
//	//���ִ����쳣�ķ�ʽ
//	cout << "malloc:" << endl;
//	char *p = (char*)malloc(0x7ffffffff);
//	cout << (void*)p << endl;
//	free(p);
//	cout << "new:" << endl;
//	try{
//		char *p = new char[0X7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (exception& e){
//		cout << e.what() << endl;
//		//����ӿڣ�e.what()
//	}
//	//operator new:malloc + �쳣
//	system("pause");
//	return 0;
//}