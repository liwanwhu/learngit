 ///
 /// @file    const.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 20:45:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#define MAX 1000

int test0(void)
{
	int num =2;
	cout<<num*MAX<<endl;
	return 0;
}

void test1()
{
	const int value=1;
	cout<<"value="<<value<<endl;
}

int main(){
	test0();
	test1();
	return 0;
}
