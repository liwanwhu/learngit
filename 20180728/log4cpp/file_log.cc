 ///
 /// @file    helloLog4cpp.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-28 09:36:03
 ///
#include <stdio.h>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Appender.hh>

#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::ostringstream;
using namespace log4cpp;


int test0(string message)
{
	//create Appender ,layout
	//set layout
	Appender* fileAppender = new FileAppender("fileAppender","file.log");
	PatternLayout * pLayout1 = new PatternLayout();
	pLayout1->setConversionPattern("%d{%d %m %Y %H:%M:%S,%l}: %p : %m%n");
	fileAppender->setLayout(pLayout1);

	RollingFileAppender* rollfileAppender = new RollingFileAppender("rollfileAppender","roll.log",5*1024,1);
	PatternLayout * pLayout2 = new PatternLayout();
	//pLayout2->setConversionPattern("%d{%d %m %Y %H:%M:%S,%l}: %p : %m%n");
	rollfileAppender->setLayout(pLayout1);

	//get category root,add appender to category
	Category& root = Category::getRoot();
	root.addAppender(fileAppender);
	root.addAppender(rollfileAppender);

	//set priority
	root.setPriority(Priority::DEBUG);

	//log
	for(int i=0;i<100;i++)
	{
		string strError;
		//printf("File:" __FILE__ ",Line:%05d:",__LINE__);
		//sprintf(strError,"%s@%s,%d|%s",__func__,__FILE__,__LINE__,"this is a message!");
		ostringstream oss;
		oss<<__func__<<"@"<<__FILE__<<","<<__LINE__<<"|"<<message;

		strError=oss.str();
		root.error(strError);
	}

	//close category
	Category::shutdown();

	return 0;
}


int main(void)
{
//	string context="this is an Error Info!!";
//	test0(context);
	test0("this is an Error Info!");
	return 0;
}
