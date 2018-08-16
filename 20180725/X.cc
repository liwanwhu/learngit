 ///
 /// @file    X.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 23:00:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Demo
{

public:
	Demo(int iy)
	:_iy(iy)
	,_ix(_iy)
	{
		cout<<"Demo(int)"<<endl;
	}
	
	void print()
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}

private:
	int _iy;
	int _ix;
};

int main(void)
{
	Demo demo(10);
	demo.print();
}
