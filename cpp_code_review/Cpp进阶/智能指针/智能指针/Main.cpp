#if 0
#include<iostream>
#include <vector>
using namespace std;

template <class T>

class SmartPtr{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{

	}
	~SmartPtr(){
		if (_ptr){
			delete _ptr;
			_ptr = nullptr;
			cout << "~SmartPtr()" << endl;
		}
	}
private:
	T* _ptr;
};


//归并排序
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right) return;
	int mid = left + ((right - left) >> 1);
	// [left, mid]
	// [mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = new int;
	SmartPtr<int> sp(tmp);
	//_MergeSort(a, 0, n - 1, tmp);
	// 这里假设处理了一些其他逻辑
	vector<int> v(1000000000, 10);
	// ...
	// free(tmp);
	cout << "delete tmp" << endl;
	delete tmp;
}

int main(){
	int a[5] = { 0, 1, 2, 3, 4};
	try{
		MergeSort(a, 5);
	}
	catch (exception &e){
		cout << e.what() << endl;
	}
	catch (...){
		cout << "Unkonw error!" << endl;
	}
	return 0;
}

#endif


#if 0
#include<iostream>
#include<memory>
using namespace std;
template <class T>

class SmartPtr{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{

	}
	~SmartPtr(){
		if (_ptr){
			delete _ptr;
			_ptr = nullptr;
			cout << "~SmartPtr()" << endl;
		}
	}
	T& operator *(){
		return *_ptr;
	}
	T* operator ->(){
		return _ptr;
	}
private:
	T* _ptr;
};

struct Date{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};

int main(){
	//int *pa = new int(1);
	//SmartPtr<int> sp(pa);
	//*pa=8;
	SmartPtr<int> sp(new int(1));
	*sp = 10;//像指针一样使用,和pa指向同一片空间
	
	SmartPtr<Date> spd(new Date);
	spd->_year = 1998;
	spd->_month = 1;
	spd->_day = 28;
	

	SmartPtr<Date> spd2 = spd;
	//调用拷贝构造(浅拷贝)
	spd2->_year = 1997;
	//继续往后调试程序奔溃,原因为资源的二次释放(需要进行深拷贝)
	return 0;
}
////智能指针：要像指针一样使用
#endif


#if 0
//auto_ptr的使用
#include<iostream>
#include<memory>
using namespace std;

struct Date{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};

int main(){
	auto_ptr<Date> d1(new Date);
	//d1里面是空的，调试看看
	auto_ptr<Date> d2 = d1;
	//此处d2指向这片空间(d1中的_ptr没有了)，而d1为空
	d2->_year = 1997;
	(*d2)._year = 1998;
	return 0;
	//程序结束的时候,调用一次析构函数
	//原因为此时只有智能指针d2指向这片空间，d1被架空
}

#endif

#if 0
//auto_ptr的实现



#include<iostream>
#include<memory>
using namespace std;
struct Date{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};
template <class T>
class Autoptr{
public:
	Autoptr(T* ptr)
		:_ptr(ptr)
	{

	}
	//管理权转移 ,解决二次释放的问题
	Autoptr(Autoptr<T> & ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
		//之前的对象已经被置空
	}

	~Autoptr(){
		if (_ptr){
			delete _ptr;
			_ptr = nullptr;

		}
	}
	T& operator * (){
		return *_ptr;
	}

	T* operator ->(){
		return _ptr;
	}
private:
	T* _ptr;
};


int main(){
	Autoptr<Date> d1(new Date);
	//管理权转移,指针悬空,c++98:auto_ptr 禁止使用
	Autoptr<Date> d2 = d1;
	d2->_year= 1997;
	(*d2)._year = 1998;
	return 0;	
}
//
//
////auto_ptr问题是拷贝的啥时候出现将指针悬空的问题

#endif

#if 0
//unique_ptr的使用
#include<iostream>
#include<memory>

using namespace std;

struct Date{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};

int main(){
	unique_ptr<int>  uq(new int);
	*uq = 10;

	unique_ptr<Date> uq1(new Date);
	unique_ptr<Date> uq2 = uq1;
	unique_ptr<Date> uq3 (uq1);
	return 0;
}
#endif


#if 0
//为了解决auto_ptr的拷贝问题,引入了unique_ptr
#include<iostream>

using namespace std;

struct Date{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};

template <class T>
class UniquePtr{
public:
	UniquePtr(T* ptr)
		:_ptr(ptr)
	{

	}


