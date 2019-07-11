#include <iostream>

using namespace std;



class Base
{

	public:

		virtual void fun()
		{

			cout <<"in Base fun"<<endl;
		}
		Base()
		{
			cout <<"Base constructor"<<endl;
		}
		Base(int a)
		{
			cout <<"Base constructor"<<endl;
		}
		virtual void fun2()
		{
		cout <<"in Base fun2"<<endl;
		}


};

class Derived : public Base
{

	public:

		void fun()
		{

			cout <<"in Derived Base"<<endl;

		}
		virtual void fun2()
		{
		cout <<"in Derived fun2"<<endl;
		}

};


int main()
{

	Base *p;
	Derived D;
	p = &D;
	p->fun();
//	D.fun();
//	Base B(10);

}
