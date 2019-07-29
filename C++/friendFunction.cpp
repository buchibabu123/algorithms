#include <stdio.h>
#include <iostream>

using namespace std;

class Base
{
	int val;
	public:
	Base(int i):val(i)
	{}

	friend int fun(Base &);
	friend int fun();
	friend int main();



};

Base b(10);
int fun(Base &b)
{

	cout <<"private value =="<<b.val<<endl;
}
int fun()
{

	cout <<"private value =="<<b.val<<endl;
}
int main()
{

	fun(b);
	fun();

}
