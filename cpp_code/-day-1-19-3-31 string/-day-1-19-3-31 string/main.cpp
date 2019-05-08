//class Solution{
//public:
//	string addstrings(string num1, string num2){
//		int end1 = num1.size() - 1, end2 = num2.size() - 1;
//		string retstr;
//		//进位
//		char next = 0;
//		while (end1 >= 0 && end2 >= 0){
//			char value1 = 0;
//			if (end1 >= 0){
//				value1 = num1[end1] - '0';
//			}
//			char  value2 = 0;
//			if (end2 >= 0){
//				value2 = num2[end2] - '0';
//			}
//			char addvalue = value1 + value2 + next;
//			if (addvalue>90){
//				next = 1;
//				addvalue -= 10;
//			}
//			else{
//				next = 0;
//			}
//			retstr.insert(retstr.begin(), addvalue + '0');
//			--end1;
//			--end2;
//		}
//		if (next == 1)
//			retstr.insert(retstr.begin(), '1');
//		return retstr;
//	}
//};

//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//int main(){
//	char a1[]= "\0";//\0 被认为是一个字符，转义字符
//	cout << sizeof(a1) << endl;  //2
//	cout << strlen(a1) << endl;  //0
//
//
//	char a2[] = "\\0";
//	cout << sizeof(a2) << endl; //3
//	cout << strlen(a2) << endl;//2
//
//	char a3[]= "0000";
//	cout << sizeof(a3) << endl;//5
//	cout << strlen(a3) << endl;//4
//
//	char a4[]= "\0000";  // \000 0 \0      
//	cout << sizeof(a4) << endl;//3
//	cout << strlen(a4) << endl;//0
//
//
//	char a5[] = "\000 0";        
//	cout << sizeof(a5) << endl;//4
//	cout << strlen(a5) << endl;//0
//
//	char a6[] = "\0 000";
//	cout << sizeof(a5) << endl;//6
//	cout << strlen(a5) << endl;//0
//
//	system("pause");
//	return 0;
//}


