 ///
 /// @file    bindFigure.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-14 23:49:16
 ///
 
#include <math.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;

class Circle
{
public:
	Circle(double radius)
	:_radius(radius)
	{}

	void display() const 
	{
		cout<<"circle";
	}

	double area()
	{	return 3.14*_radius*_radius;	}

private:
	double _radius;
};

class Rectangle
{
public:
	Rectangle(double length,double width)
	:_length(length)
	,_width(width)
	{}

	void show() const
	{	cout<<"rectangle";	}

	double getArea()
	{	return _length*_width;	}

private:
	double _length;
	double _width;
};

class Triangle
{
public:
	Triangle(double a,double b,double c)
	:_a(a)
	,_b(b)
	,_c(c)
	{}

	void print() const
	{	cout<<"trangle";	}

	double calArea()
	{	double tmp=(_a+_b+_c)/2;
		return sqrt(tmp*(tmp-_a)*(tmp-_b)*(tmp-_c));
	}

private:
	double _a;
	double _b;
	double _c;
};

class Figure
{
public:
	using DisplayCallback=std::function<void()>;
	using AreaCallback=std::function<double()>;

	void setDisplayCallback(DisplayCallback && cb)
	{
		_displayCallback=std::move(cb);
	}

	void setAreaCallback(AreaCallback && ac)
	{
		_areaCallback = std::move(ac);
	}

	void handleDisplay()
	{
		if(_displayCallback)
			_displayCallback();
	}

	double handleAreaCallback()
	{
		if(_areaCallback)
			return _areaCallback();
		else 
			return 0;
	}

private:
	DisplayCallback _displayCallback;
	AreaCallback _areaCallback;
};

void test(Figure & fig)
{
	cout<<"the area of ";
	fig.handleDisplay();
	cout<<" is "<<fig.handleAreaCallback()<<endl;
}
int main(void)
{
	Circle circle(3);
	Rectangle rectangle(2,3);
	Triangle triangle(3,4,5);

	Figure fg;
	fg.setDisplayCallback(std::bind(&Circle::display,&circle));
	fg.setAreaCallback(std::bind(&Circle::area,&circle));
	test(fg);

	fg.setDisplayCallback(std::bind(&Rectangle::show,&rectangle));
	fg.setAreaCallback(std::bind(&Rectangle::getArea,&rectangle));
	test(fg);

	fg.setDisplayCallback(std::bind(&Triangle::print,&triangle));
	fg.setAreaCallback(std::bind(&Triangle::calArea,&triangle));
	test(fg);
	return 0;
}
