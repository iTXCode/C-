
#define _CRT_CESURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

class String{
public:
	String(char *str=" ")
		:_size(0)
		, _capacity(0)
		, _str()
	{

	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

int main(){

	return 0;
}