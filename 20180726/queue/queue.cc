 ///
 /// @file    queue.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-26 20:52:43
 ///
 

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	void print()
	{
		int i=0;
		cout<<"size:"<<_size<<endl;
		for(i=0;i<10;i++)
		{
			if(_data[i]!=-1)
				cout<<_data[i]<<" "<<endl;
		}
		cout<<endl;
	}

	void push(int num)
	{
		if(empty())
		{
			_size++;
			_data[0]=num;
			_head=_data;
			return;
		}

		if(full())
		{
			cout<<"queue full"<<endl;
			return;
		}
		_size++;
		_data[_size-1]=num;
		_head++;
	}

	void pop()
	{
		if(empty())
		{
			cout<<"queue empty"<<endl;
			return ;
		}
		_size--;
		if(_tail){
			_tail++;
		}
		else
			_tail=_data;
		*_tail=-1;

	}
	int front()
	{
		if(_head)
			return *_head; 
		else
			return -1;
	}
	int back()
	{
		if(_tail)
			return *(_tail+1);
		else
			return -1;
	}
	bool empty()
	{
		if(_head==NULL||_head==_tail)
		{
			return 1;
		}else
			return 0;
	}

	bool full()
	{
		if(_size==10)
		{
			return 1;
		}else
			return 0;
	}

	Queue()
		:_head(NULL)
		,_tail(NULL)
		,_size(0)
	{
		int i;
		for(i=0;i<10;i++)
			_data[i]=-1;
	}
private:
	int _data[10];
	int *_head,*_tail;
	int _size;
};

int main(void)
{
	Queue queue;
	queue.push(10);
	queue.push(12);
	queue.push(14);
	queue.print();
	int val_front=queue.front();
	cout<<"val_front:"<<val_front<<endl;
	int val_back=queue.back();
	cout<<"val_back:"<<val_back<<endl;
	queue.pop();
	queue.print();
	val_front=queue.front();
	cout<<"val_front:"<<val_front<<endl;
	val_back=queue.back();
	cout<<"val_back:"<<val_back<<endl;
	return 0;
}
