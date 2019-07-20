#include<iostream>

using namespace std;

class Singnalton{
public:
	static Singnalton* getSingnalton(){
		return &_sin;
	}
private:
	Singnalton(){};
	Singnalton(const Singnalton& s) = delete;
	//Singnalton &operator =(Singnalton const&) = delete;
	static Singnalton  _sin;
};

Singnalton Singnalton::_sin;

int main(){
	Singnalton *s = Singnalton::getSingnalton();
	Singnalton *rs = Singnalton::getSingnalton();
	return 0;
}