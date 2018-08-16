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

void Computer::setBrand(const char *brand)
{
	strcpy(_brand,brand);
}
void Computer::setPrice(float price)
{
	_price=price;
}

void Computer::print()
{
	cout<<"brand:"<<_brand<<endl;
	cout<<"price:"<<_price<<endl;
}
