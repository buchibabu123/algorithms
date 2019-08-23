#include <iostream>

using namespace std;


/*

   for templlate functions and classes the static variablle is shared for only related functions/classes ( same datatype  ) , for unrelated functions/classes seperate static variable is created

 */

template <typename T>

T fun(T value)
{

	static int var = 10;
	++var;
	cout <<"value == "<<var<<endl;

}


template <typename T>

class Base
{

	static int var;

	public:

	void Print();


};

template <typename T>
int Base<T>::var=10;

template <typename T>
void Base<T>::Print()
{

	++var;
	cout <<"class value == "<<var<<endl;

}

int main()
{

	fun<int>(10); // --> static variable created for function with int as data type and assigned with value 10
	fun<int>(20); // --> already static is created for int data type it uses the same
	fun<float>(20); // --> creats new static variable for function with double
	fun<char>(20);

	Base<int> B1;
	B1.Print();
	B1.Print();
	Base<char> B2;
	B2.Print();

	return 0;
}
