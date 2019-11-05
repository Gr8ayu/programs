#include<stdio.h>

int maxsize(int p, int *a, int bs)
{
    int i,j,max,k;

    for(i=0;i<bs;i++)
    {
        max=a[0];
        for(j=1;j<bs;j++)
        {

            if(a[j]>max)
            {
                max=a[j];
                k=j;
            }
        }
    }

    if(max>p && max>0)
    {
        *(a+k)=*(a+k)-p;
        return k;
    }
    else
        return -2;
}

int main()
{
    int bs,ps;
    printf("Enter the block size:\n");
    scanf("%d",&bs);
    printf("Enter the process size:\n");
    scanf("%d",&ps);
    int b_size[bs],p_size[ps],i=0,j=0,max;
    printf("Enter all the block sizes:\n");
    for(i=0;i<bs;i++)
    {
        scanf("%d",&b_size[i]);
    }
    printf("Enter all the process sizes:\n");
    for(i=0;i<ps;i++)
    {
        scanf("%d",&p_size[i]);
    }
    printf("\nProcess No. \tProcess Size\tBlock No.\n");
    for(i=0;i<ps;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,p_size[i],maxsize(p_size[i],b_size,bs)+1);
    }
    return 0;
}
