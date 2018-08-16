 ///
 /// @file    myLogger.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 20:56:42
 ///
 

#include "mylogger.h"

#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

#include <iostream>

Mylogger * Mylogger::_pInstance = NULL;

Mylogger * Mylogger::getInstance()
{
	if(_pInstance == NULL)
		_pInstance = new Mylogger();
	return _pInstance;
}

void Mylogger::destroy()
{
	if(_pInstance)	
		delete _pInstance;
}


Mylogger::Mylogger()
: _category(log4cpp::Category::getRoot())
{
	using namespace log4cpp;
	
	PatternLayout * ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d [%p] %m%n");

	PatternLayout * ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d [%p] %m%n");

	OstreamAppender * pOstreamAppender = new OstreamAppender("pOstreamAppender", &std::cout);
	pOstreamAppender->setLayout(ptnLayout1);

	FileAppender * pFileAppender = new FileAppender("pFileAppender", "wangdao.log");
	pFileAppender->setLayout(ptnLayout2);

	_category.addAppender(pOstreamAppender);
	_category.addAppender(pFileAppender);
	_category.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
	log4cpp::Category::shutdown();	
}

void Mylogger::warn(const char * msg) 
{
	_category.warn(msg);
}

void Mylogger::error(const char * msg) 
{
	_category.error(msg);
}

void Mylogger::info(const char * msg) 
{
	_category.info(msg);
}

void Mylogger::debug(const char * msg) 
{
	_category.debug(msg);
}
