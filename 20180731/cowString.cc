 ///
 /// @file    String.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-31 21:31:38
 ///
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
	:_pstr(new char[1]())
	{	
	}

	String(const char *arr)
	:_pstr(new char[strlen(arr)+1]())
	{
		strcpy(_pstr,arr);
	}

	String(const String& string)
	:_pstr(new char[string.size()+1]())
	{
		strcpy(_pstr,string.c_str());
	}

	~String()
	{
		if(_pstr)
			delete [] _pstr;
	}

	String &operator=(const String & string)
	{
		delete []_pstr;
		_pstr=new char[string.size()+1]();
		strcpy(_pstr,string.c_str());
		return *this;
	}

		
	String &operator=(const char *arr)
	{
		delete [] _pstr;
		_pstr=new char[strlen(arr)+1]();
		strcpy(_pstr,arr);
		return *this;
	}

	String & operator+=(const String & str1)
	{
		strcat(_pstr,str1.c_str());
		return *this; 
	}
	
	char &operator[](std::size_t index)
	{
		return *(_pstr+index);
	}
	const char &operator[](std::size_t index) const
	{
		return *(_pstr+index);
	}

	std::size_t size() const
	{
		return strlen(_pstr);
	}
	const char * c_str() const
	{
		return _pstr;
	}

	friend bool operator==(const String & str1,const String & str2);
	friend bool operator!=(const String & str1,const String & str2);

	friend bool operator<(const String & str1,const String &str2);
	friend bool operator>(const String & str1,const String & str2);
	friend bool operator<=(const String & str1,const String & str2);
	friend bool operator>=(const String & str1,const String & str2);

private:
	char * _pstr;
};

String operator+(const String & str1,const String &str2)
{
	char *arr=NULL;
	strcat(arr,str1.c_str());
	strcat(arr,str2.c_str());
	String tmp(arr);
	return tmp; 
}
String operator+(const String &str,const char *arr )
{
	char *array=NULL;
	strcat(array,str.c_str());
	strcat(array,arr);
	String tmp(array);
	return tmp; 
}
String operator+(const char *arr,const String & str)
{
	char *array=NULL;
	strcat(array,arr);
	strcat(array,str.c_str());
	String tmp(array);
	return tmp; 
}

bool operator==(const String & str1,const String & str2)
{
	if(!strcmp(str1.c_str(),str2.c_str()))
		return 1;
	else
		return 0;
}

bool operator!=(const String & str1,const String & str2)
{
	if(strcmp(str1.c_str(),str2.c_str()))
		return 1;
	else
		return 0;
}

bool operator<(const String & str1,const String &str2)
{
	if(strcmp(str1.c_str(),str2.c_str())<0)
		return 1;
	else
		return 0;
}

bool operator>(const String & str1,const String & str2)
{
	if(strcmp(str1.c_str(),str2.c_str())<0)
		return 1;
	else
		return 0;
}

bool operator<=(const String & str1,const String & str2)
{
	if(strcmp(str1.c_str(),str2.c_str())<=0)
		return 1;
	else
		return 0;
}

bool operator>=(const String & str1,const String & str2)
{
	if(strcmp(str1.c_str(),str2.c_str())>=0)
		return 1;
	else
		return 0;
}

int main(void)
{
	String s=;
	return 0;
}
