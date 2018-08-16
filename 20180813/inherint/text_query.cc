 ///
 /// @file    text_query.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-13 23:26:13
 ///
 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;
using std::set;
using std::ifstream;

class TextQuery
{
public:
	TextQuery()
	{
		_line.reserve(4096);
	}

	void readFile(const string filename);
	void query(const string & word);

private:
	vector<string> _line;
	unordered_map<string,int> _wordFrequency;
	unordered_map<string,set<int>> _wordLine;
};

void TextQuery::readFile(const string filename)
{
	ifstream fs(filename);
	while(!fs.eof())
	{
		string tmpLine;
		getline(fs,tmpLine,'\n');
		_line.pushback(tmpLine);
	}

	size_t i=0;
	for(i=0;i<_line.size();i++)
	{
		stringstream tmpSstream;
		tmpSstream<<_line[i];
		string tmp_word;
		while

}
