#include <iostream>

using namespace std;


class Base
{

	public:
		void fun()
		{
			cout <<"in base fun"<<endl;

		}

};

class Derived1: virtual public Base
{


};

class Derived2: virtual public Base
{


};

class Derived: public Derived1,public Derived2
{


};


int main()
{

Derived D;
D.fun();

}
