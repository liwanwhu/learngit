 ///
 /// @file    computer3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 23:16:16
 ///

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer
{

public:
	Computer(const char *brand,float price)
	:_brand(new char[strlen(brand)+1]())
	,_price(price)
	{
		cout<<"Computer(const char *,float)"<<endl;
		strcpy(_brand,brand);
	}

	void print()
	{
		cout<<"brand:"<<_brand<<endl;
		cout<<"price"<<_price<<endl;
	}

	~Computer()
	{
		cout<<"~Computer()"<<endl;
		delete [] _brand;
	}

private:
	char * _brand;
	float _price;

};

int main(void)
{
	Computer * pc =new Computer("mac",10000);
	pc->print();

	delete pc;

	return 0;
}
