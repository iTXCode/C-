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
		//����size
		++_finish;
	}

	void Reserve(size_t n){
		//1.������ʱ���ж�ԭ���ռ��Ƿ�Ϊ�գ�Ϊ�ղ���Ҫ����
		//2.������ʱ��ע����������⣬��ͬ�����Ϳ����ķ�ʽ��ͬ��ֱ��
		//����T���͵ĸ�ֵ���������������ɿ���
		if (n > Capacity()){
			size_t sz = Size();
			//�����µĿռ�
			T* tmp = new T[n];
			//���ռ��Ƿ�Ϊ��
			//if (_start){
			//ǳ����
			//	memcpy(tmp, _start, sizeof(T)*sz);
			//	//����ԭ�пռ������
			//	delete _start;
			//	//�ͷ�ԭ�пռ�
			//	//�������ַ�����ʱ�򣬵����β�����delete ��������
			//	//�ͷſռ���ֶ����ͷŵ�����
			//}

			if (_start){
				//���������T���͵ĸ�ֵ�����������ɿ���
				for (int i = 0; i < sz; i++){
					tmp[i] = _start[i];
				}
				delete[] _start;
				//�ͷ�ԭ�пռ�
				//�������ַ�����ʱ�򣬵����β�����delete ��������
				//�ͷſռ���ֶ����ͷŵ�����
			}
			_start = tmp;
			//����size;
			_finish = _start + sz;
			//��������
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
	//ָ���һ��Ԫ�ص���ʼλ��
	//eg:int ��һ���ֽڵ�λ��
	T* _finish;
	//���һ��λ�õĽ���λ��
	//eg:int ���һ���ֽڵ���һ��λ��
	T* _endOfStorage;
	//�ѷ���õĿռ�Ľ���λ��
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