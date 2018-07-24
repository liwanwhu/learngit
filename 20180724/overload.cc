 ///
 /// @file    overload.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 21:26:50
 ///
#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;

int add(int x,int y)
{
	return x+y;
}

int add(int x,int y,int z)
{
	return x+y+z;
}

double add(double x,double y,double z)
{
	return x+y+z;
}

int main(void)
{
	int a=3,b=4,c=5;
	printf("a+b=%d\n",add(a,b));
	printf("a+b+c=%d\n",add(a,b,c));

	double d1=1.1,d2=2.2,d3=3.3;
	cout<<"d1+d2+d3="<<add(d1,d2,d3)<<endl;

	return 0;
}
