 ///
 /// @file    computer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 13:08:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#include <stdio.h>
#include <string.h>

#ifndef	__COMPUTER_H_
#define __COMPUTER_H_

class Computer
{
public:
	void setBrand(const char *brand)
	{
		strcpy(_brand,brand);
	}

	void setPrice(float price)
	{
		_price=price;
	}

	void print()
	{
		cout<<"brand:"<<_brand<<endl;
		cout<<"price:"<<_price<<endl;
	}
private:
	char _brand[20];
	float _price;
};
#endif
