
//#include<iostream>
////���һ��ֻ���ڶ�������������
//using namespace std;
//
//class HeapOnly{
//	friend void fun();
//public:
//	static HeapOnly* creatHeapOnly(){
//		return new HeapOnly;
//	}
//private:
//	HeapOnly(){
//		cout << "HeapOnly" << endl;
//	}
//	//HeapOnly(const HeapOnly& h) = delete;
//	//���������������Ҳ"��ס"�Ļ������ǿ��Խ����󴴽���ջ��
//	//Ҳ���Խ��������캯��ֻ������ʵ��
//	HeapOnly(const HeapOnly& h); 
//};
//
//void fun(){
//	HeapOnly *h=HeapOnly::creatHeapOnly();
//	//HeapOnly h1(*h);
//	//��������������캯��delete,���ַ�ʽ�Ϳ��Ե��ÿ�������
//}
//int main(){
//	//��ʱ������HeapOnly h�ķ�ʽ���������Ϊ
//	//����Ĺ��캯���Ѿ���˽�л��ˡ�
//	//HeapOnly h1(*h);
//	fun();
//	return 0;
//}
