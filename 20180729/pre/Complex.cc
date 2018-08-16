 ///
 /// @file    Complex.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-30 23:50:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal,double dimag)
	:_dreal(dreal)
	,_dimage(dimag)
	{}

	void display()
	{
		if(_dimage>0)
		{
			cout<<_dreal<<"+"<<_dimage<<"i"<<endl;
		}
		else if(_dimage==0){
			cout<<_dreal<<endl;
		}else{
			cout<<_dreal<<_dimage<<"i"<<endl;
		}
	}

	Complex & operator++()
	{
		++_dreal;
		++_dimage;
		return *this;
	}

	Complex  operator++(int)
	{
		Complex tmp(*this);
		++_dreal;
		++_dimage;
		return tmp;
	}
friend Complex operator+(const Complex & lhs,const Complex & rhs);
private:
	double _dreal;
	double _dimage;
};

Complex operator+(const Complex & lhs,const Complex & rhs)
{
#if 0
	Complex tmp;
	tmp._dreal=c1._dreal+c2._dreal;
	tmp._dimage=c1._dimage+c2._dimage;
	return tmp;
#endif
	return Complex(lhs._dreal+rhs._dreal,
				   lhs._dimage+rhs._dimage);
}

int test1(void)
{
	Complex c1(1,-2);
	cout<<"c1=";
	c1.display();

	cout<<"++c1=";
	(++c1).display();
	cout<<"c1=";
	c1.display();
	
	cout<<endl;
	cout<<"c1++=";
	(c1++).display();
	cout<<"c1=";
	c1.display();

	return 0;
}
int test0(void)
{
	Complex c1(1,-2);
	c1.display();

	Complex c2(-3,4);
	c2.display();

	Complex c3=c1+c2;
	c3.display();

	Complex c4(0,0);
	c4.display();
	Complex c5(0,-1);
	c5.display();

	return 0;
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
