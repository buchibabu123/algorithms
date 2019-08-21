/*
SYNTAX :  dynamic_cast < new type >expression

dynamic cast is used to check corect down cast at runtime
--> need at least one virtual function in base class
--> if the  cast successfull the dynamic cast returns value os type new type
--> if the cast fails and the new type is of pointer type the dynamic cast returns NULL pointer 
--> if the cast fails and the new type is of reference type then it types an exception of type std::bad_cast

*/

#include <iostream>


using namespace std;


int main()
{


	return 0;
}

