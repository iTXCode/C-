//
//#if 0
//#include<iostream>
//
////����ģʽ:һ����ֻ��ʵ����һ������
////����ģʽ:
////�ŵ㣺��
////ȱ�㣺���ܻᵼ�½���������������������ģʽͬʱ�������ǵ�����˳����ȷ��
//
//using namespace  std;
//class Singleton{
//public:
//	static Singleton *getInstance(){
//		return &_sin;
//	}
//private:
//	Singleton(){};
//	//��ֹ����
//	//Singleton(const Singleton& s);
//	//����
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//	static Singleton _sin;
//
//	//���캯��˽�л�
//	//��������˽�л�����delete
//};
////ȫ�ֱ���:����������ǰ���Ѿ���������
////����������ڲ�����ʵ�����Լ����͵Ķ���
////���ǿ��Զ���ָ��
////����ʵ������̬�Ķ���
//
//
//Singleton Singleton::_sin;
//
//int main(){
//	Singleton *ps = Singleton::getInstance();
//	//Singleton s(*ps);
//	Singleton *rps = Singleton::getInstance();
//	//���е�*ps��*rpsָ��ͬһƬ�ռ�(��ָ��ͬһ������)
//	return 0;
//}
//#endif
//
//#if 0
//#include<iostream>
//
//using namespace  std;
////����ģʽ
//
//class singleton{
//public:
//	 static singleton *getInstance(){
//		if (_ps == nullptr){
//			_ps = new singleton;
//		}
//		return _ps;
//	}
//
//private:
//	singleton(){};
//	singleton(const singleton &s) = delete;
//	static singleton *_ps;
//};
//
//singleton* singleton::_ps = nullptr;
//int main(){
//	singleton *ps = singleton::getInstance();
//	//��һ�ε��õ�ʱ��Ż�new һ������
//	singleton *rps = singleton::getInstance();
//	//�ڶ��ε��õ�ʱ��ֱ��������
//	return 0;
//}
//#endif
//
//
//#if 0
//#include<iostream>
//#include <thread>
//#include<mutex>
//using namespace  std;
////����ģʽ(�������÷�)
//
//class singleton{
//public:
//	static singleton *getInstance(){
//		if (_ps == nullptr){
//		_mux.lock();
//		if (_ps == nullptr){
//			_ps = new singleton;
//		}
//		_mux.unlock();
//	}
//		
//		return _ps;
//	}
//	//~singleton(){
//	//	if(_ps){
//	//		delete _ps;
//	//		//delete������������������������޵ݹ�
//	//		_ps=nullptr;
//	//	}
//	//}
//
//	~singleton(){
//		cout<<"~singleton"<<endl;
//	}
//   //��Ҫ�����ڲ���
//	class delesingleton{
//	public:
//		~delesingleton(){
//			if(_ps){
//				delete _ps;
//				_ps=nullptr;
//			} 
//		}
//	};
//
//private:
//	singleton(){};
//	singleton(const singleton &s) = delete;
//	static singleton *_ps;
//	static mutex _mux;
//	
//};
//
//void fun(){
//	for (int i = 0; i < 9; i++){
//		cout << i<<"haha" << endl;
//	}
//}
//
//static int j= 0;
//void testSingleton(){
//	cout << singleton::getInstance()<<++j << endl;
//}
//
//mutex singleton::_mux;
//singleton* singleton::_ps = nullptr;
//int main(){
//	singleton *ps = singleton::getInstance();
//	//�ͷŶ����ʱ������������Ҫ���ڲ����н���
//	//ֱ���������������޵ݹ�
//	//��һ�ε��õ�ʱ��Ż�new һ������
//	singleton *rps = singleton::getInstance();
//	//�ڶ��ε��õ�ʱ��ֱ��������
//	
//
//	//fun();
//	//����:һ����һ����ǰһ��ִ�����һ����ִ��
//	//fun();
//
//	//���̲߳���:����һ��ִ�У�����ִ��
//	/*thread t1(fun);
//	thread t2(fun);
//	t1.join();
//	t2.join();*/
//
//	thread t1(testSingleton);
//	thread t2(testSingleton);
//	t1.join();
//	t2.join();
//	//������������ʱ���������̻�����ִ�У��п���ͬ�����
//	//����������黹������ִ�У�����ͬ�����
//	//������˫��黹������ִ�У�����ͬ�����
//	return 0;
//}
//
////�����䡿
////ԭ�Ӳ���(atomic operation)�ǲ���Ҫsynchronized"��
////���Ƕ��̱߳�̵�������̸�ˡ���νԭ�Ӳ�����ָ���ᱻ�̵߳��Ȼ��ƴ�ϵĲ�����
////���ֲ���һ����ʼ����һֱ���е�������
////�м䲻�����κ� context switch ���л�����һ���̣߳�
//
//#endif
//
//
//#if 0
////�ڴ�й©
////����4G�ռ�
//
//#include<iostream>
//
//using namespace std;
//
//int main(){
//	int *p1 = (int*)malloc(sizeof(0x3fffffff));
//	cout << p1 << endl;
//	free(p1);
//	return 0;
//}
//
//#endif