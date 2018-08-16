 ///
 /// @file    log.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-28 16:58:34
 ///
#include <string.h>

#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

using log4cpp::OstreamAppender;
using log4cpp::Appender;
using log4cpp::FileAppender;
using log4cpp::PatternLayout;
using log4cpp::Category;
using log4cpp::Priority;

int test0(string message)
{
	OstreamAppender* osAppender = new OstreamAppender("osAppender",&cout);
	Appender* fileAppender = new FileAppender("fileAppender","file.log");

	PatternLayout* pLayout_cout = new PatternLayout();
	pLayout_cout->setConversionPattern("%d{%d %m %Y %H:%M:%S,%l}: %p :%m%n");
	osAppender->setLayout(pLayout_cout);
	PatternLayout* pLayout_file = new PatternLayout();
	pLayout_file->setConversionPattern("%d{%d %m %Y %H:%M:%S,%l}: %p :%m%n");
	fileAppender->setLayout(pLayout_file);

	Category& root = Category::getRoot();
	root.addAppender(osAppender);
	root.addAppender(fileAppender);

	root.setPriority(Priority::DEBUG);

	string log;
	ostringstream oss;
	oss<<__func__<<"@"<<__FILE__<<","<<__LINE__<<"|"<<message;

	log=oss.str();
	root.error(log);

	Category::shutdown();
	
	return 0;
}

int main(void)
{	
	test0("this is an Error Info!");
	return 0;
}
