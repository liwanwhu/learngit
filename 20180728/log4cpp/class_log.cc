 ///
 /// @file    helloLog4cpp.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-28 09:36:03
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

class Mylog
{
public:
	void warn(const char *message)
	{
		string log;
		ostringstream oss;
		oss<<__func__<<"@"<<__FILE__<<","<<__LINE__<<"|"<<message;

		log=oss.str();
		_pRoot->warn(log);
	}

	

	void error(const char *message)
	{
		string log;
		ostringstream oss;
		oss<<__func__<<"@"<<__FILE__<<","<<__LINE__<<"|"<<message;

		log=oss.str();
		_pRoot->error(log);
	}

	void debug(const char *message)
	{
		string log;
		ostringstream oss;
		oss<<__func__<<"@"<<__FILE__<<","<<__LINE__<<"|"<<message;

		log=oss.str();
		_pRoot->debug(log);
	}


	void info(const char *message)
	{
		string log;
		ostringstream oss;
		oss<<__func__<<"@"<<__FILE__<<","<<__LINE__<<"|"<<message;

		log=oss.str();
		cout<<log<<endl;
		_pRoot->info(log);
	}


	static Mylog * getInstance()
	{
		if(!_pMylog)
			_pMylog=new Mylog();
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
		_pRoot=&root;
		return _pMylog;
	}

	static void destory()
	{
		if(_pMylog)
			delete  _pMylog;
		cout<<"destory"<<endl;
		Category::shutdown();
	}
private:
	Mylog()
	{
		cout<<"Mylog()"<<endl;

	}
	~Mylog()
	{
		cout<<"~Mylog()"<<endl;
	}
private:
	static Mylog * _pMylog;
	static Category* _pRoot;
};

Mylog * Mylog::_pMylog=NULL;
Category * Mylog::_pRoot=NULL;

int main(void)
{
	Mylog *log= Mylog::getInstance();
	cout<<"hello,world"<<endl;
	log->info("this is an info !");
	log->error("this is an error!");
	log->warn("this is a warn!");
	log->debug("this is a debug");
	Mylog::destory();

	return 0;
}
