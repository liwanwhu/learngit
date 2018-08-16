 ///
 /// @file    memory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 20:15:30
 ///

#include <string.h>
#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;

int a=0;
char *p1;
const int x =100;

int test0(void)
{
	int b;
	char s[]="123456";
	char *p2;
	const char * p3 ="123456";

	static int c=0;
	c++;
	const int y=10;

	p1=new char[10];
	p2=new char[5];
	strcpy(p1,"123456");
	printf("&test0=%p\n",test0);
	printf("&123456=%p\n",&"123456");
	printf("&c=%p\n",&c);
	printf("p3=%p\n",p3);
	printf("&p1=%p\n",&p1);
	printf("&x=%p\n",&x);
	printf("&a=%p\n\n",&a);

	printf("p1=%p\n",p1);
	printf("p2=%p\n\n",p2);

	printf("&y=%p\n",&y);
	printf("&p3=%p\n\n",&p3);

	printf("&b=%p\n",&b);
	printf("s=%p\n",s);
	printf("&p2=%p\n\n",&p2);

	return 0;
}

int main(void)
{
	test0();
	return 0;
}
