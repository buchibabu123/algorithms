#include <iostream>

using namespace std;



int main()
{

	try{

		throw 0;

	}
	catch(char c)
	{
		cout <<"char"<<endl;

	}
	catch(int num)
	{

		cout <<"integer"<<endl;

	}

	cout <<"after exception"<<endl;

}
