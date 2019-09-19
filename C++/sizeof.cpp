#include <iostream>

using namespace std;

/*

   1--> sizeof is a operator not function
   2--> sizeof os resolved at compile time 
   3--> xpressions in sizeof are not evaluated
   4--> paranthesis are not mandatory in sizeof

 */


double fun()
{

	cout <<"dummy"<<endl;

}

int main()
{


	int x = 10;

	cout <<"size is "<<sizeof(x++)<<endl; // it only prints sizeof x . but the expression x+++ wont be evaluates at compile time sizeof(x++) replaced with sizeof(int) --> value 4
	cout <<"value is "<<x<<endl;  // as expressions not evaluated in sizeof() it prints 4
	cout <<sizeof(fun())<<endl; // as sizeof is compile time operator  here fun wont be called it prints sizeof the return type of fun  in this case it s sizeof double if return type is int it is 4 (sizeof int)  
	cout <<sizeof fun()<<endl; // paranthesis are not mandatory

	return 0;
} 
