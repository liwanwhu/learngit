 ///
 /// @file    at_s.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 23:48:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string s("message");
	s="abc";
	s.at(2)='x';
	cout<<s<<endl;
	return 0;
}
