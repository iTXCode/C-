#include<iostream>

using namespace std;


//template <class T1,class T2>
////模板类型参数
//T1 Add(const T1 &a, const T2 &b){
//	return a + b;
//}
//
////非类型模板参数，作为常量来使用
//template<size_t N>
//
//void fun(){
//	T[N];//看作常量来使用
//}
////非类型模板参数，作为常量来使用
////一般不能用浮点数，类对象以及字符串不允许作为非类型模板参数
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

//参数用const修饰的版本
template <class T>
//const修饰错位,const -> a,b
bool isGreater(const T&a, const T&b){
	return a > b;
}

//1.需要有一个已经存在的通用模板函数
//2.模板参数为空
//3.函数名后要显示写出要特化的类型
//4.特化的类型的格式要和通用模板参数格式一致
//5.一般不去写函数模板的特化版本，函数模板的特化比较复杂，
//会爆出一些奇怪的错误，建议对于函数模板处理不了的
//或者报错的类型，去实现一个对应类型的普通函数

template <>
bool isGreater<char* &> /*需要显示的给出特化的版本*/(char* & const a, char *&const b){
	//需要有一个已经存在的通用模板函数
	//该函数为上一函数的特化版本
	if (strcmp(a, b) > 0)
		return true;
	return false;
}

////参数不用const修饰的版本
//template <class T>
//
//bool isGreater( T&a, T&b){
//	return a > b;
//}
//
//template <>
//bool isGreater<char*> /*需要显示的给出特化的版本*/(char* &a, char *&b){
//	//需要有一个已经存在的通用模板函数
//	//该函数为上一函数的特化版本
//	if (strcmp(a, b) > 0)
//		return true;
//	return false;
//}
int main(){
	int a = 10, b = 20;
	char* str1 = "jun";
	char*  str2 = "xian";
	cout << isquater(a, b) << endl;//编译器自己推演参数类型
	cout << isquater<int>(a, b) << endl;//显示的给出类型，编译器不用 推演
	cout << isGreater(a, b) << endl;
	cout << isGreater(str1, str2) << endl;
	//调用的是特化版本的函数
	return 0;
}

#endif



#if 0
//类模板特化
//全特化
template<class T1,class T2>
class Date{
public:
	Date(){ cout << "Date<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>

class Date<int,char>{
public:
	Date(){ cout << "Date<int,char>" << endl; }
private:
	int _d1;
	char _d2;
};

//半特化
//1.部分特化
template<class T>

class Date<T, char>{
public:
	Date(){ cout << "Date<T,char>" << endl; }
private:
	T _d1;
	char _d2;
};

//半特化
//2.对模板参数做一定的限制
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
////容器增容：拷贝
////memcpy: 一片内存的拷贝，效率高 : (1)
////		 赋值拷贝 = : 每一个元素依次拷贝，效率比较低：o(n)
//
////		 STL拷贝分两类
////		 1.内置类型
////		 2.自定义类型：拷贝赋值
////POD: Plain Old Data ---->内置类型
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
////RTTI: Run Time Type Information 运行时类别识别
////RTTI: typeid typeid(a).name
////bool  isPODtype(const char* tp) :缺陷：效率低，时间复杂度O(N^2)
//
//bool isPODtype(const char* tp){
//	static char* typeArr[] = { "int", "double", "flaot", "char", "...." };
//	for (int i = 0; i < sizeof(typeArr) / sizeof(typeArr[0]); i++){
//		if (strcmp(tp, typeArr[i]))
//			return true;
//	}
//	return false;
//}
////时间复杂度O(n^2)
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
//类型萃取
//结构体的使用方式

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
【类型萃取typetrats】
1.使用类模板和模板特化技术定义类型萃取类
typetraits,内部定义类型falsetype
2.对于内置类型，通过模板特化自定义类型的
typetraits,内部定义类型truetype
3.编译期通过输入的类型生成对应的typetraits，调用TrueType或者falsetype的get(）
方法确定具体的类型是否为自定义类型 ，根据返回结果决定返回的方式
4.优点：效率高，编译时确定类型，不占运行时间
*/


#endif 


#if 0
//【STL 类型萃取设计方法】
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

void Copy(T* dst, const T *src, size_t sz,TrueType){
	cout << typeid(T).name() << ":memcpy()" << endl;
	memcpy(dst, src, sizeof(T)*sz);
}

template <class T>

//通过最后一个参数不同形成函数重载
void Copy(T* dst, const T *src, size_t sz,FalseType){
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

//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case
//等关键字及条件判断语句（A?B:C

//template<size_t N>
//struct Sum{
//	enum{Ret=N+Sum<N-1>::Ret};
//};
////模板特化用来结束编译式递归
//template<>
//struct Sum<1>{
//	enum{Ret=1};
//};
//
//int main(){
//	cout << Sum<10>::Ret << endl;
//	return 0;
//}


//【模板分离编译】
//模板函数或者类模板函数申明和定义都放在.h或者.hpp文件中
//不支持分离编译:链接的时候找不到实际指令
/*
编译过程：
a.cpp-->1.预处理：头文件展开，宏替换，条件编译，去注释，
生成--->a.i
a.i--->2.编译：检查语法，如果无语法错误，把代码编译成汇编代码，-->a.s
a.s->3.汇编：汇编代码转成机器码，-->a.obj
导出符号表(已解决的指令)，未解决符号表(需要在其他的导出符号表中寻找地址的指令 ) 。
a.obj,x.obj..->4.链接:把多个obj文件链接在一起，生成一个可执行程序。
*/
//cpp文件参与编译，头文件不参与编译
