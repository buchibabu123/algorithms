/*

   if a class has one argument constructor if we pass valus using assignment operator Like Base B = Value then the one argument constructor gets called implicitly to avoid this just add explicit keyword in front of one argument constcuctor then the compiler throws error if there is any implicit call 

 */

#include <iostream>

using namespace std;

class Base
{

	int data;

	public:

	Base();
	explicit Base(int );

};

Base::Base()
{

	cout <<"Base class Constructor"<<endl;

}

Base::Base(int a)
{

	cout <<" One argument constructor"<<endl;

}

void fun(Base B)
{

	// some code

}


int main()
{
	Base B;
	Base B1(10);
	Base B2 = 20;  // implicit call  compiler treats this as Base B2(20);
	fun(B);
	fun(50);  // implicit call 
	return 0;
}
