 ///
 /// @file    vector.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-08 16:35:02
 ///
 
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
public:
	Point(int x=0,int y=0)
	:_x(x)
	,_y(y)
	{
	}
	~Point(){
	}

	friend ostream & operator<<(ostream & os,const Point & hs);
private:
	int _x;
	int _y;
};
ostream & operator<<(ostream & os,const Point & hs)
{
	os <<"("<<hs._x
		<<","<<hs._y
		<<")";
	return os;
}

template <typename T>
class Vector
{
public:
	Vector()
	{
		_start=(T *)new T[1024]();
		_finish=_start;
		_end_of_storage=_start+1024;
	}
	~Vector()
	{
		 _finish=NULL;
		_end_of_storage=NULL;
		delete [] _start;
		_start=NULL;
	}
	void push_back(const T &ele)
	{
		*_finish++=ele;
	}

	void pop_back()
	{
		--_finish;
	}

	int size()
	{
		return _finish-_start;
	}

	int capacity()
	{
		return _end_of_storage-_start;
	}

//	template <typename container>
	void print()
	{
		for(T* iter=_start;iter!=_finish;++iter)
		{
			cout<<*iter<<" ";
		}
		cout<<endl;
	}
#if 0
private:
	void reallocate();
private:
	static std::allocator<T> _alloc;
#endif
private:
	T * _start;
	T * _finish;
	T * _end_of_storage;
};

void test0()
{
	Vector<int> vector;
	cout<<"capacity:"<<vector.capacity()<<endl;
	vector.push_back(1);
	cout<<"size:"<<vector.size()<<endl;
	vector.print();
	vector.pop_back();
	vector.print();
}

void test1()
{
	Vector<Point> vector;
	cout<<"capacity:"<<vector.capacity()<<endl;
	vector.push_back(Point(1,2));
	cout<<"size:"<<vector.size()<<endl;
	vector.print();
	vector.pop_back();
	vector.print();
}

int main()
{
	//test0();
	test1();
	return 0;
}
