
/*

   operator conversion_type
   {

   }

   A conversion function that belongs to a class X specifies a conversion from the class type X to the type specified by the conversion_type. The following code fragment shows a conversion function called operator int():

 */

#include <iostream>

using namespace std;



class Base
{
	int b;
	public:

	Base(int x=0):b(x)
	{
	}

	operator int()
	{

		return b;

	}
	operator int*()
	{
		return NULL;
	}
};

int main()
{

	Base B(55);
	int b = int(B);
	int *x = (int*)(B);
	cout <<b<<endl;
	if(x == NULL)
		cout <<"conversion works"<<endl;
	else	
		cout <<"no conversion"<<endl;

}
