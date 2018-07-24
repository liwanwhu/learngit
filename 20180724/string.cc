 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 23:01:51
 ///
 
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
	{
		string s;
		assert(s.empty()&&(s.length()==0)&&(s.size()==0));
	}

	{
		string s(4,'=');
		cout<<s<<endl;
	}

	string other("Exemplary");
	cout<<other<<endl;
	string s(other,0,other.length()-1);
	cout<<s<<" "<<other.length()<<" "<<other.size()<<endl;

	
	string s1("c-style string",7);
	cout<<s<<endl;
	return 0;
}
