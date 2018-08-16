 ///
 /// @file    Queue.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 20:57:52
 ///
#include <deque> 
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::deque;
using std::string;

template <typename Type>
class Queue
{
public:

	bool empty() const
	{
		return _data.size()==0;
	}

	void push(const Type & element)
	{
		_data.push_back(element);
	}

	void pop()
	{
		if(!empty()){
			_data.pop_front();
		}else{
			cout<<"queue is empty, no more data!"<<endl;
		}
	}

	Type front() const
	{
		return _data.front();
	}

	Type back() const
	{
		return _data.back();
	}


private:
	deque<Type> _data;
};

void test0(void)
{
	Queue<int> queue;
	cout<<"queue is empty?"<<queue.empty()<<endl;
	queue.push(1);
	cout<<"queue is empty?"<<queue.empty()<<endl;

	for(int idx=2;idx!=11;++idx)
	{
		queue.push(idx);
	}


	while(!queue.empty()){
		cout<<queue.front()<<endl;
		queue.pop();
	}
	cout<<"queue is empty?"<<queue.empty()<<endl;

}
	
void test1(void)
{
	Queue<string> queue;
	cout<<"queue is empty?"<<queue.empty()<<endl;
	char ch='a';
	queue.push(string(3,ch));
	cout<<"queue is empty?"<<queue.empty()<<endl;

	for(int idx=1;idx!=11;++idx)
	{
		queue.push(string(3,ch+idx));
	}

	while(!queue.empty()){
		cout<<queue.front()<<endl;
		queue.pop();
	}
	cout<<"queue is empty?"<<queue.empty()<<endl;

}
int main(void)
{
	test0();
	cout<<endl;
	test1();
}
