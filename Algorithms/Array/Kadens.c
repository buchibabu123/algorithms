#include <stdio.h>

int main()
{

	int arr[] = {-2,-3,4,-1,-2,1,5,-3};
	int size = sizeof(arr)/sizeof(int);

	int i =0,start=0,end=0,s=0;
	int max_ending_here = 0,max_so_far = 0;
	for(i=0;i<size;i++)
	{

		max_ending_here = max_ending_here + arr[i];
		if (max_ending_here<0){
			max_ending_here = 0;
			s = i+1;
			continue;
			}
		if (max_ending_here>max_so_far)
			{
			max_so_far = max_ending_here;
			start = s;
			end  = i;
			}
	}

	printf("Maximum sum is [ %d ]\n",max_so_far);
	return 0;
}