	~UniquePtr()
	{
		if (_ptr){
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator* (){
		return *_ptr;
	}

	T* operator->(){
		return _ptr;
	}
private:
	//防拷贝:两种方式都可以
	UniquePtr(const UniquePtr<T>& up);
	UniquePtr<T>& operator=(const UniquePtr<T> &up);

	//UniquePtr(const UniquePtr<T> up)=delete;
	//UniquePtr<T>& operator=(const UniquePtr<T> &up)=delete;
	T* _ptr;
};

int main(){
	UniquePtr<Date> up(new Date);
	//不可拷贝，不可赋值
	//UniquePtr<Date> upcopy(up);//错误的拷贝方式(不可以拷贝)
	up->_year = 1990;
	return 0;
}
//靠谱
//实现了RAII +指针
//缺点：不能拷贝，不能赋值

#endif

#if 0
//解决了拷贝和赋值的问题
#include<iostream>
#include<memory>

using namespace std;
struct Date{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};


int main(){
	//shared_ptr可拷贝，可复制
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> spcopy(sp);
	shared_ptr<Date> sp2(new Date);
	sp2 = sp;
	cout << sp.use_count() << endl;
	//引用计数:记录管理的指针;
	return 0;
}
#endif

#if  0
//解决了拷贝和赋值的问题
#include<iostream>
#include<memory>

using namespace std;
struct Date{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};


int main(){
	/*
	非法的使用方式：
	Date* pd=new Date;
	shared_ptr<Date> sp(pd);
	shared_ptr<Date> spcopy(pd);
	//这样的使用方式导致同一片资源释放了两次，会使程序奔溃
	*/
	//shared_ptr可拷贝，可复制
	shared_ptr<Date> sp(new Date);//资源申请马上初始化
	shared_ptr<Date> spcopy(sp);
	spcopy = sp;
    //spcopy和sp管理同一片空间
	shared_ptr<Date> sp2(new Date);
	shared_ptr<Date> sp2copy(sp2);
	//sp2和sp2copy管理同一片空间
	cout << sp.use_count() << endl;
	//引用计数:记录管理的指针;
	cout << sp2.use_count() << endl;

	return 0;
}
#endif


#if 0

//模拟实现shared_ptr
#include<iostream>

using namespace std;

struct Date
{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};

template <class T>


class SharedPtr{
public:
	//构造函数在第一次申请资源后调用
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _useCount(new int(1))//第一次申请资源的时候指向这片资源的指针个数为1
	{}

	//拷贝构造的使用
	
	SharedPtr(const SharedPtr<T> & sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
	{
		//当前指向资源的引用计数+1;
		++(*_useCount);
	}
	//赋值运算符重载
	SharedPtr<T> &operator=(const SharedPtr<T> & sp)
	{
		//对于两个智能指针管理同一片空间的情况,不需要赋值
		if (_ptr != sp._ptr){//检查是否为自己给自己赋值
			if (--(*_useCount) == 0)
				//检查是否是最后的一个指针指向这片空间
			{
				delete _ptr;
				delete _useCount;
				//若是最后一个指针则将这片空间释放并且将计数器指针也释放掉
			}
			_ptr = sp._ptr;
			_useCount = sp._useCount;
			++(*_useCount);
		}
		return *this;
	}


	//析构函数的使用 
	~SharedPtr()
	{
		if (--(*_useCount)==0){
			delete _ptr;
			delete _useCount;
			_ptr = nullptr;
			_useCount = nullptr;
		}
		
	}
	T& operator*(){
		return *_ptr;
	}

	T* operator ->(){
		return _ptr;
	}

	int useCount(){
		return *_useCount;
	}
private:
	T* _ptr;
	int* _useCount;
};



int main(){
	//Date* dt = new Date;
	SharedPtr<Date> sp(new Date);
	SharedPtr<Date> spcopy(sp);
	SharedPtr<Date> sp2(new Date);
	sp2 = sp;
	return 0;
}

#endif


#if 0
//shared_ptr与线程安全的问题
#include<iostream>
#include<thread>
#include<mutex>//互斥锁
using namespace std;

struct Date
{
	int _year = 1997;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};

template <class T>


class SharedPtr{
public:
	//构造函数在第一次申请资源后调用
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _useCount(new int(1))//第一次申请资源的时候指向这片资源的指针个数为1
	{}

	//拷贝构造的使用

	SharedPtr(const SharedPtr<T> & sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
	{
		//当前指向资源的引用计数+1;
		++(*_useCount);
	}
	//赋值运算符重载
	SharedPtr<T> &operator=(const SharedPtr<T> & sp)
	{
		//对于两个智能指针管理同一片空间的情况,不需要赋值
		if (_ptr != sp._ptr){//检查是否为自己给自己赋值
			if (--(*_useCount) == 0)
				//检查是否是最后的一个指针指向这片空间
			{
				delete _ptr;
				delete _useCount;
				//若是最后一个指针则将这片空间释放并且将计数器指针也释放掉
			}
			_ptr = sp._ptr;
			_useCount = sp._useCount;
			++(*_useCount);
		}
		return *this;
	}


	//析构函数的使用 
	~SharedPtr()
	{
		if (--(*_useCount) == 0){
			delete _ptr;
			delete _useCount;
			_ptr = nullptr;
			_useCount = nullptr;
		}

	}
	T& operator*(){
		return *_ptr;
	}

	T* operator ->(){
		return _ptr;
	}

	int useCount(){
		return *_useCount;
	}
private:
	T* _ptr;
	int* _useCount;
};

void Test(const SharedPtr<Date> &sp,int n){
	for (int i = 0; i < n; i++)
		SharedPtr<Date> spcopy(sp);
}

int main(){
	//Date* dt = new Date;
	SharedPtr<Date> sp(new Date);
	int n = 100000;
	thread t1(Test, sp, n);
	thread t2(Test, sp, n);
	t1.join();
	t2.join();
	cout << sp.useCount() << endl;
	return 0;
}
#endif


#if 0
//shared_ptr与线程安全的问题
//加入互斥锁来保证线程的安全
#include<iostream>
#include<thread>
#include<mutex>//互斥锁
using namespace std;

mutex mtx;
struct Date
{
	int _year = 1;
	int _month = 8;
	int _day = 1;
	~Date(){
		cout << "~Date()" << endl;
	}
};

template <class T>


class SharedPtr{
public:
	//构造函数在第一次申请资源后调用
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _useCount(new int(1))//第一次申请资源的时候指向这片资源的指针个数为1
		, _mtx(new mutex)//空间与创建的锁对应起来
	{}

	//拷贝构造的使用

	SharedPtr(const SharedPtr<T> & sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
		, _mtx(sp._mtx)
	{
		//当前指向资源的引用计数+1;
		addRef();
	}
	//赋值运算符重载
	SharedPtr<T> &operator=(const SharedPtr<T> & sp)
	{
		//对于两个智能指针管理同一片空间的情况,不需要赋值
		if (_ptr != sp._ptr){//检查是否为自己给自己赋值
			if (subRef() == 0)
				//检查是否是最后的一个指针指向这片空间
			{
				delete _ptr;
				delete _useCount;
				//若是最后一个指针则将这片空间释放并且将计数器指针也释放掉
				delete _mtx;
			}
			_ptr = sp._ptr;
			_useCount = sp._useCount;
			_mtx = sp._mtx;
			addRef();
		}
		return *this;
	}

	int addRef(){
		_mtx->lock();
		++(*_useCount);
		_mtx->unlock();
		return *_useCount;
	}
	int subRef(){
		_mtx->lock();
		--(*_useCount);
		_mtx->unlock();
		return *_useCount;
	}

	//析构函数的使用 
	~SharedPtr()
	{
		if (subRef() == 0){
			delete _ptr;
			delete _useCount;
			delete _mtx;
			_mtx = nullptr;
			_ptr = nullptr;
			_useCount = nullptr;
		}

	}
	T& operator*(){
		return *_ptr;
	}

	T* operator ->(){
		return _ptr;
	}

	int useCount(){
		return *_useCount;
	}
private:
	T* _ptr;
	int* _useCount;
	mutex* _mtx;
};

void Test( SharedPtr<Date> &sp, int n){
	for (int i = 0; i < n; i++){
		//智能指针本身是线程安全的，但是管理的资源不一定线程安全
		//需要资源的使用者保证线程安全
		SharedPtr<Date> spcopy(sp);
		mtx.lock();
		sp->_year++;
		mtx.unlock();
	}
		
}

int main(){
	//Date* dt = new Date;
	SharedPtr<Date> sp(new Date);
	int n = 100000;
	thread t1(Test, sp, n);
	thread t2(Test, sp, n);
	t1.join();
	t2.join();
	cout << sp.useCount() << endl;
	cout << sp->_year << endl;
	return 0;
}
#endif


#if 0
//shared_ptr 的循环引用
#include<iostream>
#include<memory>

using namespace std;

struct ListNode
{
	int _data;
	shared_ptr<ListNode> _prev;
	shared_ptr<ListNode> _next;
	~ListNode(){ cout << "~ListNode()" << endl; }
};

int main(){
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	return 0;
}
#endif

#if 0
//shared_ptr 析构的使用
#include<iostream>
#include<memory>

using namespace std;

struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	~ListNode(){ cout << "~ListNode()" << endl; }
	//换成weak_ptr即可调用ListNode 的析构函数
};

int main(){
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	return 0;
}
#endif



#if 0
//仿函数的使用
#include<iostream>
#include<memory>

using namespace std;

struct ListNode
{
	int _data;
	/*shared_ptr<ListNode> _prev;
	shared_ptr<ListNode> _next;*/
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	~ListNode(){ cout << "~ListNode()" << endl; }
	//换成weak_ptr即可调用ListNode 的析构函数
};
struct Date{
	int _year = 1997;
	int _month = 1;
	int _day = 2;
	~Date(){
		cout << "~Date()" << endl;
	}
};

template<class T>
struct Free{
	void operator()(T* ptr){
		cout << "free:"<<ptr << endl;
		free(ptr);
	}
};
template <class T>
struct DeleteArray{
	void operator()(T* ptr){
		cout << "delete[]:" << ptr << endl;
		delete[] ptr;
		ptr = nullptr;
	}
};

int main(){
	Free<Date> FREE;
	DeleteArray<Date> DelArray;
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> sp1((Date*)malloc(sizeof(Date)), FREE);
	shared_ptr<Date> sp2(new Date[10], DelArray);
	return 0;
}
#endif


#if 0
//异常安全的问题
//线程的死锁
#include<iostream>
#include<mutex>
#include<vector>
#include<thread>

using namespace std;

mutex mtx;

void fun(){
	try{
		mtx.lock();
		vector<int> v;
		v.at(10) = 10; //异常，跳转，导致第一个线程未解锁，造成死锁
		mtx.unlock();
	}
	catch (exception & e){
		cout << e.what() << endl;
	}
	cout << "exception dealad" << endl;
}

int main(){
	thread t1(fun);
	thread t2(fun);
	t1.join();
	t2.join();
	return 0;
}

#endif



//异常安全的问题
//线程的死锁
#include<iostream>
#include<mutex>
#include<vector>
#include<thread>

using namespace std;

mutex mtx;

//守卫锁
template <class MTX>
class LockGurad{
public:
	LockGurad(MTX& mtx)
		:_mtx(mtx)
	{
		_mtx.lock();
		//构造的时候加锁
	}
	~LockGurad(){
		_mtx.unlock();
		//析构的时候解锁
	}
	LockGurad(const LockGurad<mutex> &) = delete;
	//防止拷贝
private:
	MTX& _mtx;
};

void fun(){
	try{

		LockGurad<mutex> lg(mtx);
		int i;
		cin >> i;
		if (i > 100)
			return ;
	}
	catch (exception & e){
		cout << e.what() << endl;
	}
	cout << "exception dealad" << endl;
}



int main(){
	thread t1(fun);
	thread t2(fun);
	t1.join();
	t2.join();
	return 0;
}




#if 0
#include<iostream>
#include <thread>
#include <mutex>

using namespace std;
// C++11的库中也有一个lock_guard，下面的LockGuard造轮子其实就是为了学习他的原理
template<class Mutex>
class LockGuard
{
public:
	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{
		_mutex.lock();
	}
	~LockGuard()
	{
		_mutex.unlock();
	}
	LockGuard(const LockGuard<Mutex>& lg) = delete;
private:
	// 注意这里必须使用引用，否则锁的就不是一个互斥量对象
	Mutex& _mutex;
};
mutex mtx;
static int n = 0;
void Func()
{
	for (size_t i = 0; i < 10000; ++i)
	{
		LockGuard<mutex> lock(mtx);
		++n;
	}
}

int main()
{
	int begin = clock();
	thread t1(Func);
	thread t2(Func);
	t1.join();
	t2.join();
	int end = clock();
	cout << n << std::endl;
	cout << "cost time:" << end - begin << endl;
	return 0;
}

#endif
