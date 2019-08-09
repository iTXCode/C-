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


//�鲢����
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
	// ������账����һЩ�����߼�
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
	*sp = 10;//��ָ��һ��ʹ��,��paָ��ͬһƬ�ռ�
	
	SmartPtr<Date> spd(new Date);
	spd->_year = 1998;
	spd->_month = 1;
	spd->_day = 28;
	

	SmartPtr<Date> spd2 = spd;
	//���ÿ�������(ǳ����)
	spd2->_year = 1997;
	//����������Գ�����,ԭ��Ϊ��Դ�Ķ����ͷ�(��Ҫ�������)
	return 0;
}
////����ָ�룺Ҫ��ָ��һ��ʹ��
#endif


#if 0
//auto_ptr��ʹ��
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
	//d1�����ǿյģ����Կ���
	auto_ptr<Date> d2 = d1;
	//�˴�d2ָ����Ƭ�ռ�(d1�е�_ptrû����)����d1Ϊ��
	d2->_year = 1997;
	(*d2)._year = 1998;
	return 0;
	//���������ʱ��,����һ����������
	//ԭ��Ϊ��ʱֻ������ָ��d2ָ����Ƭ�ռ䣬d1���ܿ�
}

#endif

#if 0
//auto_ptr��ʵ��



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
	//����Ȩת�� ,��������ͷŵ�����
	Autoptr(Autoptr<T> & ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
		//֮ǰ�Ķ����Ѿ����ÿ�
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
	//����Ȩת��,ָ������,c++98:auto_ptr ��ֹʹ��
	Autoptr<Date> d2 = d1;
	d2->_year= 1997;
	(*d2)._year = 1998;
	return 0;	
}
//
//
////auto_ptr�����ǿ�����ɶʱ����ֽ�ָ�����յ�����

#endif

#if 0
//unique_ptr��ʹ��
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
//Ϊ�˽��auto_ptr�Ŀ�������,������unique_ptr
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
	//������:���ַ�ʽ������
	UniquePtr(const UniquePtr<T>& up);
	UniquePtr<T>& operator=(const UniquePtr<T> &up);

	//UniquePtr(const UniquePtr<T> up)=delete;
	//UniquePtr<T>& operator=(const UniquePtr<T> &up)=delete;
	T* _ptr;
};

int main(){
	UniquePtr<Date> up(new Date);
	//���ɿ��������ɸ�ֵ
	//UniquePtr<Date> upcopy(up);//����Ŀ�����ʽ(�����Կ���)
	up->_year = 1990;
	return 0;
}
//����
//ʵ����RAII +ָ��
//ȱ�㣺���ܿ��������ܸ�ֵ

#endif

#if 0
//����˿����͸�ֵ������
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
	//shared_ptr�ɿ������ɸ���
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> spcopy(sp);
	shared_ptr<Date> sp2(new Date);
	sp2 = sp;
	cout << sp.use_count() << endl;
	//���ü���:��¼�����ָ��;
	return 0;
}
#endif

#if  0
//����˿����͸�ֵ������
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
	�Ƿ���ʹ�÷�ʽ��
	Date* pd=new Date;
	shared_ptr<Date> sp(pd);
	shared_ptr<Date> spcopy(pd);
	//������ʹ�÷�ʽ����ͬһƬ��Դ�ͷ������Σ���ʹ������
	*/
	//shared_ptr�ɿ������ɸ���
	shared_ptr<Date> sp(new Date);//��Դ�������ϳ�ʼ��
	shared_ptr<Date> spcopy(sp);
	spcopy = sp;
    //spcopy��sp����ͬһƬ�ռ�
	shared_ptr<Date> sp2(new Date);
	shared_ptr<Date> sp2copy(sp2);
	//sp2��sp2copy����ͬһƬ�ռ�
	cout << sp.use_count() << endl;
	//���ü���:��¼�����ָ��;
	cout << sp2.use_count() << endl;

	return 0;
}
#endif


#if 0

