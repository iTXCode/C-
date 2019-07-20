#include<iostream>

using namespace std;


//template <class T1,class T2>
////ģ�����Ͳ���
//T1 Add(const T1 &a, const T2 &b){
//	return a + b;
//}
//
////������ģ���������Ϊ������ʹ��
//template<size_t N>
//
//void fun(){
//	T[N];//����������ʹ��
//}
////������ģ���������Ϊ������ʹ��
////һ�㲻���ø�������������Լ��ַ�����������Ϊ������ģ�����
//template <class T,size_t N>
//class Array{
//private:
//	T a[N];
//};
//int main(){
//	Array<int, 10> arr1;
//	Array<double, 100> arr2;
//	return 0;
//}



#if 0
template <class T>

bool isquater(T&a,T&b){
	return a == b;
}

//������const���εİ汾
template <class T>
//const���δ�λ,const -> a,b
bool isGreater(const T&a, const T&b){
	return a > b;
}

//1.��Ҫ��һ���Ѿ����ڵ�ͨ��ģ�庯��
//2.ģ�����Ϊ��
//3.��������Ҫ��ʾд��Ҫ�ػ�������
//4.�ػ������͵ĸ�ʽҪ��ͨ��ģ�������ʽһ��
//5.һ�㲻ȥд����ģ����ػ��汾������ģ����ػ��Ƚϸ��ӣ�
//�ᱬ��һЩ��ֵĴ��󣬽�����ں���ģ�崦���˵�
//���߱�������ͣ�ȥʵ��һ����Ӧ���͵���ͨ����

template <>
bool isGreater<char* &> /*��Ҫ��ʾ�ĸ����ػ��İ汾*/(char* & const a, char *&const b){
	//��Ҫ��һ���Ѿ����ڵ�ͨ��ģ�庯��
	//�ú���Ϊ��һ�������ػ��汾
	if (strcmp(a, b) > 0)
		return true;
	return false;
}

////��������const���εİ汾
//template <class T>
//
//bool isGreater( T&a, T&b){
//	return a > b;
//}
//
//template <>
//bool isGreater<char*> /*��Ҫ��ʾ�ĸ����ػ��İ汾*/(char* &a, char *&b){
//	//��Ҫ��һ���Ѿ����ڵ�ͨ��ģ�庯��
//	//�ú���Ϊ��һ�������ػ��汾
//	if (strcmp(a, b) > 0)
//		return true;
//	return false;
//}
int main(){
	int a = 10, b = 20;
	char* str1 = "jun";
	char*  str2 = "xian";
	cout << isquater(a, b) << endl;//�������Լ����ݲ�������
	cout << isquater<int>(a, b) << endl;//��ʾ�ĸ������ͣ����������� ����
	cout << isGreater(a, b) << endl;
	cout << isGreater(str1, str2) << endl;
	//���õ����ػ��汾�ĺ���
	return 0;
}

#endif



