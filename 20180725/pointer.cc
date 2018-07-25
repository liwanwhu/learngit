 ///
 /// @file    pointer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 12:32:21
 ///
 //

#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

int *p1;
int func1()
{
	int num =10;
	return num;
}

int test0(void)
{
	//int *p2;
	int *p2=(int *)malloc(sizeof(int));
	*p2=10;
	printf("p2=%p\n",p2);
	return 0;
}

int main(void)
{
	int a=func1();
	printf("&a=%p\n",&a);
	printf("func1()=%p\n",func1);
	
	const int &ref=func1();



	//test0();
	return 0;
}

