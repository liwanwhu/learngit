 ///
 /// @file    main.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-02 20:52:08
 ///
 
#include "tinyxml2.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace tinyxml2;

void example1()
{
	XMLDocument doc;
	doc.LoadFile("test.xml");
	const char* content = doc.FirstChildElement("Hello")->GetText();
	printf("Hello,%s",content);

}
int main()
{
	example1();

	return 0;
}
