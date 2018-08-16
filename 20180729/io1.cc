 ///
 /// @file    io1.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-29 23:43:31
 ///
#include <limits> 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void printCin()
{
	cout<<"badbit="<<cin.bad()<<endl;
	cout<<"failbit="<<cin.fail()<<endl;
	cout<<"eofbit="<<cin.eof()<<endl;
	cout<<"goodbit="<<cin.good()<<endl;
}

int test0(void)
{
	cout<<"sizeof(cout)="<<sizeof(cout)<<endl;
	cout<<"sizeof(cin)="<<sizeof(cin)<<endl;

	printCin();
	int num;
	while(cin>>num)
	{
		cout<<num<<endl;
	}
	printCin();
	cout<<endl<<"重置流状态";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	printCin();

	string s;
	cin>>s;
	cout<<"s="<<s<<endl;
}

void test1(void)
{
	int number;
	cout<<">>pls input an interger: ";
	while(cin>>number,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"cin has breaken!"<<endl;
			break;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout<<">>pls input an interger:";
			continue;
		}
		cout<<"number="<<number<<endl;
	}
	printCin();
	cout<<"1111"<<endl;
}


int main(void)
{
	test0();
//	test1();

	return 0;
}
