#include <stdio.h>
#define NILL 0
int Memo[100];
int fib(int n)
{

	if (n==0 || n==1)
		return n;
	return (fib(n-1) + fib(n-2));

}

#if 1
/* use this function to calculate fibonanci using bruteforce method*/ 
int FIB(int n)
{

//	int n  = 20;

	printf("Fibonanci is == [ %d ] \n",fib(n));
	return 0;

}

#endif

int _initialize(int n)
{
	for (int i=0;i<=n;i++)
		Memo[i] = NILL;



}

int Fib(int n)
{
	if(Memo[n]==NILL)
	{
		if(n<=1)
			Memo[n] = n;
		else
			Memo[n] = (Fib(n-1) + Fib(n-2));

	}	
	return Memo[n];

}

int main()
{

	_initialize(100);


	printf("Fibonanci is ==[ %d ]\n",Fib(40));

//	FIB(40);
	return 0;
}
