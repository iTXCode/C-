#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
struct TrueType{

};
struct FalseType{

};

//������ȡ
template<class T>

struct TypeTraits{
	typedef FalseType _isPodType;
};

//�ػ��汾

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

//ͨ�����һ��������ͬ�γɺ�������
template <class T>

void Copy(T* dst, const T *src, size_t sz, TrueType){
	cout << typeid(T).name() << ":memcpy()" << endl;
	memcpy(dst, src, sizeof(T)*sz);
}

template <class T>

//ͨ�����һ��������ͬ�γɺ�������
void Copy(T* dst, const T *src, size_t sz, FalseType){
	//���һ������ֻ�������ͣ�û��������
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
		//������������������ݣ����ǲ���ʹ��memcpy��
		for (int i = 0; i < v.Size(); i++){
			_start[i] = v[i];
		}
		Copy(_start, v._start, v.Size());
		//����_finish;_endofstorage
		_finish = _start + v.Size();
		_endofStorage = _start + v.Capacity();
	}
	T& operator=( Vector<T>& v){
		Swap(v);
		//����������֮��Ķ�Ӧָ��Ϳռ�
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
		//���ȿ����ǲ�����Ҫ����
		if (_finish == _endofStorage){
			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
			Reserve(newc);
		}
		*_finish = val;
		++_finish;
	}


	//�����߼�
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
		//����֮����µ������Է�ֹ ������ʧЧ
		//�ȼ�����pos��_start�ľ��룬
		//֮��_start+len��֮ǰ�Ŀռ�������һλ
		iterator end = _finish;

		while (end > pos){
			//��pos�Ժ��Ԫ�ض�����Ų��һλ
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
	//			//������Ч��������
	//		}
	//		else{
	//			if (n > Capacity())
	//				Reserve(n);
	//			//�����ӵĿռ丳ֵ
	//			while (_finish != _start + n){
	//				*_finish = val;
	//				_finish++;
	//			}
	//		}
	//	}
	void Resize(size_t n,const T&val=T()){
		if (n <= Size()){
			_finish=_start + n;
			//��������
		}
		else{
			if (n > Capacity())
				Reserve(n);
			while (_finish != _start + n){
				//��_finishС��_start+nʱ��_finish�����ƶ�
				//�����ƶ���λ�ø�ֵΪָ����ֵ������Ĭ�ϵ�ֵ
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
//		//�˴���v[]��Ҫ����ֵ����������[]
//	}
//	cout << endl;
//}
void PrintfVector(const Vector<T> &v){
	for (int i = 0; i < v.Size();i++){
		cout <<v[i]<< " ";
		//�˴���v[]��Ҫ����ֵ����������[]
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