//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//#include<set>
////使用set的方法，属于std命名空间
////set的作用
////1.key的模型场景，判断在不在？
////2.排序+去重(不会允许相同的数据进去)
//
//void test_set(){
//	set<int> a1;  
//	a1.insert(9);
//	a1.insert(8);
//	a1.insert(7);
//	//2.排序+去重(不会允许相同的数据进去)
//	a1.insert(6);
//	a1.insert(6);
//	a1.insert(6);
//	a1.insert(6);
//	//只输出一个6
//	set<int> ::iterator it1 = a1.begin(); 
//	while (it1 != a1.end()){
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//	//打印出来的结果按照从小到大的顺序自动进行了排序
//	//底层是搜索二叉树，迭代器按中序进行搜索
//	//用它排序代价比较大
//
//	
//	
//	//1.key的模型场景，判断在不在？
//
//	//查找某个元素的情况
//	int  x = 0;
//	cin >> x;
//	auto ret = a1.find(x);  //优势:时间复杂度小O(logN)
//	//找不到就会返回迭代器的末端set::end
//	if (ret != a1.end()){
//		cout << x<< "在a1的集合中" << endl;
//		a1.erase(ret);
//	}
//	else{
//		cout << x << "不在a1的集合中" << endl;
//	}
//
//	for (auto e : a1)
//	{
//		cout << e << " ";
//		//简化版
//	}
//	cout << endl;
//}
//
//int main(){
//	test();
//	system("pause");
//	return 0;
//	
//}

//multiset的应用 
//#include<iostream>
//#include<windows.h>
//#include<string>
//using namespace std;
//
//#include<set>
//
//void test_multiset(){
//	//multiset底层仍是搜索树,不会去重
//	//用来排序，不去重
//	multiset<int> s1;
//	s1.insert(10);
//	s1.insert(1);
//	s1.insert(3);
//	s1.insert(5);
//	s1.insert(9);
//	s1.insert(110);
//	s1.insert(120);
//
//	for (auto e : s1){
//		cout << e << " ";
//	}
//	cout << endl;
//
//	multiset <string> names;
//	names.insert("Lining");
//	names.insert("sort");
//	names.insert("fight");
//	multiset<string> ::iterator it = names.begin();
//	while (it != names.end()){
//		cout << it<< endl;
//		it++;
//	}
//	
//}
//
//int main(){
//	test_multiset();
//	system("pause");
//	return 0;
//
//}