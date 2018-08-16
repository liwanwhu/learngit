 ///
 /// @file    boost.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-02 19:59:21
 ///
 
#include <iostream>
#include <boost/version.hpp>
#include <boost/timer.hpp>
using std::cout;
using std::endl;

int main()
{
	boost::timer t;
	cout<<"max timespan:"<<t.elapsed_max()/3600<<"h"<<endl;
	cout<<"min timespan:"<<t.elapsed_min()<<endl;
	cout<<"now time elapsed:"<<t.elapsed()<<endl;
	cout<<"boost version"<<BOOST_LIB_VERSION<<endl;

	return 0;
}
