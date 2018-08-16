 ///
 /// @file    myLogger.h
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 17:29:38
 ///
 
#ifndef __MYLOGGER_H__
#define __MYLOGGER_H__
#include <log4cpp/Category.hh>
#include <string>

using std::string;

class Mylogger
{
public:
	static Mylogger * getInstance();
	static void destory();
	void warn(const char *msg);
	void error(const char *msg);
	void info(const char *msg);
	void debug(const char *msg);

private:
	Mylogger();
	~Mylogger();
private:
	static Mylogger * _pInstance;
	log4cpp::Category & _category;
};

#define prefix(msg) string("[")\
	.append(__FILE__).append(":")\
	.append(__FUNCTION__).append(":")\
	.append(std::to_string(__LINE__)).append("]")\
	.append(msg).c_str()

#define LogWarn(msg)
Mylogger::getInstance()->warn(prefix(msg));



#endif

