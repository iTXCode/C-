//# if 0
//
//#include<iostream>
//#include<vector>
//
////ֻ��һ�����ֳ���һ���������������������ҳ��Ǹ�ֻ����һ�ε���
////No1�����ķ�ʽ
////���Ľ��������˳���޹�
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
////No2:�������ķ�ʽ
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
////No3:operator[]�ķ�ʽ
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
////�绰�������
////ÿ�������϶��ж�Ӧ����ĸ
////Ҫ���������֣�������ֶ�Ӧ���ַ����������
////�ݹ�ķ���������
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
//		//�ж��Ƿ��������һ��
//		if (digits.size() == depth){
//			strVec.push_back(comStr);
//			return;
//		}
//		//��ȡ��ǰ�����ֵ�ӳ��
//		int mapNum = digits[depth] - '0';
//		string letters = mapletter[mapNum];
//		//�͵�ǰ�����ֵ�ÿһ��ӳ����ĸ����
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
//�������
//��i����i+1��Ԫ��
//v[i][j]=v[i-1][j]+v[i-1][j-1]

#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	vector<vector<int>> generate(int numRows){
		vector<vector<int>>  Matrix;
		
		//��ά��vector
		//����numRows��
		//vector<vector<int>>
		Matrix.resize(numRows);   //vector<int> v;
		for (int i = 0; i < numRows; i++){
			//ÿ�з���i+1��
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

