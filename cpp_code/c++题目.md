### String 题目

##### string类反转字符串

````C ++
#include<iostream>
#include<string>

using namesapce std;

string reverseString(string s){
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end){
		swap(s[begin], s[end]);
		end--;
		begin++;
	}
	return s;
}


int main(){
	string s("hello bit!");
	cout <<"s="<< s << endl;
	cout << "reverseString(s)=" << reverseString(s) << endl;
	return 0;
}
````

##### 字符串的的第一个唯一的字符,返回其在字符串中位置下标

###### NO1:

````c ++
#include<iostream>
#include<string>

using namesapce std;
class Solution{
public:
	int fristUniqChar(string s){
		int hashT[256] = { 0 };
		for (auto& e : s){
			hashT[e]++;
		}
		for (int i = 0; i < s.size(); i++){
			if (hashT[s[i]] == 1)
				return i;
		}
		return -1;
	}
};

int main(){
	string s = "hello";
	Solution s1;
	cout << s1.fristUniqChar(s) << endl;
	return 0;
}
````

###### NO2:

````c ++
#include<iostream>
#include<string>

using namesapce std;
int main(){
	string s;
	while (cin >> s){
		int hashT[256] = { 0 };
		for (auto& e : s){
			hashT[e]++;
		}
		int i;
		for (i = 0; i < s.size(); i++){
			if (hashT[s[i]] == 1){
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size()){
			cout << -1 << endl;
		}
	}
	
	return 0;
}
````

##### 字符串中最后一个单词的长度,单词以空格隔开

````c ++
#include<iostream>
#include<string>

using namespace std;
int main(){
	string s;
	while(getline(cin, s)){
        //getline 遇到换行结束
		size_t pos = s.rfind(' ');
		if (pos == string::npos){
			cout << s.size() << endl;
		}
		else{
			cout << s.size() - pos - 1 << endl;
		}
	}
	return 0;
}
````

##### 判断回文

> 判断是否为数字
>
> 1.一个循环从前往后遍历
>
> 2.一个循环从后往前遍历
>
> 3.一个大循环判断时候符合条件

````c ++
#include<iostream>
#include<string>

using namespace std;
class Solution{
public:
	bool isNumberLetter(char c){
		return (c >= '0'&&c <= '9')
			|| (c >= 'a'&&c <= 'z')
			|| (c >= 'A' <= 'Z');
	}
	
	bool isPalindrome(string s){
		int begin = 0;
		int end = s.size() - 1;
		//所有的小写转大写
		for (auto&e : s){
			if (e >= 'a'){
				e -= 32;
			}
		}
		while (begin < end){
			while (begin < end){
				//从前完后找到第一个字母或数字
				if (isNumberLetter(s[begin]))
					break;
				begin++;
			}
			while (begin < end){
				//从前往后找到最后一个字母或者数字
				if (isNumberLetter(s[end]))
					break;
				end--;
			}
			//比较begin和end位置的字符
			//大小写字母相差32
			if (s[begin] % 32 != s[end] % 32){
				//存在取模后值相等的情况
				//if((s[begin]+32-'a')%32!=(s[end]+32-'a')%32)
				return false;
			}
			if (s[begin] != s[end])
				return false;
				begin++;
			    end--;
		}
		return true;
	}
};

int  main(){
	string s = "H0POPPOP0H";
	Solution s1;
	cout << s1.isPalindrome(s) << endl;
	return 0;
}
````

##### 字符串相加

**【字符串转整形】char - '0'--->int**

**两个数字相加取值范围[0~18]**

**当前位值=(第一个数当前位+第二个数当前位的值+上一位的进位%10**

**当前位的进位=(第一个数当前位+第二个数当前位的值+上一位的进位/10**

````c ++
class Solution{
public:
	string addstrings(string num1, string num2){
		int end1 = num1.size() - 1;
         int end2 = num2.size() - 1;
		string retstr;
		//进位
		char next = 0;
		while (end1 >= 0 && end2 >= 0){
			char value1 = 0;
			if (end1 >= 0){
				value1 = num1[end1] - '0';
			}
			char  value2 = 0;
			if (end2 >= 0){
				value2 = num2[end2] - '0';
			}
			char addvalue = value1 + value2 + next;
			if (addvalue>90){
				next = 1;
				addvalue -= 10;
			}
			else{
				next = 0;
			}
			retstr.insert(retstr.begin(), addvalue + '0');
            //头插
			--end1;
			--end2;
		}
		if (next == 1)
			retstr.insert(retstr.begin(), '1');
		return retstr;
	}
};
````

##### 版本改进

````c ++
class Solution{
public:
	string addstrings(string num1, string num2){
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		string retstr;
       retstr.reserve(num1.size()>num2.size()?          num1.size()+1:um2.szie()+1);
		//进位
		char next = 0;
		while (end1 >= 0 && end2 >= 0){
			char value1 = 0;
			if (end1 >= 0){
				value1 = num1[end1] - '0';
			}
			char  value2 = 0;
			if (end2 >= 0){
				value2 = num2[end2] - '0';
			}
			char addvalue = value1 + value2 + next;
			if (addvalue>90){
				next = 1;
				addvalue -= 10;
			}
			else{
				next = 0;
			}
			retstr+=(addvalue+'0');
			--end1;
			--end2;
		}
		if (next == 1)
			retstr+='1';
        //reverse(retstr.begin(),retstr.end());
        //和上面的注释掉的那句搭配使用
		return retstr;
	}
};
````

###### NO2

````c ++

````

