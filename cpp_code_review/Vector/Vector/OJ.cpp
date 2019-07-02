//# if 0
//
//#include<iostream>
//#include<vector>
//
////只有一个数字出现一次其他的数均出现两次找出那个只出现一次的数
////No1：异或的方式
////异或的结果与异或的顺序无关
////using namespace std;
////class Single{
////public:
////	int singleNumber(vector<int>& nums){
////		int ret = 0;
////		for (auto &e : nums){
////			ret = ret^e;
////		}
////		return ret;
////	}
////};
//
////No2:迭代器的方式
////using namespace std;
////class Single{
////public:
////	int singleNumber(vector<int>& nums){
////		auto vit = nums.begin();
////		int ret = 0;
////		while (vit != nums.end()){
////			ret ^= *vit;
////			vit++;
////		}
////		return ret;
////	}
////};
//
////No3:operator[]的方式
//using namespace std;
//class Single{
//public:
//	int singleNumber(vector<int>& nums){
//		int ret = 0;
//		for (int i = 0; i < nums.size(); i++){
//			ret ^= nums[i];
//		}
//		return ret;
//	}
//};
//
//
//int main(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(3);
//	v.push_back(1);
//	v.push_back(4);
//	Single s;
//	cout<<s.singleNumber(v)<<endl;
//	return 0;
//}
//
//#endif 
//
//
////电话号码组合
////每个按键上都有对应的字母
////要求输入数字，输出数字对应的字符的两两组合
////递归的方法来解题
//#include<iostream>
//#include<vector>
//#include<string>
//#include<string.h>
//using namespace std;
//
//class Solution{
//	string mapletter[10] = { " ", " ", "abc", "def", "ghi",
//	"jkl", "mno", "pqrs", "tuv", "wyzx" };
//public:
//	
//	void combination(string &digits, int depth, const string& comStr,
//		vector<string>& strVec)
//	{
//		//判断是否走完最后一层
//		if (digits.size() == depth){
//			strVec.push_back(comStr);
//			return;
//		}
//		//获取当前层数字的映射
//		int mapNum = digits[depth] - '0';
//		string letters = mapletter[mapNum];
//		//和当前层数字的每一个映射字母相结合
//		for (auto &e : letters){
//			combination(digits, depth + 1, comStr + e, strVec);
//		}
//	}
//	vector<string> letterCombinations(string digits){
//		vector<string> strVec;
//		if (digits.empty()){
//			return strVec;
//		}
//		string s;
//		combination(digits, 0, s, strVec);
//	}
//};
//
//int main(){
//	string s;
//	cin >> s;
//	Solution s1;
//	s1.letterCombinations(s);
//	return 0;
//}
//
//


#if 0
//杨辉三角
//第i行有i+1个元素
//v[i][j]=v[i-1][j]+v[i-1][j-1]

#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	vector<vector<int>> generate(int numRows){
		vector<vector<int>>  Matrix;
		
		//二维的vector
		//分配numRows行
		//vector<vector<int>>
		Matrix.resize(numRows);   //vector<int> v;
		for (int i = 0; i < numRows; i++){
			//每行分配i+1列
			//vector<int>
			Matrix[i].resize(i + 1,1);
			
		}
		for (int i = 2; i < numRows; i++){
			for (int j = 1; j < i; j++){
				Matrix[i][j] = Matrix[i - 1][j] + Matrix[i - 1][j - 1];

			}
		}
		for (int i = 0; i < numRows; i++){
			for (int j = 0; j < i+1; j++){
				cout << Matrix[i][j] << " ";

			}
			cout << endl;
		}
		return Matrix;
	}
};


int main(){
	Solution s;
	s.generate(10);
	return 0;
}
#endif

