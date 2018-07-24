 ///
 /// @file    default.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 22:00:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int add(int x,int y=10){
	return x+y;
}

int main(void)
{
	int a=3,b=4;
	cout<<"a+b="<<add(a,b)<<endl;
	return 0;
}
