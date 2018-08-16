 ///
 /// @file    myVector.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-08 16:35:02
 ///
 
#include <iostream>
#include <memory>
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
	:_start(0)
	,_finish(0)
	,_end_of_storage(0)
	{
	}

	~Vector()
	{
		if(_start)
		{
			while(_start!=_finish)
				_alloc.destroy(--_finish);
			_alloc.deallocate(_start,capacity());
		}
	}

	T * begin() const {return _start;}
	T * end()const {return _finish;}

	T & operator[](size_t index){return _start[index];}
	//T & operator[](size_t index){return *(_start+index);}

	void push_back(const T &ele);
	void pop_back();

	size_t size()const {	return _finish-_start;	}

	size_t capacity()const { return _end_of_storage-_start; }

	void print();

private:
	void reallocate();
private:
	static std::allocator<T> _alloc;
private:
	T * _start;
	T * _finish;
	T * _end_of_storage;
};
template <typename T>
void Vector<T>::push_back(const T &ele)
{
	if(size()==capacity())
		reallocate();
	_alloc.construct(_finish++,ele);
}

template <typename T>
void Vector<T>::pop_back()
{
	if(size()>0)
		_alloc.destroy(--_finish);
}

template <typename T>
void Vector<T>::print()
{
	for(T* iter=_start;iter!=_finish;++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
}

template <typename T>
void Vector<T>::reallocate()
{
	int oldcapacity=capacity();
	int newcapacity=(oldcapacity>0? 2*oldcapacity:1);
	T * tmp=_alloc.allocate(newcapacity);
	if(newcapacity>0)
	{
		std::uninitialized_copy(_start,_finish,tmp);
		while(_start!=_finish)
			_alloc.destroy(--_finish);
		_alloc.deallocate(_start,oldcapacity);
	}
	_start=tmp;
	_end_of_storage=_start+newcapacity;
	_finish=_start+oldcapacity;
}

template <typename T>
void display(const Vector<T> & vec)
{
	cout<<"capacity:"<<vec.capacity()<<endl;
	cout<<"size:"<<vec.size()<<endl;
}
	
template <typename T>
std::allocator<T> Vector<T>::_alloc;

int test0(void)
{
	Vector<int> numbers;
	display(numbers);

	numbers.push_back(1);
	display(numbers);

	numbers.push_back(2);
	display(numbers);

	numbers.push_back(3);
	display(numbers);
	numbers.push_back(4);
	display(numbers);
	numbers.push_back(5);
	display(numbers);

	for(auto & elem : numbers)
	{
		cout << elem << " ";
	}
	cout << endl;

	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(size_t idx = 0; idx != numbers.size(); ++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	return 0;
}

#if 0
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
#endif

int test1(void)
{
	Vector<Point> numbers;
	display(numbers);

	numbers.push_back(Point(1,2));
	display(numbers);

	numbers.push_back(Point(2,3));
	display(numbers);

	numbers.push_back(Point(3,4));
	display(numbers);
	numbers.push_back(Point(4,5));
	display(numbers);
	numbers.push_back(Point(5,6));
	display(numbers);

	for(auto & elem : numbers)
	{
		cout << elem << " ";
	}
	cout << endl;

	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(size_t idx = 0; idx != numbers.size(); ++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	return 0;
}
int main()
{
	cout<<"int:"<<endl;
	test0();
	cout<<"Point"<<endl;
	test1();
	return 0;
}
