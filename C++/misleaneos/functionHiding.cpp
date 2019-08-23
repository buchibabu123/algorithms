#include <iostream>

using namespace std;

/*

if Derived class has same function name as in Base class all the Base class functions with that name are hided in derived class 
if the Derived class doesn't have the function signature as in Base then we cal access that function in Derived object without any issue
to call Hided function we cal use scope resolution operator Base::fun() or using Base in Derived


*/

class Base
{

	public:

		void fun()
		{
			cout <<"in Base fun"<<endl;

		}

};

class Derived : public Base
{

	public:
		void fun(int a)
		{
			cout <<"Derived fun"<<endl;
		}
		void xyz()
		{
			cout <<"in Derived xyz"<<endl;

		}

};


int main()
{

	Derived D;
	D.fun();
	D.xyz();

}
