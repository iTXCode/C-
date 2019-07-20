//
//#if 0
//#include<iostream>
//
////单例模式:一个类只能实例化一个对象
////饿汉模式:
////优点：简单
////缺点：可能会导致进程启动慢，如果多个单利模式同时启动他们的启动顺利不确定
//
//using namespace  std;
//class Singleton{
//public:
//	static Singleton *getInstance(){
//		return &_sin;
//	}
//private:
//	Singleton(){};
//	//防止拷贝
//	//Singleton(const Singleton& s);
//	//或者
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//	static Singleton _sin;
//
//	//构造函数私有化
//	//拷贝构造私有化或者delete
//};
////全局变量:主函数运行前就已经创建好了
////不能在类的内部不能实例化自己类型的对象
////但是可以定义指针
////可以实例化静态的对象
//
//
//Singleton Singleton::_sin;
//
//int main(){
//	Singleton *ps = Singleton::getInstance();
//	//Singleton s(*ps);
//	Singleton *rps = Singleton::getInstance();
//	//其中的*ps与*rps指向同一片空间(既指向同一个对象)
//	return 0;
//}
//#endif
//
//#if 0
//#include<iostream>
//
//using namespace  std;
////懒汉模式
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
//	//第一次调用的时候才会new 一个对象
//	singleton *rps = singleton::getInstance();
//	//第二次调用的时候直接拿来用
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
////懒汉模式(加锁的用法)
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
//	//		//delete继续调用析构函数，造成无限递归
//	//		_ps=nullptr;
//	//	}
//	//}
//
//	~singleton(){
//		cout<<"~singleton"<<endl;
//	}
//   //需要声明内部类
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
//	//释放对象的时候，析构函数需要在内部类中进行
//	//直接析构会引发无限递归
//	//第一次调用的时候才会new 一个对象
//	singleton *rps = singleton::getInstance();
//	//第二次调用的时候直接拿来用
//	
//
//	//fun();
//	//串行:一个等一个，前一个执行完后一个再执行
//	//fun();
//
//	//多线程并行:两个一块执行，抢着执行
//	/*thread t1(fun);
//	thread t2(fun);
//	t1.join();
//	t2.join();*/
//
//	thread t1(testSingleton);
//	thread t2(testSingleton);
//	t1.join();
//	t2.join();
//	//不加锁单检查的时候两个进程会抢着执行，有可能同行输出
//	//加上锁但检查还是抢着执行，可能同行输出
//	//加上锁双检查还是抢着执行，可能同行输出
//	return 0;
//}
//
////【补充】
////原子操作(atomic operation)是不需要synchronized"，
////这是多线程编程的老生常谈了。所谓原子操作是指不会被线程调度机制打断的操作；
////这种操作一旦开始，就一直运行到结束，
////中间不会有任何 context switch （切换到另一个线程）
//
//#endif
//
//
//#if 0
////内存泄漏
////申请4G空间
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