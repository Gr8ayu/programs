#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, loc, total=0, *arr;
	printf("Enter the length of the request queue: ");
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	printf("Enter the track numbers in the request queue:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the current location of R/W head: ");
	scanf("%d",&loc);
	for(i=0;i<n;i++)
	{
		total+=abs(arr[i]-loc);
		loc=arr[i];
	}
	printf("Total number of track movements: %d\nAverage seek time: %.3f\n",total, total/(float)n);
	return 0;
}
