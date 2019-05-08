//#include<iostream>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int main(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	auto it = v.begin();
//	while (it != v.end()){
//		if (*it % 2 == 0){
//			it = v.erase(it);
//		}
//		else{
//			++it;
//		}
//	}
//	for (auto e : v){
//		cout<<e<< " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int main(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	auto it = v.begin();
//	while (it != v.end()){
//			it = v.erase(it);
//			++it;
//		
//	}
//	for (auto e : v){
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}



//µü´úÆ÷Ê§Ð§ 
//#include<iostream>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int main(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	auto it = v.begin();
//	while (it != v.end()){
//		if (*it % 2 == 0){
//			v.erase(it);
//		}
//		++it;
//
//	}
//	for (auto e : v){
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<stack>
#include<windows.h>

using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		_elem.push(x);
		if (_min.empty() || x <= _min.top()){
			_min.push(x);
		}
	}

	void pop() {
		if (_elem.top() == _min.top()){
			_min.pop();
		}
		_elem.pop();
	}

	int top() {

		return _elem.top();

	}

	int getMin() {
		return _min.top();
	}
private:
	std::stack<int> _elem;
	std::stack<int> _min;
};
int main(){
	cout << "haha " << endl;
	system("pause");
	return 0;
}