#include"Date.h"
#include<stdlib.h>
void testDate(){
	Date d1(2019, 5, 27);
	d1.disPlay();
	Date d2(2019, 6, 1);
	d2.disPlay();
	d1++;
	cout << "d1++:";
	d1.disPlay();
	d2++;
	cout << "d1++:" ;
	d2.disPlay();
	Date d3=d1 + 25;
	cout << "d1 + 25:";
	d3.disPlay();
	Date d4 = d2 - 52;
	cout << "d2 - 52:";
	d4.disPlay();
}

void testDate2(){

	Date d5(2019, 5, 1);
	cout << "d5:";
	d5.disPlay();
	Date d6(2019, 1, 1);
	cout << "d6:";
	d6.disPlay();
	int d7 = d5 - d6;
	cout << "d7:";
	cout << d7 << endl;
    int d8 = d6 - d5;
	cout << d8 << endl;
	cout << " d5>d6:" << (d5 > d6) << endl;
	cout << " d6>d5:" << (d6 > d5) << endl;
}

int main(){
	testDate();
	testDate2();
	system("pause");
	return 0;
}

