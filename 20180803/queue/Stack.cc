 ///
 /// @file    Stack.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-03 21:23:57
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename Type,size_t kSize=10>
class Stack
{
public:
	Stack()
	:_data()
	{
		_data.reserve(kSize);
	}

	template <typename T>
	void display(T t);

	bool full() const;
	bool empty() const;

	void push(const Type & element);
	void pop();
	Type top();

private:
	 vector<Type> _data;
};

template <typename Type,size_t kSize>
bool Stack<Type,kSize>::full() const
{
	return _data.size()==kSize;
}

template <typename Type,size_t kSize>
bool Stack<Type,kSize>::empty() const
{
	return _data.size()==0;
}

template <typename Type,size_t kSize>
void Stack<Type,kSize>::push(const Type & element)
{
	if(!full()){
		_data.push_back(element);
	}else{
		cout<<"stack is full ,cannot push data any more!"<<endl;
	}
}

template <typename Type,size_t kSize>
void Stack<Type,kSize>::pop()
{
	if(!empty())
	{
		_data.pop_back();
	}else{
		cout<<"stack is empty,no more data!"<<endl;
	}
}

template <typename Type,size_t kSize>
Type Stack<Type,kSize>::top()
{
	return _data.back();
}

template <typename Type,size_t kSize>
template <typename T>
void Stack<Type,kSize>::display(T t)
{
	cout<<"t="<<t<<endl;
}

void test0(void)
{
	vector<int> numbers;
	Stack<int> stack;
	cout<<"stack is empty?"<<stack.empty()<<endl;
	stack.push(1);
	cout<<"stack is empty?"<<stack.empty()<<endl;

	for(int idx=2;idx!=11;++idx)
	{
		stack.push(idx);
	}

	cout<<"stack is full?"<<stack.full()<<endl;

	while(!stack.empty()){
		cout<<stack.top()<<endl;
		stack.pop();
	}
	cout<<"stack is full?"<<stack.empty()<<endl;

}
	
void test1(void)
{
	vector<string> numbers;
	Stack<string> stack;
	cout<<"stack is empty?"<<stack.empty()<<endl;
	char ch='a';
	stack.push(string(3,ch));
	cout<<"stack is empty?"<<stack.empty()<<endl;

	for(int idx=1;idx!=11;++idx)
	{
		stack.push(string(3,ch+idx));
	}

	cout<<"stack is full?"<<stack.full()<<endl;

	while(!stack.empty()){
		cout<<stack.top()<<endl;
		stack.pop();
	}
	cout<<"stack is full?"<<stack.empty()<<endl;

}
int main(void)
{
	//test0();
	test1();
}
