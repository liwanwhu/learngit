 ///
 /// @file    list_iterator.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-06 16:17:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ListItem
{
public:
	T value() const{return _value;}
	ListItem* next() const {return _next;}
private:
	T _value;
	ListItem* _next;
};

template <typename T>
class List
{
public:
	void insert_front(T value);
	ListItem<T>* front()const ;
	void insert_end(T value);
	void display(std::ostream &os = cout) const;
private:
	ListItem<T>* _end;
	ListItem<T>* _front;
	long _size;
};

template <typename Item>
struct ListIter
{
	Item* ptr;

	ListIter(Item* p=0)
	:ptr(p)
	{}

	Item& operator*() const
	{
		return *ptr;
	}

	Item* operator->() const
	{
		return ptr;
	}

	ListIter& operator++()
	{
		ptr=ptr->next();
		return *this;
	}

	ListIter& operator++(int)
	{
		ListIter tmp=*this;
		++*this;
		return *tmp;
	}

	bool operator==(const ListIter& i)const
	{
		return ptr == i.ptr;
	}

	bool operator!=(const ListIter& i) const
	{
		return ptr != i.ptr;
	}
};

void test0()
{
	List<int> mylist;

	for(int i=0;i<5;++i){
		mylist.insert_front(i);
		mylist.insert_end(i+2);
	}

	mylist.display();

	ListIter<ListItem<int>> begin(mylist.front());
	ListIter<ListItem<int>> end;
	ListIter<ListItem<int>> iter;

	iter=find(begin,end,3);
	if(iter==end)
		cout<<"not found"<<endl;
	else
		cout<<"found."<<iter->value()<<endl;
}
