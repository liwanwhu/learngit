 ///
 /// @file    autoRelease2.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-01 15:57:04
 ///
#include <pthread.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:

	static Singleton * getInstance()
	{
		pthread_once(&_once,init);
		return _pInstance;
	}
	void print()
	{
		cout<<"this is a Singleton."<<endl;
	}


private:
	static void init()
	{
		_pInstance=new Singleton();
		atexit(destory);
	}
	
	static void destory()
	{
		delete _pInstance;
	}

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
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance=NULL;
pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton *p1= Singleton::getInstance();
	p1->print();
	return 0;
}
