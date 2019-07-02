#include<iostream>
#include<vector>

using namespace std;
//泛型编程

//int main(){
//	vector<char> v;
//	//vector中的数据不是以'\0'结束的(string 中是)
//	//vector中可以管理不同类型的数据
//	vector<char> v2(10, 'x');
//	vector<int> v4(10, 2);
//	vector<int>::iterator sit = v4.begin();
//	while (sit != v4.end()){
//		cout << *sit;
//		sit++;
//	}
//	string s("hello bit!");
//	vector<char> v3(s.begin(),s.end());
//	return 0;
//}
////string::iterator: char*
////vector<T>:  T*

//int main(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (int i = 0; i < v.size(); i++){
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	//普通迭代器方式访问
//	//vector<int>::iterator vit = v.begin();
//	auto vit = v.begin();
//	while (vit!=v.end()){
//		cout << *vit << " ";
//		vit++;
//	}
//	cout << endl;
//
//
//	//反向迭代器的访问方式
//	auto vit1 = v.rbegin();
//	while (vit1 != v.rend()){
//		cout << *vit1 << " ";
//		vit1++;
//	}
//	cout << endl;
//
//	//打印迭代器中内容的时候不能改变其内容
//	vector<int>::const_iterator  cvit = v.begin();
//	while (cvit != v.end()){
//		cout << "const:" << *cvit<<" ";
//		cvit++;
//	}
//	cout << endl;
//
//	//基于范围的for循环,内部调用迭代器的begin和end;
//	for (auto &e : v){
//		
//		cout << e << " ";
//		//e++;//此处的e匹配的是迭代器中的元素
//		//若先++后输出的话就改变了迭代器本来要输出的内容
//	}
//	cout << endl;
//	return 0;
//}
 

//void printVector(vector<int> &v){
//	//对于只是简单打印的可以传引用，进而不进行值拷贝
//	//若希望修改迭代器中的内容，传参数的时候可以传const修饰的 参数
//	//形如：const vector<int> &v;
//	auto vit1 = v.begin();
//	while (vit1 != v.end()){
//		cout << *vit1 << " ";
//		vit1++;
//	}
//	cout << endl;
//}
//
//int main(){
//	vector<int> v(10, 1);
//	printVector(v);
//	//max_size();显示迭代器中可以存放的最多元素数量
//	vector<int> v1;
//	vector<char> v2;
//	vector<double> v3;
//	cout << v1.max_size() << endl;  //1G
//	cout << v2.max_size() << endl;  //4G
//	cout << v3.max_size() << endl;  //0.5G
//	return 0;
//}



#if 0
void printVector(vector<int> &v){
	//对于只是简单打印的可以传引用，进而不进行值拷贝
	//若希望修改迭代器中的内容，传参数的时候可以传const修饰的 参数
	//形如：const vector<int> &v;
	auto vit1 = v.begin();
	while (vit1 != v.end()){
		cout << *vit1 << " ";
		vit1++;
	}
	cout << endl;
}

//insert接口的测试
void testVector(){
	vector<int> v;
	//vector容量初始值为0(不存放内容的时候)
	//之后扩容的时候window按照原来容量的1.5倍进行扩容
	//Linux按照原来的2倍进行扩容
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	v.insert(v.begin(), 0);  //头插
	v.insert(v.end(), 6);   //尾插
	//函数的参数不再是位置,而是迭代器
	printVector(v);
	v.insert(++v.begin(),10,20);
	//迭代器可以++;首元素的下一个元素

	printVector(v);
}

//扩容的是否会导致迭代器失效
//相当于一个野指针
int main(){
	testVector();
	return 0;
}


#endif

#if 0
void printVector(vector<int> &v){
	//对于只是简单打印的可以传引用，进而不进行值拷贝
	//若希望修改迭代器中的内容，传参数的时候可以传const修饰的 参数
	//形如：const vector<int> &v;
	auto vit1 = v.begin();
	while (vit1 != v.end()){
		cout << *vit1 << " ";
		vit1++;
	}
	cout << endl;
}

//erase删除位置的迭代器

void testErase(){
	vector<int> v(10, 2);
	//删除函数的参数,删除的是一个元素的话(删除位置的迭代器)
	//删除的是连续几个元素的话(参数为两个迭代器)
	//iterator erase(iterator pos)
	//iterator erase(iterator first,iterator last)
	//从迭代器first开始删除到迭代器last;
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin(), v.end()-3);
	//迭代器可以进行加减运算
	printVector(v);
}