#if 0
//��ģ���ػ�
//ȫ�ػ�
template<class T1,class T2>
class Date{
public:
	Date(){ cout << "Date<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//ȫ�ػ�
template<>

class Date<int,char>{
public:
	Date(){ cout << "Date<int,char>" << endl; }
private:
	int _d1;
	char _d2;
};

//���ػ�
//1.�����ػ�
template<class T>

class Date<T, char>{
public:
	Date(){ cout << "Date<T,char>" << endl; }
private:
	T _d1;
	char _d2;
};

//���ػ�
//2.��ģ�������һ��������
template<class T1,class T2>

class Date<T1*, T2*>

{
public:
	Date(){ cout << "Date<T1*,T2*>" << endl; }
private:
	T1* _d1;
	T2* _d2;
};

template<class T1, class T2>

class Date<T1&, T2&>

{
public:
	Date(){ cout << "Date<T1&,T2&>" << endl; }
private:
	T1* _d1;
	T2* _d2;
};
int main(){
	Date<int, int> d1; //Date<T1,T2>
	Date<int, char> d2;//Date<int,char>
	Date<char, char> d3;//Date<T,char>
	Date<char*, int*> d4;//Date<T1*,T2*>
	Date<char&, int&> d5;//Date<T1&,T2&>
	return 0;
}
#endif

//
//
////�������ݣ�����
////memcpy: һƬ�ڴ�Ŀ�����Ч�ʸ� : (1)
////		 ��ֵ���� = : ÿһ��Ԫ�����ο�����Ч�ʱȽϵͣ�o(n)
//
////		 STL����������
////		 1.��������
////		 2.�Զ������ͣ�������ֵ
////POD: Plain Old Data ---->��������
//template <class T>
//
//void Copy(T* dst, const T *src, size_t sz, bool isPODtype){
//	if (isPODtype){
//		memcpy(dst,src,sizeof(T)*sz);
//	}
//	else{
//		for (int i = 0; i < sz, i++){
//			det[i] = src[i];
//		}
//	}
//}
//
////RTTI: Run Time Type Information ����ʱ���ʶ��
////RTTI: typeid typeid(a).name
////bool  isPODtype(const char* tp) :ȱ�ݣ�Ч�ʵͣ�ʱ�临�Ӷ�O(N^2)
//
//bool isPODtype(const char* tp){
//	static char* typeArr[] = { "int", "double", "flaot", "char", "...." };
//	for (int i = 0; i < sizeof(typeArr) / sizeof(typeArr[0]); i++){
//		if (strcmp(tp, typeArr[i]))
//			return true;
//	}
//	return false;
//}
////ʱ�临�Ӷ�O(n^2)
//template <class T>
//
//void Copy(T* dst, const T *src, size_t sz){
//	if (isPODtype(typeid(T).name())){
//		memcpy(dst, src, sizeof(T)*sz);
//	}
//	else{
//		for (int i = 0; i < sz, i++){
//			det[i] = src[i];
//		}
//	}
//}




#if 0
//������ȡ
//�ṹ���ʹ�÷�ʽ

struct TrueType{
	static bool Get(){
		return true;
	}
};
struct FalseType{
	static bool Get(){
		return false;
	}
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


template <class T>

void Copy(T* dst, const T *src, size_t sz){
	if (TypeTraits<T>::_isPodType::Get()){
		cout << typeid(T).name() << ":memcpy()" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else{
		cout << typeid(T).name() << ":operator=()" << endl;
		for (int i = 0; i < sz; i++){
			dst[i] = src[i];
		}
	}
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[7];
	Copy(arr2, arr, 7);
	string str1[] = {"123","345","hello","world"};
	string str2[4];
	Copy(str2, str1, 4);
	return 0;
}
/*
��������ȡtypetrats��
1.ʹ����ģ���ģ���ػ���������������ȡ��
typetraits,�ڲ���������falsetype
2.�����������ͣ�ͨ��ģ���ػ��Զ������͵�
typetraits,�ڲ���������truetype
3.������ͨ��������������ɶ�Ӧ��typetraits������TrueType����falsetype��get(��
����ȷ������������Ƿ�Ϊ�Զ������� �����ݷ��ؽ���������صķ�ʽ
4.�ŵ㣺Ч�ʸߣ�����ʱȷ�����ͣ���ռ����ʱ��
*/


#endif 


#if 0
//��STL ������ȡ��Ʒ�����
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

void Copy(T* dst, const T *src, size_t sz,TrueType){
	cout << typeid(T).name() << ":memcpy()" << endl;
	memcpy(dst, src, sizeof(T)*sz);
}

template <class T>

//ͨ�����һ��������ͬ�γɺ�������
void Copy(T* dst, const T *src, size_t sz,FalseType){
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

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[7];
	Copy(arr2, arr, 7);
	string str1[] = { "123", "345", "hello", "world" };
	string str2[4];
	Copy(str2, str1, 4);
	return 0;
}
#endif

//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
//�ȹؼ��ּ������ж���䣨A?B:C

//template<size_t N>
//struct Sum{
//	enum{Ret=N+Sum<N-1>::Ret};
//};
////ģ���ػ�������������ʽ�ݹ�
//template<>
//struct Sum<1>{
//	enum{Ret=1};
//};
//
//int main(){
//	cout << Sum<10>::Ret << endl;
//	return 0;
//}


//��ģ�������롿
//ģ�庯��������ģ�庯�������Ͷ��嶼����.h����.hpp�ļ���
//��֧�ַ������:���ӵ�ʱ���Ҳ���ʵ��ָ��
/*
������̣�
a.cpp-->1.Ԥ����ͷ�ļ�չ�������滻���������룬ȥע�ͣ�
����--->a.i
a.i--->2.���룺����﷨��������﷨���󣬰Ѵ������ɻ����룬-->a.s
a.s->3.��ࣺ������ת�ɻ����룬-->a.obj
�������ű�(�ѽ����ָ��)��δ������ű�(��Ҫ�������ĵ������ű���Ѱ�ҵ�ַ��ָ�� ) ��
a.obj,x.obj..->4.����:�Ѷ��obj�ļ�������һ������һ����ִ�г���
*/
//cpp�ļ�������룬ͷ�ļ����������
