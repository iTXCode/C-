//#include<iostream>
//#include<assert.h>
//#include<string>
//
//using namespace std;
//
//template<class T>
//
////vector的实现是靠三个指针来完成一些列操作的
//class Vector{
//public:
//	typedef T* iterator;
//	//模板指针(可以接受任意类型的迭代器使用)
//	typedef const T* const_iterator;
//	Vector()
//		:_start(nullptr)
//		, _finish(nullptr)
//		, _endOfStorage(nullptr)
//	{}
//
//	Vector(const Vector<T>& v){
//		//开辟空间
//		T* _start = new T[v.Capacity()];//深拷贝
//		//拷贝内容:深拷贝，不能使用memcpy（）；
//		for (int i = 0; i < v.Size(); i++){
//			_start[i] = v[i];
//		}
//		//更新_finish,_endOfStorage
//		_finish = _start + v.Size();
//		_endOfStorage = _start + v.Capacity();
//	}
//
//	T& operator=(Vector<T> v){
//		Swap(v);
//		//交换了资源和空间 
//		return *this;
//	}
//	~Vector(){
//		if (_start){
//			delete[] _start;
//			_start = _finish = _endOfStorage = nullptr;
//	    //让三个指针指向同一块地方
//		}
//	}
//
//	void Swap(Vector<T> v){
//		swap(_start,v._start);
//		swap(_finish,v._finish);
//		swap(_endOfStorage, v._endOfStorage);
//	}
//	size_t Size()const{
//		return _finish - _start;
//		//两者的差即为该容器中的有效字符个数
//	}
//	size_t Capacity()const{
//		return _endOfStorage - _start;
//		//返回的是整个容量的大小
//	}
//	void PushBack(const T&val){
//		//if (Size() == Capacity())
//		if (_finish == _endOfStorage)
//		{//如果两者相等则说明有效字符个数已经沾满了整个容量。则需要扩容了
//			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
//			Reserve(newc);
//		}
//		*_finish = val;
//		//将val的值加入到有效字符的序列中
//		//更新size(有效字符长度)
//		++_finish;
//	}
//
//	void Reserve(size_t n){
//		//1.拷贝的时候判断原来空间是否为空，为空不需要拷贝
//		//2.拷贝的时候注意深拷贝的问题，不同的类型拷贝的方式不同，直接
//		//调用T类型的赋值运算符重载依次完成拷贝
//		if (n > Capacity()){
//			size_t sz = Size();
//			//申请新的空间
//			T* tmp = new T[n];
//			//检查空间是否为空
//			//if (_start){
//			//浅拷贝
//			//	memcpy(tmp, _start, sizeof(T)*sz);
//			//	//拷贝原有空间的内容
//			//	delete _start;
//			//	//释放原有空间
//			//	//当插入字符串的时候，第三次插入在delete 处程序奔溃
//			//	//释放空间出现二次释放的问题
//			//}
//
//			if (_start){
//				//深拷贝，调用T类型的赋值运算符重载完成拷贝
//				for (int i = 0; i < sz; i++){
//					tmp[i] = _start[i];
//				}
//				delete[] _start;
//				//释放原有空间
//				//当插入字符串的时候，第三次插入在delete 处程序奔溃
//				//释放空间出现二次释放的问题
//			}
//			_start = tmp;
//			//更新size;
//			_finish = _start + sz;
//			//更新容量
//			_endOfStorage = _start + n;
//		}
//	}
//	T& operator[](size_t pos){
//		assert(pos < Size());
//		return _start[pos];
//	}
//	const T& operator[](size_t pos)const{
//		assert(pos < Size());
//		return _start[pos];
//	}
//	iterator begin(){
//		return _start;
//	}
//	iterator end(){
//		return _finish;
//	}
//	const_iterator begin() const {
//		return _start;
//	}
//
//	const_iterator end() const{
//		return _finish;
//	}
//
//	//insert,erase 存在迭代器失效的问题
//	//insert：增容的时候迭代器失效
//	//先判断位置的合法性
//	//检查是否需要增容
//	//增容以后要更新迭代器的位置，防止迭代器失效
//	void Insert(iterator pos, const T& val){
//		assert(pos<=_finish&&pos>=_start);
//		size_t len = pos - _start;
//		//计算插入位置到首地址的距离，以便在插入完毕后
//		//确定pos之前的元素，pos 的位置
//		if (_finish == _endOfStorage){
//			size_t newc = (_start == nullptr ? 1 : 2 * Capacity());
//			Reserve(newc);
//		}
//		//增容之后需要更新迭代器
//		pos = _start + len;
//		iterator end = _finish;//记录最后元素的结束位置
//		while (end > pos){
//			*end = *(end - 1);
//			end--;//或者--end;
//		}
//		//在pos位置插入元素
//		*pos = val;
//		//更新_finish
//		++_finish;
//	}
//
//	//Erase：导致迭代器访问越界或者位置访问异常
//	//调用完之后获取Erase的返回值，更新迭代器
//	//检查位置是否合法
//	//直接将pos位置的元素往前移动，覆盖掉pos原来的值
//	//更新_finisd的值
//	iterator Erase(iterator pos){
//		assert(pos >= _start&&pos < _finish);
//		iterator begin = pos + 1;
//		//挪动元素
//		while (begin < _finish){
//			*(begin - 1) = *begin;
//			begin++;
//		}
//		//更新_finish的位置
//		--_finish;
//		return pos;
//	}
//	//Resize
//	void Resize(size_t n,const T& val=T()){
//		if (n<=Size()){
//			_finish = _start + n;
//			//将其有效容量增加
//		}
//		else{
//			if (n > Capacity())
//				Reserve(n);
//			//给增加的空间赋值
//			while (_finish != _start + n){
//				*_finish = val;
//				_finish++;
//			}
//		}
//	}
//private:
//	T* _start;
//	//指向第一个元素的起始位置
//	//eg:int 第一个字节的位置
//	T* _finish;
//	//最后一个位置的结束位置
//	//eg:int 最后一个字节的下一个位置
//	T* _endOfStorage;
//	//已分配好的空间的结束位置
//};
//
//template <class T>
//
//void PrintVector(const Vector<T>& v){
//	for (int i = 0; i < v.Size(); i++){
//		cout << v[i] << " ";
//	}
//	cout << endl;
//}
//template <class T>
//void PrintVectorFor(const Vector<T>& v){
//	for (auto& e:v){
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void testInsertErase(){
//	Vector<int> v;
//	v.PushBack(1);
//	v.PushBack(2);
//	v.PushBack(3);
//	v.PushBack(4);
//	v.Insert(v.end(), 5);
//	PrintVectorFor(v);
//	//删除所有偶数
//	Vector<int>::iterator vit = v.begin();
//	while (vit != v.end()){
//		if (*vit % 2 == 0){
//			vit=v.Erase(vit);
//			//接收Erase函数的返回值，防止迭代器失效
//		}
//		else
//			vit++;
//	}
//		
//	PrintVectorFor(v);
//}
//
//
//void testResize(){
//	Vector<int> v;
//	v.PushBack(1);
//	v.PushBack(2);
//	v.PushBack(3);
//	v.PushBack(4);
//	
//	v.Resize(3);
//	PrintVectorFor(v);
//}
//
//int main(){
//	Vector<int> v;
//	v.PushBack(1);
//	v.PushBack(1);
//	v.PushBack(1);
//	v.PushBack(1);
//	v.PushBack(1);
//	PrintVectorFor(v);
//	Vector<string> v1;
//	v1.PushBack("hello");
//	v1.PushBack(" world!");
//	PrintVectorFor(v1);
//	testInsertErase();
//	testResize();
//	return 0;
//}