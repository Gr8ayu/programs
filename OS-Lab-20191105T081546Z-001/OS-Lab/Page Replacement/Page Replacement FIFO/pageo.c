#include<stdio.h>

int main()
{
        printf("Enter the no. of Page numbers:\n");
        int i=0,j=0,n,fr,k=0,flag=0;
        scanf("%d",&n);
        printf("Enter the Pages:\n");
        int arr[n];
        for(i=0;i<n;i++)
        {
                scanf("%d",&arr[i]);
        }
        printf("Enter the Frame Length:\n");
        scanf("%d",&fr);
        int arr2[fr],fault=0,hit=0;
        for(i=0;i<fr;i++)
        {
                arr2[i]=arr[i];
                fault+=1;
                for(j=0;j<fr;j++)
                {
                        printf("%d ",arr2[j]);
                }
                printf("\n");
        }
        for(i=fr;i<n;i++)
        {
                flag=0;
                for(j=0;j<fr;j++)
                {
                        if(arr2[j]==arr[i])
                        {
                                hit+=1;
                                flag=1;
                                break;
                        }
                }
                if(flag==0)
                {
                        arr2[k]=arr[i];
                        k=(k+1)%fr;
                        fault+=1;
                        flag=1;
                }
                for(j=0;j<fr;j++)
                {
                        printf("%d ",arr2[j]);
                }
                printf("\n");
        }
        printf("\nFaults ----> %d",fault);
        printf("Hits-------> %d",hit);
        printf("\n");
        return 0;
}
