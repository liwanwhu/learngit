 ///
 /// @file    helloLog4cpp.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-28 09:36:03
 ///
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/StringQueueAppender.hh>

#include <iostream>
#include <queue>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::queue;
using namespace log4cpp;

int main()
{
	//create Appender ,layout
	StringQueueAppender* strQAppender = new StringQueueAppender("strQAppender");
	strQAppender->setLayout(new BasicLayout());
//PatternLayout * pLayout = new PatternLayout();
	//set layout
	//get category root,add appender to category
	Category& root = Category::getRoot();
	root.addAppender(strQAppender);
	//set priority
	root.setPriority(Priority::DEBUG);

	//log
	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a warning Message!");

	cout<<"Get message from Memory Queue!"<<endl;
	cout<<"---------------------------"<<endl;
	queue<string>& myStrQ = strQAppender->getQueue();
	while(!myStrQ.empty())
	{
		cout<<myStrQ.front();
		myStrQ.pop();
	}

	//close category
	Category::shutdown();

	return 0;
}
