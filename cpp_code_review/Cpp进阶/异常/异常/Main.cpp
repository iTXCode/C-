#if 0
#include<iostream>

using namespace std;

int Division(int a,int b){
	if (b == 0)
		throw("Division by zero!");
	return a / b;
}

int main(){
	int a, b;
	cin >> a>>b;
	try{
		Division(a, b);
	}
	catch (const int a){
		cout << a << endl;
	}
	catch (const char c){
		cout << c << endl;
	}
	catch (const char* str){
		cout << str << endl;
	}
	return 0;
}
#endif

#include<iostream>

using namespace std;

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		//当与之配对的try块中代码无异常抛出的时候,则跳过该逻辑执行之后的代码
		cout << "delete []" << array << endl;
		//先将空间释放再将异常重新抛出，避免其他接口捕捉到后不释放空间导致内存泄漏
		delete[] array;
		throw;
		
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}

	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}