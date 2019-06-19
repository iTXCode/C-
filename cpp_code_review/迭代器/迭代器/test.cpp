//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//
//
//using namespace std;
//
//
////const迭代器的使用
//void printString(const string &s){
//	string::const_iterator sit = s.begin();
//	cout << "NO_2:" << " ";
//	while (sit != s.end()){
//		cout << *sit ;
//		++sit;
//	}
//	cout << endl;
//}
//
////反向迭代器
//void printRString(const string &s){
//	string::const_reverse_iterator sit = s.rbegin();
//	cout << "NO_3:" << " ";
//	while (sit != s.rend()){
//		cout << *sit;
//		++sit;
//		//看着是++,内部是--
//	}
//	cout << endl;
//}
////rbegin指向最后一个位置
////rend指向第一个位置的前一个位置
//
//
//
////普通迭代器
//void testiterator(){
//	string s("hello bit!");
//	string::iterator sit = s.begin();
//	cout << "NO_1:" << " ";
//	while (sit != s.end()){
//		cout << *sit;
//		++sit;
//	}
//	cout << endl;
//	printString(s);
//	printRString(s);
//
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4); 
//	v.push_back(5);
//
//	vector <int>::iterator vit = v.begin();
//	while (vit != v.end()){
//		cout << *vit;
//		++vit;
//	}
//	cout << endl;
//}
//
//
//
//
//int main(){
//	testiterator();
//	return 0;
//}
//
////迭代器：
////涉及模式:访问机制
////在外部：看作指针使用，内部实现上，不同容器有 
////不同的实现方式不一定是原生指针
////【迭代器分类】
////1.正向迭代器(可读可写)
////2.方向迭代器(可读可写)
////3.const迭代器(只读)
////begin:第一个元素的位置
////end:最后一个元素的下一个位置
////rbegin:最后一个元素的位置
////rend:第一个元素的前一个位置
//
//
//
//
//#if 0
//void testString1(){
//	string s("haha");
//	//可读可写
//	for (int i = 0; i < s.size(); ++i){
//		cout <<"NO1:"<< s[i]  << " ";
//		cout << "NO2:"<<s.operator[](i) << endl;
//	}
//	cout << endl;
//
//	for (auto e : s){
//		cout <<"NO3:"<< e << endl;
//	}
//}
//
//int main(){
//	testString1();
//	return 0;
//}
//#endif 

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int  main(){
	string s("yang zi jun");
	string::iterator sit = s.begin();
	while (sit!=s.end()){
		cout << *sit;
		++sit;
	}
	//普通的迭代器
	cout << endl;
	//vector迭代器的使用
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> visit_arr(arr, arr +10);
	//完成类型的
	vector<int>::iterator sit1;
	for (sit1 = visit_arr.begin(); sit1 != visit_arr.end(); sit1++){
		cout << *sit1;
	}
	cout << endl;

	string s1 = "hello bit!";
	string::const_iterator sit2 = s1.begin();
	while (sit2 != s1.end()){
		//sit[0] = 2;
		cout << *sit2;
		sit2++;
		//const迭代器为只读迭代器,若像修改其中的元素
		//编辑器就会抛出异常,程序异常终止
	}
	cout << endl;

	//反向迭代器
	string s2 = "hellolleh";
	string::const_reverse_iterator sit3 = s2.rbegin();
	while (sit3 != s2.rend()){
		cout << *sit3;
		++sit3;
	}
	cout << endl;
	return 0;
}