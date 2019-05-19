//#include<iostream>
//#include<windows.h>
//#include<string>
//
//using namespace std;
//#include<map>
//
//void test_map(){
//	map<string, string> names;
//	names.insert(pair<string, string>("insert", "插入"));
//	//可以写成names.insert(make_pair("insert", "插入"));
//	//make_pair模板函数
//	//template<class K,class V>
//	//inline pair<K,V> make_pair(const K& k,const V&v){
//	//return pair<K,V> (k,v);
//    //}
//	names.insert(pair<string, string>("sort", "排序"));
//	names.insert(pair<string, string>("find", "查找"));
//	names.insert(pair<string, string>("binary", "二"));
//
//	//修改词义
//	//No.1
//	auto it = names.find("binary");
//	if (it != names.end()){
//	it->second = "二进位的";
//	}
//	auto ret = names.begin();
//	//map<string, string> ::iterator ret = names.begin();
//	while (ret != names.end()){
//		cout << (*ret).first << ":" << (*ret).second << endl;
//		//cout << ret->first << ":" << ret->second << endl;
//		++ret;
//	}
//
//	//No.2
//	names["binary"] = "二进位";
//
//
//	
//	//c++11
//	for ( const auto& e : names){  //不修改const
//		cout << e.first << ":" << e.second<<endl;
//	}
//}
//
//int main(){
//	test_map();
//	system("pause");
//	return 0;
//}
//



//
//#include<iostream>
//#include<windows.h>
//#include<string>
//
//using namespace std;
//#include<map>
//
//void test_map(){
//	
//	//统计单词或者字符出现的次数
//	string str_array[] = {"sort","love","love","binary","second"};
//	//NO.1 : map<string, int> count_map;
//	//NO.2:
//	typedef std::map<std::string,int> CountMap;
//	typedef std::map<std::string, int>::iterator CountMapIter;
//	CountMap count_map;
//	////No.1：传统的方式统计次数
//	//for (auto e:str_array)
//	//{
//	//	CountMapIter it = count_map.find(e);
//	//	if (it != count_map.end()){
//	//		//(*it).second++;
//	//		it->second++;
//	//	}
//	//	else{
//	//		count_map.insert(make_pair(e,1)); 
//	//		//insert在比较时只看key内的内容不看value
//
//	//	}
//	//}
//	////No.2：使用insert的方法统计次数
//	//for (const auto& e : str_array){
//	//	auto ret = count_map.insert(make_pair(e, 1));
//	//	//pair<CountMapIter, bool> ret = count_map.insert(make_pair(e,1));
//	//	//效果相同
//	//	if (ret.second == false){
//	//		//为什么为false查看c++官方文档接口
//	//		ret.first -> second++;
//	//	}
//	
//	//}
//	//若将两份代码同时使用，计数的结果为两种方法计数的和
//
//
//
//	//No.3:operator[]统计次数
//	for (const auto& e:str_array)
//	{
//		count_map[e]++;
//		//运算符重载std::map::operator[]
//		//返回值为value
//	}
//
//	typedef map<string, string> Dict;
//	Dict dict;
//	dict["sort"] = "排序";
//	dict["bug"] = "幺蛾子";
//	dict["left"] = "左边";
//	dict["left"] = "剩余";
//	//当[]中的内容(key)相同的时候，operator[]会对value进行替换
//	//调试可见
//	cout << dict["set"] << endl;
//	//注意这里会插入
//}




#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<time.h>

using namespace std;

#include<set>
void benchmark(){
	size_t n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i){
		v.push_back(rand());
	}

	set<int> s;
	size_t begin1 = clock();
	for (size_t i = 0; i < v.size();i++)
	{
		s.insert(v[i]);
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		s.find(v[i]);
	}
	size_t end1 = clock();
	cout << "set_insert:" << end1 - begin1 << endl;

	
	unordered_set<int> s1;
	size_t begin2 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		s1.insert(v[i]);
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		s1.find(v[i]);
	}
	size_t end2 = clock();
	cout << "unoedered_set_insert:" << end2 - begin2 << endl;
}
//multimap没有operator[]
//排升序键大堆
//找最大的前100个键小堆

int main(){
	benchmark();
	system("pause");
	return 0;
}


