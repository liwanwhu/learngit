 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 22:15:57
 ///

#include <stdlib.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

void test0(void)
{
	int *p=(int *)malloc(sizeof(int));
	*p=10;
	cout<<"*p="<<*p<<endl;

	int *p2=(int *)malloc(sizeof(int)*10);
	::memset(p2,0,sizeof(int)*10);
	for(int idx=0;idx<10;idx++)
		p2[idx]=idx;

	free(p);
	free(p2);
}

void test1(void)
{
	int *p=new int(1);
	cout<<"*p="<<*p<<endl;
	int *p2=new int[10]();
	for(int idx=0;idx<10;++idx)
		p2[idx]=idx;

	delete p;
	delete [] p2;
}

int main(void)
{
	test0();
	test1();
	return 0;
}

