 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-26 17:03:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	void print()
	{
		cout<<"singleton()"<<endl;
	}

	static Singleton * getInstance()
	{
		if(!_pSingleton)
			_pSingleton=new Singleton();
		return _pSingleton;
	}

	static void destory()
	{
		if(_pSingleton)
			delete  _pSingleton;
		cout<<"destory"<<endl;
	}
private:
	Singleton()
	{
		cout<<"Singleton()"<<endl;
	}
	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}
private:
	static Singleton * _pSingleton;
};

Singleton *Singleton::_pSingleton=NULL;

int main(void)
{
	Singleton *p1= Singleton::getInstance();
	p1->print();
	Singleton::destory();
	return 0;
}
