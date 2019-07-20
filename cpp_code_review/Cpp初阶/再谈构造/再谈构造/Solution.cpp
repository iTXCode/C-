#include<iostream>

using namespace std;
#if 0
class solution{
public:
	class sum{
	public:
		sum(){
			
			_sum += _i;
			++_i;
		}
	};
	int sum_solution(int n){
		_sum = 0;
		_i = 1;
		sum arr[10];
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};

int solution::_sum = 0;
int solution::_i = 1;

int main(){
	solution s;
	cout << s.sum_solution(10) << endl;
	return 0;
}
#endif


