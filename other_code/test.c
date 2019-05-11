#include<iostream>

using namespace std;

class Date{
 public:
   Date(int year,int month,int day)
   :_year(year)
    ,_month(month)
    ,_day(day)
   {
    cout<<_year<<"年:"<<_month<<"月:"<<_day<<"日"<<endl;
   }
 private:
   int _year;
   int _month;
   int _day;
};

int main(){
  Date date(1997,8,1);
  return 0;
}
