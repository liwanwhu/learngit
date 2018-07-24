 ///
 /// @file    namespace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-24 19:41:07
 ///
 
#include <iostream>
//using namespace std;//1

namespace A
{

void displayA()
{
	std::cout<<"A::displayA()"<<std::endl;
}

}//end of namespace A

using namespace A;

void cout()
{
	std::cout<<"cout()"<<std::endl;
}

int main(){
	//A::displayA();
	displayA();
	cout();
	return 0;
}
