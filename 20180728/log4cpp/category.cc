 ///
 /// @file    category.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-28 16:14:12
 ///
 
#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using std::string;

using log4cpp::OstreamAppender;
using log4cpp::BasicLayout;
using log4cpp::Category;
using log4cpp::Priority;

int main(void)
{
	OstreamAppender* osAppender1 = new OstreamAppender("osAppender1",&cout);
	osAppender1->setLayout(new BasicLayout());
	OstreamAppender* osAppender2 = new OstreamAppender("osAppender2",&cout);
	osAppender2->setLayout(new BasicLayout());
	Category& root = Category::getRoot();
	root.setPriority(Priority::DEBUG);

	Category& sub1=root.getInstance("sub1");
	sub1.addAppender(osAppender1);
	sub1.setPriority(Priority::DEBUG);
	sub1.error("sub error");

	Category& sub2=root.getInstance("sub2");
	sub2.addAppender(osAppender2);
	sub2.setPriority(101);
	sub2.warn("sub2 fatal");
	sub2.alert("sub2 alert");
	sub2.crit("sub2 crit");

	Category::shutdown();
	return 0;
}
