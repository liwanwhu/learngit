 ///
 /// @file    autoRelease.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-01 15:57:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout<<"AutoRelease()"<<endl;
		}
		~AutoRelease()
		{
			if(_pInstance)
				delete  _pInstance;
			cout<<"~AutoRelease()"<<endl;
		}
	};

	static Singleton * getInstance()
	{
		if(!_pInstance)
			_pInstance=new Singleton();
		return _pInstance;
	}

	void print()
	{
		cout<<"this is a Singleton."<<endl;
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
	static Singleton *_pInstance;
	static AutoRelease _autoRelease;
};

Singleton * Singleton::_pInstance=new Singleton();
Singleton::AutoRelease Singleton::_autoRelease;

int main(void)
{
	Singleton *p1= Singleton::getInstance();
	p1->print();
	return 0;
}
