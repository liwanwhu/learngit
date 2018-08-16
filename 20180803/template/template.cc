 ///
 /// @file    template.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 15:02:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename Type>
Type add(Type x, Type y)
{
	return x+y;
}

int main(void)
{
	int a=3,b=4;
	cout<<add(a,b)<<endl;
	double x=1.1, y=2.2;
	cout<<add(x,y)<<endl;
	return 0;
}
