 ///
 /// @file    point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 21:13:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{

public:
	Point()
	:_ix(0)
	,_iy(0)
	{
		cout<<"Point()"<<endl;
	}

	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}

	void print()
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}

	~Point()
	{
		cout<<"~Point()"<<endl;
	}

private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt;
	pt.print();

	Point pt2(1,2);
	pt2.print();
	pt2.~Point();

	int a=3;
	int b(4);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;

	return 0;

}
