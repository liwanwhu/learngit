 ///
 /// @file    myString.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-25 19:55:48
 ///

#include "myString.h"

#include <string.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

String::String()
{
	cout<<endl<<"string()"<<endl;	
}

String::String(const char *pstr)
	:_pstr(new char[strlen(pstr)+1]())
{
	strcpy(_pstr,pstr);
	cout<<endl<<"string(string)"<<endl;
}

String::String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]())
{
	strcpy(_pstr,rhs._pstr);
	cout<<endl<<"string(res)"<<endl;
}
String & String::operator=(const String & rhs)
{
	if(this!=&rhs){
		delete  _pstr;

		_pstr=new char[strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
	}
	return * this;
}

void String::print()
{
	cout<<_pstr<<endl;
}

String::~String()
{
	delete _pstr;
	cout<<endl<<"~String()"<<endl;
}
