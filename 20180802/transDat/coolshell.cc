///
/// @file    coolshell.cc
/// @author  liwan(1459940006@qq.com)
/// @date    2018-08-04 10:18:00
///

#include "tinyxml2.h"

#include <string.h>

#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>
using std::cout;
using std::endl;
using namespace tinyxml2;
using std::ofstream;
using std::ostream;
using std::string;
using std::vector;

struct RssItem
{
	string title;
	string link;
	string content;
};

class RssReader
{
	public:
		RssReader()
		{
			_rss.reserve(1024);
		}
		void parseRss();
		void dump();
	private:
		vector<RssItem> _rss;
};

void RssReader::parseRss()
{
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");

	XMLElement *rss= doc.RootElement();
	XMLElement *channel = rss->FirstChildElement("channel");
	string content;
	while(channel)
	{
		XMLElement *item = channel->FirstChildElement("item");
		while(item)
		{
			XMLElement *title = item->FirstChildElement("title");
			XMLElement *link = item->FirstChildElement("link");
			XMLElement *arr = item->FirstChildElement("content:encoded");
			if(arr){
				string bContent(arr->GetText());					
				boost::regex re("</?[^>]+>");
				content=boost::regex_replace(bContent,re,string(""));
				content=boost::regex_replace(content,boost::regex("&lt;"),string("<"));
				content=boost::regex_replace(content,boost::regex("&gt;"),string(">"));
				content=boost::regex_replace(content,boost::regex("&amp;"),string("&"));
				content=boost::regex_replace(content,boost::regex("&quot;"),string("\""));
			}
			RssItem rss;
			rss.title=title->GetText();
			rss.link=link->GetText();
			rss.content=content;
			_rss.push_back(rss);
			item=item->NextSiblingElement();
		}
		channel=channel->NextSiblingElement();
	}
}
void RssReader::dump()
{
	ofstream ofs("pagelib.dat");
	if(!ofs.good()){
		cout<<"ofstream open error!"<<endl;
		return;
	}
	int i=0;
	for(auto & ele:_rss){
		ofs<<"<doc>"<<endl;
		ofs<<"<docid>"<<++i<<"</docid>"<<endl;
		ofs<<"<title>"<<ele.title<<"</title>"<<endl;
		ofs<<"<link>"<<ele.link<<"</link>"<<endl;
		ofs<<"<content>"<<ele.content<<"</content>"<<endl;
		ofs<<"</doc>"<<endl;
	}
}


int main(void)
{
	RssReader reader;
	reader.parseRss();
	reader.dump();
	return 0;
}

