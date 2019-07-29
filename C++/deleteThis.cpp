/*

delete this will work only on dynamically allocated operator . on static allocated objects it gives run time error
it is not good to delete this pointer as there is chance that we can we the pointer later in programming that cause unexpected result

*/

#include <iostream>

using namespace std;

class Base
{

	public:
		Base()
		{
			cout <<"in constructor"<<endl;
		}
		void fun()
		{
			delete this;
		}
		~Base()
		{
			cout <<"in desctructor"<<endl;
		}


};

int main()
{

Base *b = new Base;
b->fun();

}
