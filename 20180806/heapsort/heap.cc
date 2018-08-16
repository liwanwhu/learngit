 ///
 /// @file    heap.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-08-06 20:11:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#define N 10
void swap(int & a,int & b){
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void heap_max(int *a, int pos ,int len)
{
	int dad=pos;
	int son = 2*dad+1;
	while(son<len)
	{
		if(son+1<len&&a[son]<a[son+1])
			son++;
		if(a[dad]<a[son])
		{
			swap(a[dad],a[son]);
			dad=son;
			son=2*dad+1;
		}
		else
			break;
	}
}

void arr_heap(int *a )
{
	int i;
	for(i=N/2-1;i>=0;i--)
	{
		heap_max(a,i,N);
	}
	swap(a[0],a[N-1]);
	for(i=N-1;i>0;i--)
	{
		heap_max(a,0,i);
		swap(a[0],a[i-1]);
	}
}

void print(int * arr){
	int i;
	for(i=0;i<N;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int arr[10]={9,8,7,4,5,6,3,2,1,0};
	print(arr);
	arr_heap(arr);
	print(arr);

	return 0;
}
	
	
