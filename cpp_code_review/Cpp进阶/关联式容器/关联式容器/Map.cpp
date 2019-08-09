#if 0

#include<iostream>
#include<map>
#include<string>
#include <functional>
using namespace std;

//void test(){
//	map<string, string> dictMap;
//	dictMap.insert(make_pair("中国", "China"));
//	dictMap.insert(make_pair("日本", "Japanese"));
//	//注意map容器的插入方式
//	dictMap["西安"] = "xi,an";
//	auto dit = dictMap.begin();
//	while (dit != dictMap.end()){
//		cout << dit->first << " " << dit->second << endl;
//		++dit;
//	}
//}
void testMap(){
	map<int,string, greater<int>> testMap;
	testMap[8] = "中国";
	testMap[2] = "美国";
	testMap[1] = "法国";
	testMap[3] = "阿拉伯";
	testMap[10] = "伊拉克";
	testMap[9] = "西安";
	testMap.insert(make_pair(11,"英国"));
	for (const auto& e : testMap){
		cout << e.first << " " << e.second << endl;
	}
	int key;
	/*while (cin >> key){
		if (testMap.count(key))
		cout << key<<"-->" << testMap[key] << endl;
		else
		cout << "not dind key:" << key << endl;
		}*/
	cin >> key;
	//find的迭代器的使用
	if (testMap.find(key) != testMap.end()){
		cout << testMap[key] << endl;
	}
	
}
int main(){
	testMap();
	return 0;
}

#endif

#if 0
//map迭代器的使用
#include<iostream>
#include <string>
#include <map>

using namespace std;

void TestMap()
{
	map<string, string> m{ { "apple", "苹果" },
	{ "banan", "香蕉" },
	{ "orange", "橘子" },
	{ "peach", "桃子" },
	{ "waterme", "水蜜桃" } };
	cout << endl;
	for (auto it = m.begin(); it != m.end(); ++it)
		cout<< (*it).first << "--->" << it->second << endl;
	cout<< endl;
	
}

int main(){
	TestMap();
	return 0;
}

#endif


#if 0
#include<iostream>
#include <string>
#include <map>

using namespace std;
void TestMap()
{
	// 构造一个空的map，此时m中一个元素都没有
	map<string, string> m;
	/*
	operator[]的原理是：
	用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中
	如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器
	如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器
	operator[]函数最后将insert返回值键值对中的value返回
	*/
	// 将<"apple", "">插入map中，插入成功，返回value的引用，将“苹果”赋值给该引用结果，
	// 即修改与"apple"对应的value""为"苹果"
	m["apple"] = "苹果";
	// 将<"apple", "">插入map中，插入失败，将<"apple", "苹果">中的"苹果"返回
	cout << m["apple"] << endl;
	cout << m.size() << endl;
	// “banan不在map中，该函数抛异常”
	m.at("banan");
}

int  main(){
	TestMap();
	return 0;
}
#endif
//【测试multimap】

#include<iostream>
#include<map>
#include<string>
#include <functional>
using namespace std;

void testMap(){
	
		multimap<int, string, greater<int>> testMap;
		//multimap：不提供[]操作，key不唯一
		//键值可以重复
		/*testMap[8] = "中国";
		testMap[2] = "美国";
		testMap[1] = "法国";
		testMap[3] = "阿拉伯";
		testMap[10] = "伊拉克";*/

		testMap.insert(make_pair(1, "中国"));
		testMap.insert(make_pair(2, "美国"));
		testMap.insert(make_pair(3, "英国"));
		testMap.insert(make_pair(7, "法国"));
		testMap.insert(make_pair(8, "德国"));
		testMap.insert(make_pair(9, "阿拉伯国"));
		cout << testMap.count(1) << endl;
		for ( const auto& e : testMap){
			cout << e.first << "-->" << e.second << endl;
		}

		//选择键值大于等于给定数字的值
		auto mit = testMap.lower_bound(3);
		cout << mit->first<<"-->"<<mit->second << endl;
		//选择键值小于给定数字的值
		mit = testMap.upper_bound(3);
		cout << mit->first << "-->" << mit->second << endl;
	}

int main(){
	testMap();
	return 0;
}



#if 0
#include<iostream>
#include<set>
#include<string>
#include <functional>
using namespace std;

void testset(){

	set<int> testSet;
	testSet.insert(1);
	testSet.insert(2);
	testSet.insert(4);
	testSet.insert(6);
	testSet.insert(5);
	testSet.insert(9);
	for (const auto& e : testSet){
		cout << e << endl;
	}
//自动排序(从大到小)，自动去重 
}

int main(){
	testset();
	return 0;
}
#endif


#if  0
#include<iostream>
#include<set>
#include<string>
#include <functional>
using namespace std;

void testset(){

	multiset<int> testSet;
	testSet.insert(1);
	testSet.insert(1);
	testSet.insert(1);
	testSet.insert(2);
	testSet.insert(4);
	testSet.insert(6);
	testSet.insert(5);
	testSet.insert(9);
	for (const auto& e : testSet){
		cout << e << endl;
	}
	//自动排序(从小到大),可以重复 
}

int main(){
	testset();
	return 0;
}
#endif

