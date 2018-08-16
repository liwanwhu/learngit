 ///
 /// @file    helloLog4cpp.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-28 09:36:03
 ///
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;

class Mylog
{
public:
	void warn(
};
int test0()
{
	//create Appender ,layout
	OstreamAppender * osAppender = new OstreamAppender("osAppender",&cout);
	osAppender->setLayout(new BasicLayout());
	//get category root,add appender to category
	Category& root = Category::getRoot();
	root.addAppender(osAppender);
	//set priority
	root.setPriority(Priority::DEBUG);

	//log
	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a warning Message!");

	//close category
	Category::shutdown();

	return 0;
}

int main(void)
{
	cout<<"hello,world"<<endl;
	logInfo("Message");
	logError("Message");
	logWarn("Message");
	logDebug("Message");
}
