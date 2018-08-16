 ///
 /// @file    computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 12:54:28
 ///

#include "computer.h"
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;



int main(void)
{
	Computer com;
	com.setBrand("lenovo");
	com.setPrice(8888);
	com.print();

	return 0;
}
