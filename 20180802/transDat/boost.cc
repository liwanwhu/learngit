 ///
 /// @file    boost.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-04 17:29:31
 ///
 
#include <iostream>
#include <string>
#include <boost/regex.hpp>
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str = "chinaen 8Glish";

	boost::regex expr("(\\w+)\\s(\\w+)");

	cout<<boost::regex_match(str,expr)<<endl;

	boost::smatch what;

	if(boost::regex_search(str,what,expr))
	{
		cout<<what[0]<<endl;
		cout<<what[1]<<endl;
		cout<<what[2]<<endl;
		cout<<what[3]<<endl;
	}else
	{
		cout<<"检索失败"<<endl;
	}
	return 0;
}

