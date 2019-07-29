

/*

#1 ) performs implicit conversion between types float to int ,int to float , pointer conversion 
#2 ) checks pointer conversion and returns error if conversion is not valid  ( int *ptr =static_cast<int*>(&c); )
#3 ) static cast avoid cast from derived to private base pointer
#4 )  static cast should be prefered when converting to void* or from void* 
 */

/*	why to use static_cast		*/

/*

   1.) for compatable type conversion like int to float ..
   2.) to avoid unrelated pointer conversion
   3.) finding is easy
   4.) to check code at compilation time for errors


 */

#include <iostream>

using namespace std;

#if 0

int main()
{



	int a = 10;


	float b = static_cast<float>(a);
	cout <<b<<endl;

	char c;

	/* this line fails in C++ with static_cast as it is dangerous to assign character variable address to integer pointer, while accessing value at pointer we will get gangeroius results ( memory voilation ) , but it is safe in C */

	int *ptr =static_cast<int*>(&c); // throws error at compile time 
	//int *ptr =(&c);  // pass at compile time but fail in run time
	*ptr = 100;



	return 0;
}

#endif

// #3 ) static cast avoid cast from derived to private base pointer

class Base
{};

class Derived : private Base
{};


int main()
{

	Derived D;
	Base *p = (Base*)(&D);  // this will work 
	Base *p = static_cast<Base*>(&D); // this gives compilation error as we derived Derived class from base as private ( error: ‘Base’ is an inaccessible base of ‘Derived’ ) 


	int i = 10;
	void *ptr = static_cast<void*>(&i);
	int *ip = static_cast<int*>(ptr);

}

