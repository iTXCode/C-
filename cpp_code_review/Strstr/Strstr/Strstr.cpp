//#include<iostream>
//
//using namespace std;
//
//int StrStr(char*s1, char * s2){
//	while (*s1){
//		if (*s1 == *s2){
//			char *str=s1;
//			char *ret = s2;
//			while (*str&&*ret){
//				if (*str != *ret)
//					break;
//				str++;
//				ret++;
//			}
//			if (*ret == '\0')
//				return (str-s1);
//		}
//		s1++;
//	}
//	return 0;
//}
//
//int main(){
//	char *s="hello  world!";
//	cout<<StrStr(s, "world!")<<endl;
//	return 0;
//}

#include<iostream>

using namespace std;

int StrStr( char*s1,  char * s2){
	char *ret = s1;
	char *jun = s1;
	char *str = s2;
	char *ptr = s2;
	while (*ret){
		if (*ret == *str){
			while (*ret&&*str){
				if (*ret != *str)
					break;
				ret++;
				str++;
			}
			if (*str == '\0')
				return (jun - s1);
			str = ptr;
		}
		if (jun != ret){
			ret = jun;
		}
		ret++;
		jun++;
	}
	return 0;
}

int main(){
	char *s = "hell hello  world!";
	cout << s << endl;
	cout << StrStr(s, "hello") << endl;
	return 0;
}