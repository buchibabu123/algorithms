#include <iostream>
#include <stdio.h>

int fun(int a)
{
	int count =0;
	int val=1;
	for(int i=0;i<=31;i++)
	{

		if( a>>i & val)
			count+=1;
		printf("%d ",( a >> i) & val);
	}
	printf("\n");
	return count;
}

int main()
{

	int a = 10;

	printf("==[%d]\n",fun(a));

}


