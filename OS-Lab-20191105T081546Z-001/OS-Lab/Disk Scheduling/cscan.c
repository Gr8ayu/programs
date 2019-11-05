#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(arr[i]>arr[j])
			{
				int temp=*(arr+j);
				*(arr+j)=*(arr+i);
				*(arr+i)=temp;
			}
}

int main()
{
	int n, i, low=0, high, loc, total=0, *arr;
	printf("Enter the disk size: ");
	scanf("%d",&high);
	high--;
	printf("Enter the length of the request queue: ");
	scanf("%d",&n);
	arr=(int *)calloc(n+3,sizeof(int));
	printf("Enter all the track numbers in the request queue:\n");
	arr[0]=low;
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);	
	printf("Enter the current location of the R/W head: ");
	scanf("%d",&loc);
	arr[n+1]=loc;
	arr[n+2]=high;
	sort(arr, n+3);
	for(i=1;i<(n+3);i++)
	{
		if(arr[i-1]==loc)
			continue;
		total+=abs(arr[i-1]-arr[i]);
	}
	total+=abs(high-low);
	printf("Total number of track movements= %d\nAverage seeking time= %.3f\n",total,total/(float)n);
	return 0;
}
