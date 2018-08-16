 ///
 /// @file    heapsort.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-06 19:43:34
 ///
#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename T,typename Compare =std::less<T> >
class HeapSort
{
public:
	HeapSort(T * arr,int size)
	:_size(size)
	,_arr(arr,arr+size)
	{
	}
	void heapAdjust(int  pos,int & size);
	void sort();
	void print();
private:
	void swap(T & lhs,T & rhs){
		T tmp;
		tmp=lhs;
		lhs=rhs;
		rhs=tmp;
	}
private:
	vector<T> _arr;
	int _size;
};

template <typename T>
struct compare
{
	bool operator()(const T & lhs, const T & rhs) const
	{
		return lhs<rhs;
	}
};

template <typename T, typename Compare>
void HeapSort<T,Compare>::heapAdjust(int  pos,int & size)
{
	int dad=pos;
	int son=2*dad+1;
	while(son<size){
		if(son+1<size&&_arr[son]<_arr[son+1])
			++son;
		if(_arr[dad]<_arr[son])
		{
			swap(_arr[dad],_arr[son]);
			dad=son;
			son=2*dad+1;
		}
		else
			break;
	}
}

template <typename T, typename Compare >
void HeapSort<T,Compare>::sort()
{
	int i;
	for(i=_size/2-1;i>0;--i){
		heapAdjust(i,_size);
	}
	swap(_arr[0],_arr[_size-1]);
	for(i=_size-1;i>0;--i)
	{
		heapAdjust(0,i);
		swap(_arr[0],_arr[i-1]);
	}
}

template <typename T, typename Compare>
void HeapSort<T,Compare>::print()
{
	int i;
	for(i=0;i<_size;++i)
		cout<<_arr[i]<<" ";
	cout<<endl;
}

int test0(void)
{
	int arr[10]={9,8,7,4,5,6,3,2,1,0};
	HeapSort<int> array(arr,10);
	array.print();
	array.sort();
	array.print();
	return 0;
}
int test1(void)
{
	string arr[5]={"the","frogurt","is","also","cursed"};
	HeapSort<string> array(arr,5);
	array.print();
	array.sort();
	array.print();
	return 0;
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
