#include <iostream>

using namespace std;

class Base
{

	int data;

	public:

	Base();
	Base(int );

};

Base::Base()
{

	cout <<"Base class Constructor"<<endl;

}

Base::Base(int a)
{

	cout <<" One argument constructor"<<endl;

}

int main()
{
	Base B;
	Base B1(10);
	return 0;
}
