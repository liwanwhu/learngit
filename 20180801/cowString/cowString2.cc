 ///
 /// @file    example.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-01 19:34:27
 ///
 
#include <stdio.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class String
{
	class CharPxy
	{
	public:
		CharPxy(String & string,size_t index)
		:_hs(string)
		,_index(index)
		{
		}

		//~CharPxy();
		
		char & operator=(const char & c)
		{
			if(_hs.refCount()>1)
			{
				_hs.decreaseRefcout();
				char * tmp=new char[_hs.size()+5]()+4;
				strcpy(tmp,_hs._pstr);
				_hs._pstr=tmp;
				_hs.increaseRefcout();
			}
			_hs._pstr[_index]=c;
			return _hs._pstr[_index];
		}
friend std::ostream & operator<<(std::ostream & os,const CharPxy & hs); 

	private:
		String & _hs;
		size_t _index;

	};
public:

	String()
	:_pstr(new char[5]()+4)
	{
		initRefcout();
	}

	String(const char * pstr)
	:_pstr(new char[strlen(pstr)+5]()+4)
	{
		strcpy(_pstr,pstr);
		initRefcout();
	}

	String(const String & hs)
	:_pstr(hs._pstr)
	{
		increaseRefcout();
	}

	~String()
	{
		release();
	}

	CharPxy  operator[](size_t index){
		return CharPxy(*this,index);
	}
#if 0
	CharPxy & operator[](size_t index){
		cout<<"CharPxy operator[]"<<endl;
	
		CharPxy *p1=new CharPxy(*this,index);
		return  *p1;
	}
	char & operator[](size_t index)
	{
		if(refCount()>1)
		{
			decreaseRefcout();
			char * tmp=new char[size()+5]()+4;
			strcpy(tmp,_pstr);
			_pstr=tmp;
			increaseRefcout();
		}
		return _pstr[index];
	}
#endif
	size_t  refCount() const
	{
		return *(int *)(_pstr-4);
	}

	String & operator=(const String & hs)
	{
		if(this!=&hs){
			release();
			_pstr=hs._pstr;
			increaseRefcout();
		}
		return *this;
	}

	const char * c_str() const
	{
		return _pstr;
	}
friend std::ostream & operator<<(std::ostream & os,const String &str);
friend std::ostream & operator<<(std::ostream & os,const CharPxy & hs); 

private:
	size_t size()const
	{
		return strlen(_pstr);
	}
	void initRefcout()
	{
		*(int *)(_pstr-4)=1;
	}

	void increaseRefcout()
	{
		++(*(int *)(_pstr-4));
	}

	void decreaseRefcout()
	{
		--(*(int *)(_pstr-4));
	}

	void release()
	{
		decreaseRefcout();
		if(refCount()==0)
		{
			delete [] (_pstr-4);
			cout<<"delete heap data"<<endl;
		}
	}

private:
	char * _pstr;
};

#if 0
std::ostream & operator<<(std::ostream & os,String::CharPxy & hs) 
{
	cout<<"operator<<"<<endl;
	os<<hs._hs._pstr[hs._index];
	return os;
}
#endif
std::ostream & operator<<(std::ostream & os,const String::CharPxy & hs) 
{
	os<<hs._hs._pstr[hs._index];
	return os;
}
std::ostream & operator<<(std::ostream & os,const String & hs)
{
	os<<hs._pstr;
	return os;
}
int test0(void)
{
	String s1;
	String s2 = s1;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s1's refcount ="<<s1.refCount()<<endl;
	cout<<"s2's refcount ="<<s2.refCount()<<endl;

	return 0;
}


int test1(void)
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
	cout << "writing" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n\n", s3.c_str());

	cout << "reading" << endl;
	cout<<s2[0] <<endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
//	printf("s2[0]'address = %p\n", &s2[0]);
	printf("s3'address = %p\n\n", s3.c_str());

	return 0;
}

int main(void)
{
	//test0();
	test1();
	
	return 0;
}
