 ///
 /// @file    memberTemplate.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 16:25:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(double dx=0,double dy=0)
	:_dx(dx)
	,_dy(dy)
	{}

	template<typename T>
	T typeCast()
	{
		return (T)_dx *_dy;
	}

private:
	double _dx;
	double _dy;
};

int main(void)
{
	Point pt(1.1,3.2);
	cout<<pt.typeCast<int>()<<endl;

	return 0;
}
