#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void * operator new(size_t size)
{

	cout<<"size =="<<size<<endl;

	void *p = malloc(size);

	return p;
}

void  operator delete(void *p)
{
	cout<<"size =="<<endl;


}

class Base
{
	int val;
	public:
	Base()
	{
		cout <<"in base constructor"<<endl;
	}

};

int main()
{

	int *p = new int;
	delete p;

	Base *b = new Base;
	return 0;
}
