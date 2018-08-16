 ///
 /// @file    copyContructorPoint.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 23:39:22
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
		cout << "Point()"<<endl;
	}

	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)"<<endl;
	}

	Point(const Point & rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	{
		cout<<"Point(const Point &)"<<endl;
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

int test0(void)
{
	Point pt1(1,2);
	cout<<"pt1=";
	pt1.print();
	cout<<endl;

	Point pt2 =pt1;
	cout<<"pt2=";
	pt2.print();

	return 0;
}


int main(void)
{
	test0();
	return 0;
}
