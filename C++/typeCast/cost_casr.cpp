#include <iostream>


using namespace std;


/* const_cast is typically used to cast away the constness of objects. It is the only C++ style that can do this. 

   The syntax is:
   const_cast < type-name > (expression) 		

The reason for this operator is that we may have a need for a value that is constant most of the time but that can be changed occasionally. In such a case, we can declare the value as const and use const_cast when we need to alter the value 
*/


int main()
{

	const char *ptr = "abced";

# if 0

	char *nonConstPtr = (ptr); // this will give compilation error

# endif
	char *nonConstPtr = const_cast<char *>(ptr); // this will work

	return 0;
}

