#include <iostream>

using namespace std;



struct Base
{

	short a ;
	short b;
};

struct Derived 
{

	int val;

};


int main()
{
	struct Base B;
	B.a = 1;
	B.b = 2;
	Derived *D = reinterpret_cast<Derived*>(&B);
	cout <<D->val<<endl;



	return 0;
}
