 ///
 /// @file    myString_main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 19:49:27
 ///
 
#include "myString.h"

#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	String str1;
	str1.print();

	String str2="Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4=str2;
	str4.print();

	printf("1=%p",str1);
	printf("2=%p",str2);
	printf("3=%p",str3);
	printf("4=%p",str4);
	return 0;
}

