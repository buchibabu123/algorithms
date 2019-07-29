#include <iostream>

using namespace std;


class A{};
class B{};


int main()
{


/*

Only reinterpret_cast can be used to convert a pointer to an object to a pointer to an unrelated object type. The dynamic_cast would fail at run-time, however on most compilers it will also fail to compile because there are no virtual functions in the class of the pointer being casted.


*/


A *base = new A;

//B *ptr1 = static_cast<B*>(base);
//B *ptr2 = dynamic_cast<B*>(base);
//B *ptr3 = const_cast<B*>(base);
B *ptr4 = reinterpret_cast<B*>(base);

}
