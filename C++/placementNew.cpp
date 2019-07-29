/*

when we use " new  operator " every time the control goes from userspace to kernal space for memoey allocation but if we need to allocate more number of objects calling new every time is an expensive operation ( switching from user to kernel and searching for memory  )


programmer explicitly construct and desctruct objects of his choice at any time at known  memory location 

Placement new is a variation new operator in C++. Normal new operator does two things : (1) Allocates memory (2) Constructs an object in allocated memory.

Placement new allows us to separate above two things. In placement new, we can pass a preallocated memory and construct an object in the passed memory. 


Normal new allocates memory in heap and constructs objects tehre whereas using placement new, object construction can be done at known address

As it allows to construct an object on memory that is already allocated , it is required for optimizations as it is faster not to re-allocate all the time. There may be cases when it is required to re-construct an object multiple times so, placement new operator might be more efficient in these cases.


================== uses ====================

Useful when building a memory pool, a garbage collector or simply when performance and exception safety are paramount.
There’s no danger of allocation failure since the memory has already been allocated, and constructing an object on a pre-allocated buffer takes less time.
This feature becomes useful while working in an environment with limited resources


================== uses ====================

*/

#include <iostream>

using namespace std;


class Base
{

	int num;
	public:

	Base();
	~Base();

};


Base::Base()
{

	cout <<"Base class Constructor"<<endl;

}

Base::~Base()
{

	cout <<"Base class Destructor"<<endl;
}

int main()
{

	Base *B = new Base(); // Normal Call 
	delete B;

	char *memory = new char[10*sizeof(Base)];
	
	Base *B1 = new (&memory[0])Base();
	Base *B2 = new (&memory[sizeof(Base)])Base();
	B1->~Base(); // we need to call destructor explicitly as we are constructing objects on known memory
	B2->~Base();	
	delete memory;


}
