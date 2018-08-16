
 
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


