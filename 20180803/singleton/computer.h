
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer
{

public:
	Computer()
	{
		cout<<"Computer()"<<endl;
	}
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
		if(_brand)
			delete [] _brand;
	}

private:
	char * _brand;
	float _price;

};
