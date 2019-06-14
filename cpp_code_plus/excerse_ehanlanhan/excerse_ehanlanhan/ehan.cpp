#if 0
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
	Singnalton &operator =(Singnalton const&) = delete;
	static Singnalton  _sin;
};

Singnalton Singnalton::_sin;

int main(){
	Singnalton *s = Singnalton::getSingnalton();
	Singnalton *rs = Singnalton::getSingnalton();
	//实现的两个类指针指向同一快地址
	return 0;
}
#endif



#include<iostream>

using namespace std;

class Singleton{
public:
	static Singleton* getSingleton(){
		if (_sin == nullptr){
			_sin = new Singleton;
		}
		return _sin;
	}
private:
	Singleton(){};
	Singleton(const Singleton& s) = delete;
	static Singleton *_sin;
};

Singleton Singleton::*_sin = nullptr;

int main(){
	Singleton *s = Singleton::getSingleton();
	Singleton *rs = Singleton::getSingleton();
	return 0;
}

