 ///
 /// @file    stackObject.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-29 21:50:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack_object
{
public:
	Stack_object()
		:id(0)
	{
		cout<<"Stack_object()"<<endl;
	}

private:
	~Stack_object()
	{
		cout<<"~Stack_object()"<<endl;
	}

private:
	int id;
};
int main(void)
{
	Stack_object o1;
	Stack_object *o2 = (Stack_object *)new Stack_object();
	return 0;
}

