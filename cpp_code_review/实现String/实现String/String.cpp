#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string.h>
#include<string>
using namespace std;


class String{
public:
	//【注意】
	//字符串指针输出会解引用,对于空指针解引用会奔溃
	//其他类型指针输出为地址
	//对于无参构造应该申请一个字节的空间,存放'\0'
	//String()
	//	:_str(new char[1])
	//{
	//	_str[0] = '\0';
	//}
	//String(char*  str)
	//	//:_str(str) 将_str指向与形参一样的空间,会引发多次释放的问题
	//	:_str(new char[strlen(str)+1])
	//	//应该将代码段的字符串内容拷贝一份在堆上
	//{
	//	strcpy(_str, str);
	//}

	//带参构造,需要申请和输入字符串一样的空间
	//把输入字符串拷贝进去
	//如果只拷贝字符串指针,可能会造成
	//1.二次释放(两个指针指向同一片空间)
	//2.如果传入的是字符串常量
	//(不能主动释放代码段的字符串常量)
	String(char*  str="")//写成全缺省的形式,缺省值位"";
		//:_str(str) 将_str指向与形参一样的空间
		:_str(new char[strlen(str) + 1])
		//应该将代码段的字符串内容拷贝一份在堆上
	{
		strcpy(_str, str);
	}


	//【拷贝构造】
	//深拷贝:拷贝成员变量+资源
	//浅拷贝:拷贝资源变量
	//String(const String& s)//传统写法
	//	:_str(new char[strlen(s._str) + 1])
	//{
	//	strcpy(_str, s._str);
	//}

	String(const String& s)//现代写法
		:_str(nullptr)
		//若不置空的话,*this刚开始指向随机值
		//当其把内容交还给tmp._str后，tmp._str调用析构函数释放的
		//是随机指针(程序奔溃)
		//【原则】:
		//1.自己不申请空间,不拷贝内容
		//2.通过调用构造函数(申请空间,拷贝内容)生成一个新的对象
		//3.直接获取临时对象的全部内容(通过交换指针完成),完成当前对象
		//的拷贝构造
		//4.不检查是否为自己给自己赋值因为在赋值之前无空间的释放操作
	{
		String tmp(s._str);
		//调用构造函数生成同样的一份资源,使得指针交换之后
		//两个指针指向的内容是一样的
		swap(_str, tmp._str);
	}

	//【析构函数】
	~String(){
		if (_str){
			delete[] _str;//释放堆上的空间
			_str = nullptr;
		}
	}

	//深拷贝,传统写法
	//返回引用,连续赋值
	//一定检查是否为自己给自己赋值,如果不检查，会造成
	//String& operator=(const String&  s){
	//	if (this != &s)//检查是否为自己给自己赋值
	//	{    //要拷贝的字符串长度不一定和当前对象的字符串长度一致
	//       //如果直接拷贝,空间不足的时候,会导致数据丢失
	//		//所以直接释放原来的空间,申请一个和当前要拷贝的字符串一样大的空间
	//		//_str至少有一个字节的空间,由构造函数保证的
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];
	//		strcpy(_str,s._str);
	//	}
	// return *this;
	//}

	//【现代写法】:赋值运算符重载
	//传入参数:传值调用拷贝构造,不会调用赋值运算符重载
	//不会引发赋值运算符无穷递归，通过调用拷贝构造完成拷贝
	//传值相当于在函数栈帧中生成一个临时对象
	//和拷贝构造相比,生成临时对象的时机不同,
     //拷贝构造:函数内部生成
	//赋值:传值的时候生成
	String& operator=(String s)
	{
		String tmp(s);//定义的零时变量出了作用域就会调用析构函数
		swap(_str, tmp._str);
		//因为交换了指针,所以释放临时变量指向的空间实质上是
		//释放了原来的_str指向的空间(调用析构函数释放)
		return *this;
	}


	char* c_str(){
		return _str;
	}

private:
	char* _str;
};
int main(){
	String s;
	cout << (void*)s.c_str() << endl;
	return 0;
}
#endif