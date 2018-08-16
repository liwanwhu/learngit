 ///
 /// @file    packaging.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-26 21:48:40
 ///
#include <pthread.h>

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;

class MutexLock
{
public:
	void lock()
	{
		pthread_mutex_lock(_pMutex);
	}

	void unlock()
	{
		pthread_mutex_unlock(_pMutex);
	}

	void destory()
	{
		pthread_mutex_destroy(_pMutex);
	}

	MutexLock()
		:_pMutex(new pthread_mutex_t())
	{
		pthread_mutex_init(_pMutex,NULL);
	}

public:
	friend class Conditon;

private:
	pthread_mutex_t * _pMutex;	
};

class Conditon
{
public:
	void wait(){
		pthread_cond_wait(_pCond,_lock._pMutex);
	//friend void Conditon::wait();
	}
	void notify()
	{
		pthread_cond_signal(_pCond);
	}
	void notifyall()
	{
		pthread_cond_broadcast(_pCond);
	}

	void destory()
	{
		pthread_cond_destroy(_pCond);
	}

	Conditon()
		:_pCond(new pthread_cond_t())
	{
		pthread_cond_init(_pCond,NULL);
	}
private:
	MutexLock _lock;
	pthread_cond_t * _pCond;
};

Conditon cond;
MutexLock lock;

void *thread_fun(void *)
{
	cout<<"before wait"<<endl;
	lock.lock();
	cond.wait();
	lock.unlock();
	cout<<"i am child,i will exit "<<endl;
}
int main(void)
{
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,thread_fun,NULL);
	sleep(1);
	cond.notify();
	pthread_join(thread_id,NULL);
	cond.destory();
	lock.destory();

	return 0;
}
