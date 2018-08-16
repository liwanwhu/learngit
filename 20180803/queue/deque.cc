 ///
 /// @file    deque.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 22:28:09
 ///
#include <deque>
#include <iostream>
using std::cout;
using std::endl;
using std::deque;
#if 0
template <typename Container>
void display(const Container &c)
{
	typename Container::const_iterator cit;
	for(cit=c.begin();cit!=c.end();++cit)
	{
		cout<<*cit<<"";
	}
	cout<<endl;
}
#endif
template <typename Container>
void display(const Container &c)
{
	typename Container::const_iterator cit;
	for(cit=c.begin();cit!=c.end();++cit)
	{
		cout<<*cit<<" ";
	}
	cout<<endl;
}

int main(void)
{
	deque<int> deNumbers{1,2,3,4,5};
	deNumbers.push_back(6);
	deNumbers.push_front(0);
	display(deNumbers);
	deque<int>::iterator dit=deNumbers.insert(++deNumbers.begin(),12);
	cout<<*dit<<endl;
	cout<<"deNumbers[0]="<<deNumbers[0]<<endl;
	display(deNumbers);
	deNumbers.clear();
	display(deNumbers);
	return 0;
}
