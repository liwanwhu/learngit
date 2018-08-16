 ///
 /// @file    line.cc
 /// @author  liwan(1459940006@qq.com)
 /// @date    2018-07-28 19:13:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define LOG(level,format,...)/
	do/
	{/
		fprintf(stderr,"[%s|%s@%s,%d]" format"\n",/
				level,__func__,__FILE__,__LINE__,##__VA_ARGS__);
	}while(0);
	
int main(void)
{
	LOG(LOG_DEBUG,"a=%d",10);
	return 0;
}
