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
	doc.LoadFile("test2.xml");

	XMLElement *scene=doc.RootElement();
	XMLElement *surface=scene->FirstChildElement("node");
	while(surface)
	{
		XMLElement * surfaceChild=surface -> FirstChildElement();
		const char * content;
		const XMLAttribute *attributeOfSurface=surface->FirstAttribute();
		cout<<attributeOfSurface->Name()<<":"<<attributeOfSurface->Value()<<endl;
		while(surfaceChild)
		{
			content=surfaceChild->GetText();
			surfaceChild=surfaceChild->NextSiblingElement();
			cout<<content<<endl;
		}
		surface=surface->NextSiblingElement();
	}
}

int main()
{
	example1();

	return 0;
}
