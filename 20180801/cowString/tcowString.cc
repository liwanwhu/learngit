 ///
 /// @file    cowString.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-01 11:37:26
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	class CharProxy
	{
	public:
		CharProxy(String & self, size_t idx)
		: _self(self)
		, _idx(idx)
		{}

		//CharProxy & operator=(const char & ch);
		char & operator=(const char & ch);

		friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);

	private:
		String & _self;
		size_t _idx;
	};
	
	friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);

	~String();

	size_t size() const {	return strlen(_pstr);	}
	const char * c_str() const {	return _pstr;	}

	size_t refCount() const {	return *(int*)(_pstr - 4);	}

	CharProxy operator[](size_t idx);

	//const char & operator[](size_t idx) const;

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);

private:
	//inline函数
	void initRefcount()
	{	*(int *)(_pstr - 4) = 1; }

	void increaseRefcount()
	{	++(*(int *)(_pstr - 4)); }

	void decreaseRefcount()
	{	--(*(int *)(_pstr - 4)); }

	void release() {
		decreaseRefcount();
		if(refCount() == 0) {
			delete [] (_pstr - 4);
			cout << ">> delete heap data" << endl;
		}
	}
	
private:
	char * _pstr;
};

String::String()
: _pstr(new char[5]() + 4)
{
	initRefcount();
}

String::String(const char * pstr)
: _pstr(new char[strlen(pstr) + 5]() + 4)
{
	strcpy(_pstr, pstr);
	initRefcount();
}

//时间复杂度为O(1)
String::String(const String & rhs)
: _pstr(rhs._pstr)
{
	increaseRefcount();
}

String & String::operator=(const String & rhs)
{
	if(this != &rhs)
	{
		release();

		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

String::~String()
{
	release();
}

String::CharProxy String::operator[](size_t idx)
{
	return CharProxy(*this, idx);
}

//实现写操作
//String::CharProxy & String::CharProxy::operator=(const char & ch)
char & String::CharProxy::operator=(const char & ch)
{
	cout << "CharProxy & CharProxy::operator=(const char &)" << endl;
	if(_idx < _self.size())
	{
		if(_self.refCount() > 1)
		{
			_self.decreaseRefcount();
			char * ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp, _self._pstr);
			_self._pstr = ptmp;
			_self.initRefcount();
		}
		_self._pstr[_idx] = ch;
	}
	return _self._pstr[_idx];
}

//友元函数(普通函数)
std::ostream & operator<<(std::ostream & os, const String::CharProxy & rhs)
{
	printf("rhs:%p\n", & rhs);
	os << rhs._self._pstr[rhs._idx];
	return os;
}
 
// 现在的下标访问运算符无法区分读操作和写操作
#if 0
char & String::operator[](size_t idx)
{
	cout << "char & String::operator[](size_t idx)" << endl;
	if(idx < size()) {
		if(refCount() > 1) {
			decreaseRefcount();
			//进行深拷贝
			char * ptmp = new char[size() + 5]() + 4;
			strcpy(ptmp, _pstr);
			_pstr = ptmp;
			initRefcount();
		}
		return _pstr[idx];
	} else
	{
		static char nullchar = '\0';
		cout << "下标越界" << endl;
		return nullchar;
	}
}
#endif


std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}
int test0(void)
{
	String s1;
	String s2 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1 's refcount = " << s1.refCount() << endl;
	cout << "s2 's refcount = " << s2.refCount() << endl;
 
	return 0;
}

void test1(void)
{
	String s1 = "hello,world";
	String s2 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1 's refcount = " << s1.refCount() << endl;
	cout << "s2 's refcount = " << s2.refCount() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());

	cout << endl;
	String s3 = "shenzhen";
	printf("s3' address = %p\n", s3.c_str());
	cout << "s3 = " << s3 << endl;
	s3 = s1;
	cout << endl << " >> 执行赋值运算符操作:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1 's refcount = " << s1.refCount() << endl;
	cout << "s2 's refcount = " << s2.refCount() << endl;
	cout << "s3 's refcount = " << s3.refCount() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());
	printf("s3' address = %p\n", s3.c_str());

	cout << endl;
	s3[0] = 'X';
	cout << "执行修改操作:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1 's refcount = " << s1.refCount() << endl;
	cout << "s2 's refcount = " << s2.refCount() << endl;
	cout << "s3 's refcount = " << s3.refCount() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());
	printf("s3' address = %p\n", s3.c_str());

	cout << endl;
	cout << "s1[0] = " << s1[0] << endl;
	cout << "对 s1进行读操作" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1 's refcount = " << s1.refCount() << endl;
	cout << "s2 's refcount = " << s2.refCount() << endl;
	cout << "s3 's refcount = " << s3.refCount() << endl;
	printf("s1' address = %p\n", s1.c_str());
	printf("s2' address = %p\n", s2.c_str());
	printf("s3' address = %p\n", s3.c_str());

}

int main(void)
{
	test1();

	return 0;
}