//ģ��ʵ��shared_ptr
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
	//���캯���ڵ�һ��������Դ�����
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _useCount(new int(1))//��һ��������Դ��ʱ��ָ����Ƭ��Դ��ָ�����Ϊ1
	{}

	//���������ʹ��
	
	SharedPtr(const SharedPtr<T> & sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
	{
		//��ǰָ����Դ�����ü���+1;
		++(*_useCount);
	}
	//��ֵ���������
	SharedPtr<T> &operator=(const SharedPtr<T> & sp)
	{
		//������������ָ�����ͬһƬ�ռ�����,����Ҫ��ֵ
		if (_ptr != sp._ptr){//����Ƿ�Ϊ�Լ����Լ���ֵ
			if (--(*_useCount) == 0)
				//����Ƿ�������һ��ָ��ָ����Ƭ�ռ�
			{
				delete _ptr;
				delete _useCount;
				//�������һ��ָ������Ƭ�ռ��ͷŲ��ҽ�������ָ��Ҳ�ͷŵ�
			}
			_ptr = sp._ptr;
			_useCount = sp._useCount;
			++(*_useCount);
		}
		return *this;
	}


	//����������ʹ�� 
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
//shared_ptr���̰߳�ȫ������
#include<iostream>
#include<thread>
#include<mutex>//������
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
	//���캯���ڵ�һ��������Դ�����
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _useCount(new int(1))//��һ��������Դ��ʱ��ָ����Ƭ��Դ��ָ�����Ϊ1
	{}

	//���������ʹ��

	SharedPtr(const SharedPtr<T> & sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
	{
		//��ǰָ����Դ�����ü���+1;
		++(*_useCount);
	}
	//��ֵ���������
	SharedPtr<T> &operator=(const SharedPtr<T> & sp)
	{
		//������������ָ�����ͬһƬ�ռ�����,����Ҫ��ֵ
		if (_ptr != sp._ptr){//����Ƿ�Ϊ�Լ����Լ���ֵ
			if (--(*_useCount) == 0)
				//����Ƿ�������һ��ָ��ָ����Ƭ�ռ�
			{
				delete _ptr;
				delete _useCount;
				//�������һ��ָ������Ƭ�ռ��ͷŲ��ҽ�������ָ��Ҳ�ͷŵ�
			}
			_ptr = sp._ptr;
			_useCount = sp._useCount;
			++(*_useCount);
		}
		return *this;
	}


	//����������ʹ�� 
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
//shared_ptr���̰߳�ȫ������
//���뻥��������֤�̵߳İ�ȫ
#include<iostream>
#include<thread>
#include<mutex>//������
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
	//���캯���ڵ�һ��������Դ�����
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _useCount(new int(1))//��һ��������Դ��ʱ��ָ����Ƭ��Դ��ָ�����Ϊ1
		, _mtx(new mutex)//�ռ��봴��������Ӧ����
	{}

	//���������ʹ��

	SharedPtr(const SharedPtr<T> & sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
		, _mtx(sp._mtx)
	{
		//��ǰָ����Դ�����ü���+1;
		addRef();
	}
	//��ֵ���������
	SharedPtr<T> &operator=(const SharedPtr<T> & sp)
	{
		//������������ָ�����ͬһƬ�ռ�����,����Ҫ��ֵ
		if (_ptr != sp._ptr){//����Ƿ�Ϊ�Լ����Լ���ֵ
			if (subRef() == 0)
				//����Ƿ�������һ��ָ��ָ����Ƭ�ռ�
			{
				delete _ptr;
				delete _useCount;
				//�������һ��ָ������Ƭ�ռ��ͷŲ��ҽ�������ָ��Ҳ�ͷŵ�
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

	//����������ʹ�� 
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
		//����ָ�뱾�����̰߳�ȫ�ģ����ǹ������Դ��һ���̰߳�ȫ
		//��Ҫ��Դ��ʹ���߱�֤�̰߳�ȫ
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
//shared_ptr ��ѭ������
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
//shared_ptr ������ʹ��
#include<iostream>
#include<memory>

using namespace std;

struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	~ListNode(){ cout << "~ListNode()" << endl; }
	//����weak_ptr���ɵ���ListNode ����������
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
//�º�����ʹ��
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
	//����weak_ptr���ɵ���ListNode ����������
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
//�쳣��ȫ������
//�̵߳�����
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
		v.at(10) = 10; //�쳣����ת�����µ�һ���߳�δ�������������
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



//�쳣��ȫ������
//�̵߳�����
#include<iostream>
#include<mutex>
#include<vector>
#include<thread>

using namespace std;

mutex mtx;

//������
template <class MTX>
class LockGurad{
public:
	LockGurad(MTX& mtx)
		:_mtx(mtx)
	{
		_mtx.lock();
		//�����ʱ�����
	}
	~LockGurad(){
		_mtx.unlock();
		//������ʱ�����
	}
	LockGurad(const LockGurad<mutex> &) = delete;
	//��ֹ����
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
// C++11�Ŀ���Ҳ��һ��lock_guard�������LockGuard��������ʵ����Ϊ��ѧϰ����ԭ��
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
	// ע���������ʹ�����ã��������ľͲ���һ������������
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
