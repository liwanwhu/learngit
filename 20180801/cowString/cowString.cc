 ///
 /// @file    cowString.cc
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
	:_pstr(new char[5]())
	,rw(0)
	{	
		*((int *)_pstr)=1;
		_pstr+=4;
	}

	String(const char *arr)
	:_pstr(new char[strlen(arr)+1]())
	,rw(0)
	{
		strcpy(_pstr,arr);
	}

	String(const String& string)
	:_pstr(new char[string.size()+1]())
	,rw(0)
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
		rw='1';
		delete []_pstr;
		_pstr=new char[string.size()+1]();
		strcpy(_pstr,string.c_str());
		return *this;
	}

		
	String &operator=(const char *arr)
	{
		rw='1';
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
friend std::ostream & operator<<(std::ostream & os,const String & string);


private:
	char * _pstr;
	char rw;//read-write bit read 0,write 1
};

std::ostream & operator<<(std::ostream & os,const String & string)
{
	os<<string._pstr<<endl;
	return os;
}

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


int main(void)
{
	String s1 = "hello,world";
	String s2 = s1;
	String s3 = s2;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n\n", s3.c_str());

	s1[0] = 'X';
	cout << "Ö´ÐÐÐÞ¸Ä²Ù×÷:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n\n", s3.c_str());
	return 0;
}
