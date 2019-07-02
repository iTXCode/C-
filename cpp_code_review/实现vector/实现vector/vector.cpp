#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

template<class T>

class Vector{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{

	}
	size_t Size()const{
		return _finish - _start;
	}
	size_t Capacity()const{
		return _endOfStorage - _start;
	}
	void PushBack(const T&val){
		//if (Size() == Capacity())
		if (_finish == _endOfStorage)
		{
			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
			Reserve(newc);
		}
		*_finish = val;
		//更新size
		++_finish;
	}

	void Reserve(size_t n){
		//1.拷贝的时候判断原来空间是否为空，为空不需要拷贝
		//2.拷贝的时候注意深拷贝的问题，不同的类型拷贝的方式不同，直接
		//调用T类型的赋值运算符重载依次完成拷贝
		if (n > Capacity()){
			size_t sz = Size();
			//申请新的空间
			T* tmp = new T[n];
			//检查空间是否为空
			//if (_start){
			//浅拷贝
			//	memcpy(tmp, _start, sizeof(T)*sz);
			//	//拷贝原有空间的内容
			//	delete _start;
			//	//释放原有空间
			//	//当插入字符串的时候，第三次插入在delete 处程序奔溃
			//	//释放空间出现二次释放的问题
			//}

			if (_start){
				//深拷贝，调用T类型的赋值运算符重载完成拷贝
				for (int i = 0; i < sz; i++){
					tmp[i] = _start[i];
				}
				delete[] _start;
				//释放原有空间
				//当插入字符串的时候，第三次插入在delete 处程序奔溃
				//释放空间出现二次释放的问题
			}
			_start = tmp;
			//更新size;
			_finish = _start + sz;
			//更新容量
			_endOfStorage = _start + n;
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
	const_iterator begin() const {
		return _start;
	}

	const_iterator end() const{
		return _finish;
	}
private:
	T* _start;
	//指向第一个元素的起始位置
	//eg:int 第一个字节的位置
	T* _finish;
	//最后一个位置的结束位置
	//eg:int 最后一个字节的下一个位置
	T* _endOfStorage;
	//已分配好的空间的结束位置
};

template <class T>

void PrintVector(const Vector<T>& v){
	for (int i = 0; i < v.Size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}
template <class T>
void PrintVectorFor(const Vector<T>& v){
	for (auto& e:v){
		cout << e << " ";
	}
	cout << endl;
}



int main(){
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	PrintVectorFor(v);
	Vector<string> v1;
	v1.PushBack("hello");
	v1.PushBack(" world!");
	PrintVectorFor(v1);
	return 0;
}