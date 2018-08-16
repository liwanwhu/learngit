 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-26 17:03:27
 ///

#include "point.h"
#include "computer.h"

#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;
template <typename Type>
class Singleton
{
public:
	void print()
	{
		cout<<"singleton()"<<endl;
	}

	template<typename... Args>
	static Type * getInstance(Args... args)
	//static Type * getInstance()
	{
		if(!_pType)
			_pType=new Type(args...);
		return _pType;
	}

	static void destory()
	{
		if(_pType)
			delete  _pType;
		cout<<"destory"<<endl;
	}
private:
	Singleton()
	{
		cout<<"Singleton()"<<endl;
		//Type(args...);
	}
	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}
private:
	static Type * _pType;
};
template<typename Type>
Type * Singleton<Type>::_pType=NULL;

int main(void)
{
	Computer * p1 = Singleton<Computer>::getInstance("Xiaomi",6666);
	Computer * p2 = Singleton<Computer>::getInstance("Xiaomi",6666);

	Point * p3 =Singleton<Point>::getInstance(1,2);
	Point * p4 =Singleton<Point>::getInstance(1,2);

#if 0
	Computer * p1 = Singleton<Computer>::getInstance();
	Computer * p2 = Singleton<Computer>::getInstance();

	Point * p3 =Singleton<Point>::getInstance();
	Point * p4 =Singleton<Point>::getInstance();
#endif
	printf("p1:%p\n",&(*p1));
	printf("p2:%p\n",&(*p2));
	printf("p3:%p\n",&(*p3));
	printf("p4:%p\n",&(*p4));
	return 0;
}
