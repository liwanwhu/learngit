 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-26 19:56:41
 ///
 
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	void print()
	{
		int i=0;
		cout<<"size:"<<_size<<endl;
		for(i=0;i<_size;i++)
			cout<<_data[i]<<" "<<endl;
		cout<<endl;
	}

	void push(int num)
	{
		if(full())
		{
			cout<<"stack full"<<endl;
			return;
		}
		_size++;
		_data[_size-1]=num;
	}

	void pop()
	{
		if(empty())
		{
			cout<<"stack empty"<<endl;
			return ;
		}
		_data[_size]=-1;
		_size--;
	}
	int top(){
		return _data[_size-1];
	}
	bool empty()
	{
		if(_size==0)
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

	Stack()
		:_size(0)
	{
		int i;
		for(i=0;i<10;i++)
			_data[i]=-1;
	}
private:
	int _data[10];
	int _size;
};

int main(void)
{
	Stack stack;
	stack.pop();
	stack.push(10);
	stack.push(12);
	stack.push(14);
	stack.print();

	int val_top=stack.top();
	cout<<"val_top"<<val_top<<endl;
	stack.pop();
	val_top=stack.top();
	cout<<"val_top"<<val_top<<endl;
	return 0;
}
