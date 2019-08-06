//#include<iostream>
//#include<map>
//#include<string>
//#include <functional>
//using namespace std;
//
//void test(){
//	map<string, string> dictMap;
//	dictMap.insert(make_pair("中国", "China"));
//	dictMap.insert(make_pair("日本", "Japanese"));
//	dictMap["西安"] = "xi,an";
//	auto dit = dictMap.begin();
//	while (dit != dictMap.end()){
//		cout << dit->first << " " << dit->second << endl;
//		++dit;
//	}
//}
//void testMap(){
//	map<int,string, greater<int>> testMap;
//	testMap[8] = "中国";
//	testMap[2] = "美国";
//	testMap[1] = "法国";
//	testMap[3] = "阿拉伯";
//	testMap[10] = "伊拉克";
//	for (const auto& e : testMap){
//		cout << e.first << " " << e.second << endl;
//	}
//	int key;
//	/*while (cin >> key){
//		if (testMap.count(key))
//		cout << key<<"-->" << testMap[key] << endl;
//		else
//		cout << "not dind key:" << key << endl;
//		}*/
//	cin >> key;
//	//find的迭代器的使用
//	if (testMap.find(key) != testMap.end()){
//		cout << testMap[key] << endl;
//	}
//	
//}
//int main(){
//	testMap();
//	return 0;
//}




//【测试multimap】
#if 0
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

#endif

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