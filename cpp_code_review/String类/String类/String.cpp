

#include<iostream>
#include<string>
using namespace std;
#if 0
int main(){
	string s;
	string s1("hello bit!");
	string s2(10,'$');
	string s3(s1);
	cout << s3<< endl;
	cout << s2 << endl;
	cout << s1.size() << endl;
	//输出字符串的有效个数
	cout << s1.length() << endl;
	//两者效果一样
	cout << s1.capacity() << endl;
	//输出s1对象的容量
	s1.clear();
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	//clear()接口只是将对象中的内容清空并未改变其容量

	cout << s1.empty() << endl;
	//判断字符串是否为空，结果为布尔值(1/0)
	string s4("hellow bit!");
	cout << s4[0] << endl;
	//s4[n]输出s4的第n个字符
	s4[0] = 'H';
	//s[n]='x' 改写字符串的第n个字符,如果n大于其容量就会抛异常
	//触发了assert检查
	cout << s4 << endl;


	return 0;
}
#endif

#if 0
int main(){
	string s;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << hex << (int)s.c_str() << endl;
	s.resize(10, '&');
	cout << s.size() << endl;
	//计算并输出s字符串的有效字符个数
	cout << s << endl;

	s.resize(20, '5');
	//对s进行了扩容，并将多处的空间初始化为'5'
	//s.size(size_t n,char 'c')
	//此处的n有第三种情况
	//1.n<size  size变成n，capacity大小不变
	//2.size<n<capacity size变成n,capacity不变
	//3.n>capacity   size变成n，capacity增大，[size~n]
	//这个范围中的值被置成'c'
	//s.size(size_t n)  
	//1.n<size  size变成n，capacity大小不变
	//2.size<n<capacity size变成n,capacity不变
	//这个范围中的值被置成'\0'
	//3.n>capacity   size变成n，capacity增大，[size~n]
	//这个范围中的值被置成'\0'
	cout << s.size() << endl;
	//计算并输出s字符串的有效字符个数
	cout << s << endl;

	cout << s.c_str() << endl;
	//c语言的方法，按c 的格式获取.输出的是字符串的内容
	cout << hex << (int)s.c_str() << endl;
	//输出字符串的首地址
	s.resize(5);
	//改变指定字符串的空间
	//在增大空间的时候其地址可能改变
	//在减小空间大小的时候地址不会改变
	return 0;
}
#endif


#if   0
int main(){
	string s="hello bit!";
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity()<< endl;
	cout << hex << (int)s.c_str() << endl;
	s.reserve(20);
	//给s预留空间，不会改变有效元素个数
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << hex << (int)s.c_str() << endl;


	s.reserve(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << hex << (int)s.c_str() << endl;

	s += " haha";
	s += '!';
	string s1("hehe!");
	s += s1;
	cout << s << endl;
	
	return 0;
	//void reserve(size_t n=0):
	//提高效率，减少工作时间
	//reserve用来增容，提高效率，减少增容操作
	//当n>capacity时，进行增容，不改变size的大小
}

#endif

#if 0
void testString2(){
	string s;
	s.reserve(200);
	size_t sz = s.capacity();
	cout << sz << endl;
	cout << "capacity change:" << endl;
	for (int i = 0; i <200;i++){
		s.push_back(i);
		//增容规律
		//第一次按二倍增容，后续按1.5倍增容
		if (sz!=s.capacity())
		{
			sz = s.capacity();
			cout << sz << endl;
		}
		
	}
}

int main(){
	testString2();
	return 0;
}
#endif


#if 0
void testString(){
	string s;
	s.push_back('w');
	s += 'w';
	//添加字符
	s.append("ang");
	s += " shi xian";
	//添加字符串
	cout << s << endl;

	string s1;
	s1.assign(s);
	cout << s1 << endl;
	//复制了s的内容，打印出的内容和s的一样

	s1.assign(s,0,3);
	//在s中从第0个位置拿上3个字符给s1;
	cout << s1 << endl;


	s1.assign(10,'a');
	//s.assign(size_t n,'x');将s1中的内容改成n个'x'
	cout << s1 << endl;

	s1.assign(s.begin(), s.end());
	//拷贝整个字符串s
	cout << s1 << endl;
}

int main(){
	testString();
	return 0;
}

#endif


#if 0
//insert
int main(){
	string s;
	s.insert(0, "hello");
	cout << s << endl;
	s.insert(0, "bit!");
	cout << s << endl;
	//s.insert(size_t pos,const string& str)
	//从某个位置开始进行头插
	string s1;
	s1.insert(0,s,3,5);
	//往s1中插入s中的内容，插入第0个位置开始数第3的5个元素
	cout << s1 << endl;
	return 0;
}
#endif



#if 0
//删除(erase)
int main(){
	string s("hello bit!");
	s.erase(0,4);
	//string& erase(size_t pos,size_t len);
	//删除从第0个位置开始的4个字符
	//如果输入的length大于字符串长度，取实际长度和length的大小中的 较小者
	//既将所有的字符删除掉就可以
	cout << s << endl;
	return 0;
}
#endif


//int main(){
//	string s("hello bit");
//	string s1("haha");
//	s.replace(0, 2, s1);
//	//用s1中的 内容来代替s中从位置0开始的2个字符
//	cout << s1 << endl;
//	cout << s << endl;
//	return 0;
//}



#if 0

//substr
int  main(){
	string s("hello baby!");
	//substr(size_t pos=0,size_t n);
	//从字符串s中的位置0开始的n个字符
	string s1 = s.substr(2,8);
	cout << s1 << endl;
	size_t pos = s.find('o');
	//rfind从尾端开是查找第一个'o'
	s1 = s.substr(pos, s.size() - pos);
	cout << s1 << endl;

	string add = "http://www.cplusplus.com/reference/string/string/";
	size_t pos1 = add.find("://");//4
	string a = add.substr(0,pos1);
	cout<<"string a=" << a << endl;

	size_t sz = add.find('/',pos1 + 3);
	//find(char 'x',size_t pos);
	//从指定的位置下标开始查找执行的字符'x'
	string b = add.substr(pos1 + 3, sz - pos1 - 3);
	cout << "string b="<<b << endl;
	return 0;
}
#endif




//反转字符串

string reverseString(string s){
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end){
		swap(s[begin], s[end]);
		end--;
		begin++;
	}
	return s;
}


int main(){
	string s("hello bit!");
	cout <<"s="<< s << endl;
	cout << "reverseString(s)=" << reverseString(s) << endl;
	
	return 0;
}