# if 0

#include<iostream>
#include<vector>

//ֻ��һ�����ֳ���һ���������������������ҳ��Ǹ�ֻ����һ�ε���
//No1�����ķ�ʽ
//���Ľ��������˳���޹�
//using namespace std;
//class Single{
//public:
//	int singleNumber(vector<int>& nums){
//		int ret = 0;
//		for (auto &e : nums){
//			ret = ret^e;
//		}
//		return ret;
//	}
//};

//No2:�������ķ�ʽ
//using namespace std;
//class Single{
//public:
//	int singleNumber(vector<int>& nums){
//		auto vit = nums.begin();
//		int ret = 0;
//		while (vit != nums.end()){
//			ret ^= *vit;
//			vit++;
//		}
//		return ret;
//	}
//};

//No3:operator[]�ķ�ʽ
using namespace std;
class Single{
public:
	int singleNumber(vector<int>& nums){
		int ret = 0;
		for (int i = 0; i < nums.size(); i++){
			ret ^= nums[i];
		}
		return ret;
	}
};


int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	Single s;
	cout<<s.singleNumber(v)<<endl;
	return 0;
}

#endif 


//�绰�������
//ÿ�������϶��ж�Ӧ����ĸ
//Ҫ���������֣�������ֶ�Ӧ���ַ����������
//�ݹ�ķ���������
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

class Solution{
	string mapletter[10] = { " ", " ", "abc", "def", "ghi",
	"jkl", "mno", "pqrs", "tuv", "wyzx" };
public:
	
	void combination(string &digits, int depth, const string& comStr,
		vector<string>& strVec)
	{
		//�ж��Ƿ��������һ��
		if (digits.size() == depth){
			strVec.push_back(comStr);
			return;
		}
		//��ȡ��ǰ�����ֵ�ӳ��
		int mapNum = digits[depth] - '0';
		string letters = mapletter[mapNum];
		//�͵�ǰ�����ֵ�ÿһ��ӳ����ĸ����
		for (auto &e : letters){
			combination(digits, depth + 1, comStr + e, strVec);
		}
	}
	vector<string> letterCombinations(string digits){
		vector<string> strVec;
		if (digits.empty()){
			return strVec;
		}
		string s;
		combination(digits, 0, s, strVec);
	}
};

int main(){
	string s;
	cin >> s;
	Solution s1;
	s1.letterCombinations(s);
	return 0;
}


