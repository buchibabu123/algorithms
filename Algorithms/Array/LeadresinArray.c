/*
   Given an array of integers, print the leaders in the array. A leader is an element which is larger than all the elements in the array to its right.
   For example:
   Input Array:
   { 98, 23, 54, 12, 20, 7, 27 }
Output:
Leaders- 27 54 98

 */

#include <stdio.h>


int main()
{

	int Array[] = {-10,98,23,54,12,20,7,27,0};

	int Size = sizeof(Array)/sizeof(int);

	fprintf(stderr,"size of the given array is [ %d ]\n",Size);
	int Leader=0,isLeader = 0;
	
	int i =0;
	for(i=0;i<=Size-1;i++)
	{
		isLeader = 1;
		Leader = Array[i];
		for(int j=i+1;j<=Size-1;j++)
		{
			if(Array[i]>Array[j])
				continue;
			else
			{
				isLeader = 0;
				break;
			}
		
		}
			if(isLeader)
				fprintf(stderr,"%d\t",Leader);

	}

				fprintf(stderr,"\n");

}
