 ///
 /// @file    variadicTmplate.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 15:15:31
 ///

#include <iostream>
using std::cout;
using std::endl;

template <typename... Args>
void display(Args... args)
{
	cout<<sizeof...(Args)<<endl;
	cout<<sizeof...(args)<<endl;
}

void test0(void)
{
	int a =1;
	double b=2.2,c=3.3;
	std::string s="hello.world";
	display(a,b,c,s,'A');

}
//exit func is essential
#if 0
void print()
{
	cout<<endl;
}
#endif

template <typename T>
void print(T t)
{
	cout<<t<<endl;
}
template<typename T,typename... Args>
void print(T t,Args... args)
{
	cout<<t<<"\n";
	print(args...);
}

void test1(void)
{
	int a=1;
	double b=2.2;
	std::string s="hello,world";
	print(a,b,s,'A');
}

template <typename T>
T sum(T t)
{
	return t;
}

template <typename T,typename...Args>
T sum(T t,Args... args)
{
	return t+=sum(args...);
}
void test2(void)
{
	cout<<sum(1,2,3,4)<<endl;
}
int main(void)
{
	//test0();
	test2();
	return 0;
}
