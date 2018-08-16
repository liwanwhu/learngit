 ///
 /// @file    add.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 16:30:03
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

template <typename Type,int kSize =10>
Type multiply(Type x, Type y)
{
	return x*y*kSize;
}

template <typename Type>
Type add(Type x,Type y);

template <typename Type>
Type add(Type x,Type y,Type z)
{
	return x+y+z;
}

template<>
const char * add<const char *>(const char *p1,const char *p2)
{
	cout<<"const char * add(const char *,const char *)"<<endl;
	char * ptmp=new char[strlen(p1)+strlen(p2)+1]();
	strcpy(ptmp,p1);
	strcat(ptmp,p2);
	return ptmp;
}

int add(int a ,int b){
	cout<<"int add(int,int)"<<endl;
	return a+b;
}
int main(void)
{
	int a=3,b=4,c=5;
	double d1=11.11,d2=22.22;
	char c1='A',c2=1;
	std::string s1="hello";
	std::string s2="world";

	const char * p1="hello";
	const char *p2 ="world";

	cout<<"add(a,b)="<<add(a,b)<<endl;
	cout<<"add(d1,d2)="<<add<double>(d1,d2)<<endl;
	cout<<"add(a,b,c)="<<add(a,b,c)<<endl;
	cout<<"add(c1,c2)="<<add(c1,c2)<<endl;
	cout<<"add(p1,p2)="<<add(p1,p2)<<endl;
	cout<<"add(s1,s2)="<<add(s1,s2)<<endl;
	cout<<endl;

	cout<<"multiply(a,b)"<<multiply<int,5>(a,b)<<endl;
	cout<<"multiply(a,b)"<<multiply(a,b)<<endl;
	
	return 0;
}

template <typename Type>
Type add(Type x,Type y)
{
	cout<<"Type add(Type,Type)"<<endl;
	return x+y;
}
