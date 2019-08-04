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
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		//����֮��Ե�try���д������쳣�׳���ʱ��,���������߼�ִ��֮��Ĵ���
		cout << "delete []" << array << endl;
		//�Ƚ��ռ��ͷ��ٽ��쳣�����׳������������ӿڲ�׽�����ͷſռ䵼���ڴ�й©
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