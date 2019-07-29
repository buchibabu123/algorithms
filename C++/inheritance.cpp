
#include <iostream>
#include <typeinfo>
//#include <bits/stdc++.h>

using namespace std;


class Base{
	int num;
	int num1;
	public:
	Base(){

		cout <<"in default base constructor    a== "<<endl;
	}
	Base(int a)
	{
		cout <<"in base constructor    a== "<<a<<endl;
		num = 25;
		num1 = 250;
	}

	int func()
	{
		cout <<" object address is "<<this<<endl;

		cout <<"in base func,val======"<<num<<endl;

	}

};
class Derived : public Base
{
	public:
	int val;
	Derived(int a):Base(a)
	{

		cout <<"in derived constructor"<<endl;
		val = 5;
	}
	int func()
	{
		cout <<" object address is "<<this<<endl;

		cout <<"in derived func , val ====="<<val<<endl;
	}

};

int main()
{

	//Base B(1);
	//Derived D(10);


	Base *p = new Derived(10);
	cout <<typeid(p).name()<<endl;
	p->func();
	Derived *d = (Derived*)p;
	cout <<typeid(d).name()<<endl;
	d->func();

	Derived D(56);
	cout <<"size is "<<sizeof(D)<<endl;
	int *ptr = (int*)&D;
	cout <<"First val == "<<*ptr<<endl;
	cout <<"Second val == "<<*(ptr + 1 )<<endl;
	cout <<"Third val == "<<*(ptr + 2 )<<endl;
	cout <<"First val == "<<ptr<<endl;
	cout <<"Second val == "<<(ptr + 1 )<<endl;
	cout <<"Third val == "<<(ptr + 2 )<<endl;
	cout <<"addressof object is "<<&D<<endl;
	cout <<"address of variable is "<<&(D.val)<<endl;
	cout <<"sizeo f base == "<<sizeof(Base)<<endl;



	return 0;
}
