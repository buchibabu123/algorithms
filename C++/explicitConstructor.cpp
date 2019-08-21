#include <iostream>

using namespace std;



class Base
{

	public:
		Base()
		{
			cout <<"constructor"<<endl;

		}
	
		~Base()
		{
			cout <<"destructor"<<endl;
		}

};


int main()
{

Base(); // a nameless object called and deleted immediately

cout <<"------"<<endl;
Base B; // an object gets created ,constructor gets called and once he scope is goes out then the desctructor called

B.~Base();  // here the desctructor gets called but the problem is during run time desctructor calles if object goes out of scope . but if we dot it explictly the desctructor called twise dangeor code in placement new we  will call desctructor explictly


char *memory = new char[4 * sizeof(Base)];

Base *ptr1 = new (&memory[0])Base();
Base *ptr2 = new (&memory[sizeof(Base)])Base();
ptr1->~Base();
ptr2->~Base();
delete memory;



}
