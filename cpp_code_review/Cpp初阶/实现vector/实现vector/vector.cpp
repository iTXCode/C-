//#include<iostream>
//#include<assert.h>
//#include<string>
//
//using namespace std;
//
//template<class T>
//
////vector��ʵ���ǿ�����ָ�������һЩ�в�����
//class Vector{
//public:
//	typedef T* iterator;
//	//ģ��ָ��(���Խ����������͵ĵ�����ʹ��)
//	typedef const T* const_iterator;
//	Vector()
//		:_start(nullptr)
//		, _finish(nullptr)
//		, _endOfStorage(nullptr)
//	{}
//
//	Vector(const Vector<T>& v){
//		//���ٿռ�
//		T* _start = new T[v.Capacity()];//���
//		//��������:���������ʹ��memcpy������
//		for (int i = 0; i < v.Size(); i++){
//			_start[i] = v[i];
//		}
//		//����_finish,_endOfStorage
//		_finish = _start + v.Size();
//		_endOfStorage = _start + v.Capacity();
//	}
//
//	T& operator=(Vector<T> v){
//		Swap(v);
//		//��������Դ�Ϳռ� 
//		return *this;
//	}
//	~Vector(){
//		if (_start){
//			delete[] _start;
//			_start = _finish = _endOfStorage = nullptr;
//	    //������ָ��ָ��ͬһ��ط�
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
//		//���ߵĲΪ�������е���Ч�ַ�����
//	}
//	size_t Capacity()const{
//		return _endOfStorage - _start;
//		//���ص������������Ĵ�С
//	}
//	void PushBack(const T&val){
//		//if (Size() == Capacity())
//		if (_finish == _endOfStorage)
//		{//������������˵����Ч�ַ������Ѿ�մ������������������Ҫ������
//			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
//			Reserve(newc);
//		}
//		*_finish = val;
//		//��val��ֵ���뵽��Ч�ַ���������
//		//����size(��Ч�ַ�����)
//		++_finish;
//	}
//
//	void Reserve(size_t n){
//		//1.������ʱ���ж�ԭ���ռ��Ƿ�Ϊ�գ�Ϊ�ղ���Ҫ����
//		//2.������ʱ��ע����������⣬��ͬ�����Ϳ����ķ�ʽ��ͬ��ֱ��
//		//����T���͵ĸ�ֵ���������������ɿ���
//		if (n > Capacity()){
//			size_t sz = Size();
//			//�����µĿռ�
//			T* tmp = new T[n];
//			//���ռ��Ƿ�Ϊ��
//			//if (_start){
//			//ǳ����
//			//	memcpy(tmp, _start, sizeof(T)*sz);
//			//	//����ԭ�пռ������
//			//	delete _start;
//			//	//�ͷ�ԭ�пռ�
//			//	//�������ַ�����ʱ�򣬵����β�����delete ��������
//			//	//�ͷſռ���ֶ����ͷŵ�����
//			//}
//
//			if (_start){
//				//���������T���͵ĸ�ֵ�����������ɿ���
//				for (int i = 0; i < sz; i++){
//					tmp[i] = _start[i];
//				}
//				delete[] _start;
//				//�ͷ�ԭ�пռ�
//				//�������ַ�����ʱ�򣬵����β�����delete ��������
//				//�ͷſռ���ֶ����ͷŵ�����
//			}
//			_start = tmp;
//			//����size;
//			_finish = _start + sz;
//			//��������
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
//	//insert,erase ���ڵ�����ʧЧ������
//	//insert�����ݵ�ʱ�������ʧЧ
//	//���ж�λ�õĺϷ���
//	//����Ƿ���Ҫ����
//	//�����Ժ�Ҫ���µ�������λ�ã���ֹ������ʧЧ
//	void Insert(iterator pos, const T& val){
//		assert(pos<=_finish&&pos>=_start);
//		size_t len = pos - _start;
//		//�������λ�õ��׵�ַ�ľ��룬�Ա��ڲ�����Ϻ�
//		//ȷ��pos֮ǰ��Ԫ�أ�pos ��λ��
//		if (_finish == _endOfStorage){
//			size_t newc = (_start == nullptr ? 1 : 2 * Capacity());
//			Reserve(newc);
//		}
//		//����֮����Ҫ���µ�����
//		pos = _start + len;
//		iterator end = _finish;//��¼���Ԫ�صĽ���λ��
//		while (end > pos){
//			*end = *(end - 1);
//			end--;//����--end;
//		}
//		//��posλ�ò���Ԫ��
//		*pos = val;
//		//����_finish
//		++_finish;
//	}
//
//	//Erase�����µ���������Խ�����λ�÷����쳣
//	//������֮���ȡErase�ķ���ֵ�����µ�����
//	//���λ���Ƿ�Ϸ�
//	//ֱ�ӽ�posλ�õ�Ԫ����ǰ�ƶ������ǵ�posԭ����ֵ
//	//����_finisd��ֵ
//	iterator Erase(iterator pos){
//		assert(pos >= _start&&pos < _finish);
//		iterator begin = pos + 1;
//		//Ų��Ԫ��
//		while (begin < _finish){
//			*(begin - 1) = *begin;
//			begin++;
//		}
//		//����_finish��λ��
//		--_finish;
//		return pos;
//	}
//	//Resize
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
//private:
//	T* _start;
//	//ָ���һ��Ԫ�ص���ʼλ��
//	//eg:int ��һ���ֽڵ�λ��
//	T* _finish;
//	//���һ��λ�õĽ���λ��
//	//eg:int ���һ���ֽڵ���һ��λ��
//	T* _endOfStorage;
//	//�ѷ���õĿռ�Ľ���λ��
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
//	//ɾ������ż��
//	Vector<int>::iterator vit = v.begin();
//	while (vit != v.end()){
//		if (*vit % 2 == 0){
//			vit=v.Erase(vit);
//			//����Erase�����ķ���ֵ����ֹ������ʧЧ
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