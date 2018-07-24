 ///
 /// @file    const2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 20:53:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test0(void)
{
	int num1=10;
	int num2=11;
	const int * pa =&num1;
//	*pa=20;
	pa=&num2;

	int const *pb= &num1;
//	*pb=20;
	pb=&num2;

	int * const pc =&num1;
	*pc=20;
//	pc=&num2;

	const int * const pd=&num1;

}

int main(void)
{
	test0();
	return 0;
}
