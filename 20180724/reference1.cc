 ///
 /// @file    reference1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 22:03:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void swap(int &x,int &y){
	int tmp=x;
	x=y;
	y=tmp;
}
int main()
{
	int a=3,b=4;
	cout<<a<<" "<<b<<endl;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
	return 0;
}
