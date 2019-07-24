
/*

#1 ) performs implicit conversion between types float to int ,int to float , pointer conversion 

 */

#include <iostream>

using namespace std;



int main()
{



	int a = 10;


	float b = static_cast<float>(a);
	cout <<b<<endl;

	char c;

	int *ptr =static_cast<int*>(&c);
	*ptr = 100;



	return 0;
}
