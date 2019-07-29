#include <iostream>


using namespace std;



class Base
{

	public:
		Base(int x):a(x)
	{

	}
		int funBase()
		{
			cout <<"in fun base"<<endl;
		}
		int a;

};

class Derived : public Base
{

	public:
		Derived(int x):Base(x),b(x)
	{
	}
		int funDer()
		{

			cout <<"in fun der"<<endl;
		}
		int b;


};


int main()
{

	/*
	up casting can be done without any issue 
	*/
	Base base(10);
	Derived der(20);
	Base *b = static_cast<Base*>(&der);
	cout <<b->a<<endl;
	b->funBase();

	/*
	up casting can be done without any issue  but for downcasting we will get runtime issues when we dereference pointer ( pder->b ) here while accessing b we will get unexpected value
	*/
	Derived *pder = static_cast<Derived*>(&base);
	cout <<pder->a<<endl;
	cout <<pder->b<<endl;
	pder->funDer();	

	return 0;
}
