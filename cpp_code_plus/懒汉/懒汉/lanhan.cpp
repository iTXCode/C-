//����ģʽ�Ķ���ģʽ�ļ�ʵ��
//Ч�ʱȽϵ�
#if 0
#include<iostream>

using namespace std;

class Singleton{
public:
	static Singleton* getSingleton(){
		if (_sin == nullptr){
			_sin = new Singleton;
			//��һ�ε���ʱ��newһ������
			//ʱ��ĵ��û�ֱ��return _sin
		}
		return _sin;
	}
private:
	Singleton(){};
	//�мǲ����Խ����캯��delete����ֻ������ʵ��
	Singleton(const Singleton& s) = delete;
	static Singleton *_sin;
};

Singleton* Singleton::_sin = nullptr;
//Singleton* ��_sin������(�տ�ʼ�ڳ�ʼ����ʱ��ֱ�ӽ�����
//Ū����Singleton���Ա���)
int main(){
	Singleton *s = Singleton::getSingleton();
	Singleton *rs = Singleton::getSingleton();
	//���ζ�ָ��ͬһ���ڴ棬��Ҳ�ǵ���ģʽ���ص�
	//������ģʽ���ڵ�һ�δ����ö���֮���ٴδ�����
	//�����ٴ�ʵ�����Ķ���ֱ�ӽ���һ�ε�ʵ�����Ķ����ù�����
	return 0;
}
#endif



#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class Singleton{
	friend void func();
public:
	static Singleton *getSingleton(){
		if (_sin == nullptr)
		{
			//���˫����֤Ч�ʣ���������������Ļ�
			//���ڶ�������ʱ��Ҳ������ж�֮���ٽ���
			m_mut.lock();
			if (_sin == nullptr){

				//�ò��жϵ�Ŀ�����ڱ�֤����Դ˵��ù��캯��
				//�����������Դ
				_sin = new Singleton();
			}
			m_mut.unlock();
			
		}
		return _sin;
	}
	~Singleton(){
		cout << "~Singleton()" << endl;
	}
	
	//~singleton(){
	//	//	if(_ps){
	//	//		delete _ps;
	//	//		//delete������������������������޵ݹ�
	//	//		_ps=nullptr;
	//	//	}
	//	//}
	//������ͨ������ķ�ʽ��������������ֻ��
	//ͨ���ڲ���ķ�ʽ�������������
	class ClearSingleton{
	public:
		~ClearSingleton(){
			if (_sin){
				delete _sin;
				_sin = nullptr;
				cout << "~ClearSingleton()" << endl;
			}
		}
	};
	static  ClearSingleton clear;
private:
	Singleton(){};
	Singleton(const Singleton& s)=delete;
	Singleton&operator =(Singleton const&) = delete;
	static Singleton* _sin;
	static mutex m_mut;
};

Singleton* Singleton::_sin = nullptr;
Singleton::ClearSingleton clear;
mutex Singleton::m_mut;
//ע��static�ĳ�ʼ����ʽ


void fun(){
	for (int i = 0; i < 9; i++){
		cout << Singleton::getSingleton()<< endl;
	}
}

int main(){
	Singleton *s = Singleton::getSingleton();
	Singleton *s1 = Singleton::getSingleton();
	cout << "s="<<s << endl;
	cout <<"s1="<< s1 << endl;
	thread t1(fun);
	thread t2(fun);
	t1.join();
	t2.join();
	return 0;
}
