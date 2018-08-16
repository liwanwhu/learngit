 ///
 /// @file    string.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-13 20:53:36
 ///
#include <string.h>

#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::ostream;

class String
{
public:
	String()
	:_pStr(0)
	{
		cout<<"String()"<<endl;
	}

	String(const char * hs)
	:_pStr(new char[strlen(hs)+1]())
	{
		cout<<"String(const char * hs)"<<endl;
		strcpy(_pStr,hs);
	}

	String(const String & hs)
	:_pStr(new char[hs.size()+1]())
	{
		cout<<"String(const String & hs)"<<endl;
		strcpy(_pStr,hs._pStr);
	}
#if 1
	String(String && hs)
	{
		cout<<"	String(String && hs)"<<endl;
		_pStr=hs._pStr;
		hs._pStr=0;
	}

	String & operator=(String && hs)
	{
		cout<<"String & operator=(String && hs)"<<endl;
		if(this!=&hs)
		{
			delete [] _pStr;
			_pStr=hs._pStr;
			hs._pStr=0;
		}
		return *this;
	}

#endif
	String & operator=(const String & hs)
	{
		cout<<"String & operator=(const String & hs)"<<endl;
		if(this!=&hs)
		{
			delete [] _pStr;
			_pStr=new char[hs.size()+1]();
			strcpy(_pStr,hs._pStr);
		}
		return *this;
	}

	size_t size() const
	{
		return strlen(_pStr);
	}

	~String()
	{
		if(_pStr)
			delete [] _pStr;
		cout<<"~String()"<<endl;
		
	}

	
	friend ostream & operator<<(ostream & os ,const String & hs);

private:
	char * _pStr;
};

ostream & operator<<(ostream & os ,const String & hs)
{
	os<<hs._pStr;
	return os;
}

int main(void)
{
	String str1="hello,world";
	String str2("shenzhen");
	cout<<str1<<endl;
	cout<<str2<<endl;
	str2=String("hello");
	cout<<str2<<endl;
	return 0;
}

