 ///
 /// @file    myString.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 19:36:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class String
{

public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);
	~String();

	void print();

private:
	char * _pstr;

};
