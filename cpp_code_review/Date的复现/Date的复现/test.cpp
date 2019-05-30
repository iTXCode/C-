#include"Date.h"


void test(){
	Date d(2019, 5, 28);
	d.disPlay();
	Date d1(2019, 1, 28);
	d1.disPlay();
	Date d3 = d + 25;
	d3.disPlay();
	cout << "d-d1="<<d-d1 << endl;
	cout << "d1-d=" << d1 - d << endl;
}

int main(){
	test();
	system("pause");
	return 0;
}