//单例模式的饿汉模式的简单实现
//效率比较低
#if 0
#include<iostream>

using namespace std;

class Singleton{
public:
	static Singleton* getSingleton(){
		if (_sin == nullptr){
			_sin = new Singleton;
			//第一次调用时会new一个对象
			//时候的调用会直接return _sin
		}
		return _sin;
	}
private:
	Singleton(){};
	//切记不可以将构造函数delete或者只声明不实现
	Singleton(const Singleton& s) = delete;
	static Singleton *_sin;
};

Singleton* Singleton::_sin = nullptr;
//Singleton* 是_sin的类型(刚开始在初始化的时候直接将类型
//弄成了Singleton所以报错)
int main(){
	Singleton *s = Singleton::getSingleton();
	Singleton *rs = Singleton::getSingleton();
	//两次都指向同一块内存，这也是单例模式的特点
	//而懒汉模式意在第一次创建好对象之后再次创建的
	//对象再次实例化的对象直接将第一次的实例化的对象拿过来用
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
			//添加双锁保证效率，倘若不加这个检查的话
			//当第二次来的时候也会加锁判断之后再解锁
			m_mut.lock();
			if (_sin == nullptr){

				//该层判断的目的在于保证不会对此调用构造函数
				//来多次申请资源
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
	//	//		//delete继续调用析构函数，造成无限递归
	//	//		_ps=nullptr;
	//	//	}
	//	//}
	//不可以通过上面的方式来析构对象，所以只能
	//通过内部类的方式来进对象的析构
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
//注意static的初始化格式


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
