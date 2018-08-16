 ///
 /// @file    Circle.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-15 11:03:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Circle
{
public:
	Circle(double radius=0)
	:_radius(radius)
	{
	}

	double getArea()
	{
		return 3.14*_radius*_radius;
	}

	double getPerimeter()
	{
		return 2*3.14*_radius;
	}

	void show()
	{
		cout<<"the radius is "<<_radius<<endl;
		cout<<"the perimeter is " <<getPerimeter()<<endl;
		cout<<"the area is "<<getArea()<<endl;
	}

protected:
	double _radius;
};

class Cylinder
:public Circle
{
public:
	Cylinder(double r,double h)
	:Circle(r)
	,_high(h)
	{}

	double getVolume()
	{
		return 2*3.14*_radius*_high;
	}

	void showVolume()
	{
		cout<<"the volume is "<<getVolume()<<endl;
	}

private:
	double _high;
};

int main(void)
{
	Circle circle(10);
	circle.show();

	cout<<endl;
	Cylinder cylinder(10,20);
	cylinder.showVolume();

	return 0;

}
	