int main(){
	testErase();
	return 0;
}
#endif



#if 0
//迭代器失效:迭代器指向的位置无效/越界
//1.insert(iterator it,T x);
//插入可能导致增容，会释放原有的空间，开辟新的空间，拷贝原有的内容
//插入之前的迭代器位置可能已经被释放，本质为野指针
//调用完insert接口,重新获取迭代器，防止迭代器失效
//2.调用erase(iterator it);
//访问越界,
//调用完erase接口,获取erase接口的返回值，防止迭代器失效
void printVector(vector<int> &v){
	//对于只是简单打印的可以传引用，进而不进行值拷贝
	//若希望修改迭代器中的内容，传参数的时候可以传const修饰的 参数
	//形如：const vector<int> &v;
	auto vit1 = v.begin();
	while (vit1 != v.end()){
		cout << *vit1 << " ";
		vit1++;
	}
	cout << endl;
}

void testErase(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	auto vit = v.begin();
	while (vit != v.end()){
		if (*vit % 2 == 0)
			vit=v.erase(vit);
		//调用完erase接口,获取erase接口的返回值，防止迭代器失效
		//若不用vit去那这个接口返回值的话，释放一次后程序奔溃
		//这样赋值的目的是防止迭代器指向的位置是一个无效的位置。
		//拿取erase接口的返回值(返回值为迭代器)

		else
			vit++;
	}
	printVector(v);
}
int main(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	testErase();
	//auto vit = v1.begin();
	//v1.insert(vit,10);  
	//在插入的时候进行了扩容操作，该过程中重新开辟了空间
	//导致原来的空间失效(迭代器失效),

	auto vit = v1.begin();
	v1.insert(vit, 10);
	vit = v1.begin();
	//调用完insert接口,重新获取迭代器，防止迭代器失效
	*vit = 20; //本质：野指针(指向已经释放的空间)
	v1.push_back(3);
	v1.push_back(4);
	printVector(v1);
	return 0;
}

//@@@@@@@@
//能不能自己实现的时候将insert函数设计成在原来的地址进行增容？
//@@@@@@@@

#endif

#if 0
void printVector(const vector<int> &v){
	for (auto& e : v){
		cout << e << " ";
	}
	cout << endl;
}
//全局函数swap和成员函数swap
//两个函数的区别
//本质上没有区别
//string的swap函数
//全局函数：swap(s1,s2)-->{s1.swap(s2)}//本质上内部调用的为string的成员函数
//成员函数：swap(s2)-->s1.swap(s2);
//全局的swap只是对成员的swap函数进行了封装
//通用全局变量:swap(T& s1,T& s2)-->{T temp=s1;s1=s2;s2=temp;} //进行了拷贝
//vector的swap函数
//全局函数：swap(s1,s2)-->{s1.swap(s2)}//本质上内部调用的为vector的成员函数
//成员函数：swap(s2)-->s1.swap(s2);
//全局的swap只是对成员的swap函数进行了封装
int main(){
	vector<int> v1(3, 2);
	vector<int> v2(3, 4);
	printVector(v1);
	printVector(v2);
	//全局的交换函数
	swap(v1, v2);
	cout << "全局函数交换后:" << endl;
	printVector(v1);
	printVector(v2);
	//成员函数
	v1.swap(v2);
	cout << "成员函数交换后:" << endl;
	printVector(v1);
	printVector(v2);
	
	return 0;
}
#endif


#if 0
//手动释放vector的内存空间
//1.在一个局部域中定义一个空的vector
//2.调用vector swap函数，完成空间的交换
//3.出了局部域，编译器自动调用局部域中定义的局部变量的析构函数，完成空间的释放
//{vector<T> tmp; tmp.swap(v);}
int main(){
	vector<int> v(90, 1);
	cout << v.capacity() << endl;
	//No1:
	{
		vector<int> v1;
		//定义的时候没有初始化,其内部没有内容容量为0
		v1.swap(v);
	}//加了{}不会将v原来的空间释放掉
	//(加了{}会在出作用域的时候调用析构函数释放局部变量v1)
	cout << "No1:"<<v.capacity() << endl;
	//No2:

	vector<int> v1(90, 1);
	cout << v1.capacity() << endl;
	v1.resize(0);//改变v1的有效字符数
	v1.shrink_to_fit();
	//
	cout << "No2:" << v1.capacity() << endl;
	return 0;
}
#endif

