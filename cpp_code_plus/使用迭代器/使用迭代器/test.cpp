#include<iostream>
#include<vector>
#include<string>
using namespace std;

int  main(){
	string s("yang zi jun");
	string::iterator sit = s.begin();
	while (sit != s.end()){
		cout << *sit;
		++sit;
	}
	//普通的迭代器
	cout << endl;
	//vector迭代器的使用
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> visit_arr(arr, arr + 10);
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