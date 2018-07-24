 ///
 /// @file    inline.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 21:40:33
 ///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

#define Max(x,y) (x)>(y)?x:y
#define Multiply(x,y) (x)*(y)
inline
int max(int x,int y)
{
	return x>y?x:y;
}

inline
int multiply(int x,int y)
{
	return x*y;
}

int main(void)
{
	int a=3,b=4,c=5;
	printf("Max(a.b)=%d\n",Max(a,b));
	printf("Multiply(a+b.c)=%d\n",Multiply(a+b,c));
	cout<<max(a,b)<<endl;
	cout<<multiply(a+b,c)<<endl;
	return 0;
}

