#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],b[10],i,j,flag,c[10],d,max,n,m,sum=0;
    printf("Enter the number of Process :-");
    scanf("%d",&n);
    printf("Enter the number of blocks of memory :-");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
     printf("Enter the size of Process %d :- ",i+1);
     scanf("%d",&a[i]);
    }

    for(i=0;i<m;i++)
    {
     printf("Enter the size of Memory block %d :- ",i+1);
     scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {   max=0;
        flag=0;
        for(j=0;j<m;j++)
        {
            if(a[i]<=b[j])
            {
                if(max<b[j])
                    {
                        max=b[j];
                        d=j;
                        flag=1;
                    }
            }
        }
        if(flag)
        {
            c[i]=d+1;
            b[d]-=a[i];

        }
        else
            c[i]=-1;
    }
    printf("\nProcess Number\t\tProcess Size\t\tBlock Number\n");
    for(i=0;i<n;i++)
    {   if(c[i]!=-1)
        printf("%d\t\t\t%d\t\t\t%d\n",i+1,a[i],c[i]);
        else printf("d\t\t\t%d\t\t\tNot Allocated\n",i+1,a[i]);
    }
    for(i=0;i<m;i++)
    {
        sum+=b[i];
    }
    printf("\nTotal available memory : %d\n",sum);
    return 0;
}
