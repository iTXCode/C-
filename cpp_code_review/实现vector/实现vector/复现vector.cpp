#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
struct TrueType{

};
struct FalseType{

};

//类型萃取
template<class T>

struct TypeTraits{
	typedef FalseType _isPodType;
};

//特化版本

template<>
struct TypeTraits<int>{
	typedef TrueType _isPodType;
};


template<>
struct TypeTraits<char>{
	typedef TrueType _isPodType;
};

template<>
struct TypeTraits<float>{
	typedef TrueType _isPodType;
};

template<>
struct TypeTraits<double>{
	typedef TrueType _isPodType;
};

//通过最后一个参数不同形成函数重载
template <class T>

void Copy(T* dst, const T *src, size_t sz, TrueType){
	cout << typeid(T).name() << ":memcpy()" << endl;
	memcpy(dst, src, sizeof(T)*sz);
}

template <class T>

//通过最后一个参数不同形成函数重载
void Copy(T* dst, const T *src, size_t sz, FalseType){
	//最后一个参数只给了类型，没给参数名
	cout << typeid(T).name() << ":operator=()" << endl;
	for (int i = 0; i < sz; i++){
		dst[i] = src[i];
	}
}



template <class T>
void Copy(T* dst, const T *src, size_t sz){
	Copy(dst, src, sz, TypeTraits<T>::_isPodType());
}


template <class T>
class Vector{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofStorage(nullptr)
	{

	}
	Vector(const Vector<T>& v){
		_start = new T[v.Capacity()];
		//拷贝被拷贝对象的内容，但是不能使用memcpy；
		for (int i = 0; i < v.Size(); i++){
			_start[i] = v[i];
		}
		Copy(_start, v._start, v.Size());
		//更新_finish;_endofstorage
		_finish = _start + v.Size();
		_endofStorage = _start + v.Capacity();
	}
	T& operator=( Vector<T>& v){
		Swap(v);
		//交换了两者之间的对应指针和空间
		return *this;
	}

	~Vector(){
		if (_start){
			delete[] _start;
			_start = _finish = _endofStorage = nullptr;
		}
	}
	void Swap(Vector<T> & v){
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofStorage, v._endofStorage);
	}


	size_t Size()const{
		return _finish - _start;
	}

	size_t Capacity()const{
		return _endofStorage - _start;
	}
	void PushBack(const T& val){
		//首先考虑是不是需要增容
		if (_finish == _endofStorage){
			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
			Reserve(newc);
		}
		*_finish = val;
		++_finish;
	}


	//增容逻辑
	void Reserve(size_t n){
		if (n > Capacity()){
			size_t sz = Size();
			T *_new = new T[n];
			if (_start){
				for (int i = 0; i < sz; i++)
					_new[i] = _start[i];
			}
				delete[] _start;
				_start = _new;
				_finish = _start + sz;
				_endofStorage = _start + n;
		}
	}

	T& operator[](size_t pos){
		assert(pos < Size());
		return _start[pos];
	}
	const T& operator[](size_t pos)const{
		assert(pos < Size());
		return _start[pos];
	}

	iterator begin(){
		return _start;
	}
	iterator end(){
		return _finish;
	}

	const_iterator begin()const {
		return _start;
	}

	const_iterator end()const {
		return _finish;
	}


	void Insert(iterator pos,const T& val ){
		assert(pos>=_start&&pos<=_finish);
		size_t len = pos-_start;
		if (_finish == _endofStorage){
			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
			Reserve(newc);
		}
		pos = _start + len;
		//增容之后更新迭代器以防止 迭代器失效
		//先计算了pos与_start的距离，
		//之后_start+len将之前的空间扩大了一位
		iterator end = _finish;

		while (end > pos){
			//将pos以后的元素都往后挪动一位
			*(end) = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
	}

	iterator Erase(iterator pos){
		assert(pos <= _finish&&pos >= _start);
		/*size_t len = pos - _start;
		iterator tmp = _start + len;
		while (tmp <= _finish){
		*(tmp-1) = *(tmp);
		tmp++;
		}
		--_finish;
		return pos;*/
		iterator begin = pos + 1;
		while (begin < _finish){
		*(begin - 1) = *(begin);
		begin++;
		}
		--_finish;
		return pos;
	}

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
	void Resize(size_t n,const T&val=T()){
		if (n <= Size()){
			_finish=_start + n;
			//增加容量
		}
		else{
			if (n > Capacity())
				Reserve(n);
			while (_finish != _start + n){
				//当_finish小于_start+n时将_finish往后移动
				//并给移动的位置赋值为指定的值，或者默认的值
				*_finish = val;
				_finish++;
			}
		}
	}
private:
	T *_start;
	T *_finish;
	T *_endofStorage;
};


template <class T>
//void PrintfVector(const Vector<T> &v){
//	for (int i = 0; i < v.Size();i++){
//		cout <<v[i]<< " ";
//		//此处的v[]如要返回值，必须重载[]
//	}
//	cout << endl;
//}
void PrintfVector(const Vector<T> &v){
	for (int i = 0; i < v.Size();i++){
		cout <<v[i]<< " ";
		//此处的v[]如要返回值，必须重载[]
	}
	cout << endl;
}

void testint(){
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(2);
	v.PushBack(2);
	v.PushBack(2);
	v.PushBack(2);
	Vector<int> v1(v);
	PrintfVector(v1);
	PrintfVector(v);
	cout << v.begin() << endl;
	v.Erase(v.end() - 1);
	PrintfVector(v);
	v.Resize(20, 2);
	PrintfVector(v);
	v.Resize(5);
	PrintfVector(v);
}

void testString(){
	Vector<string> v;
	v.PushBack("hello ");
	v.PushBack("bit!");
	Vector<string> v1(v);
}
int main(){
	testint();
	testString();
	return 0;
}