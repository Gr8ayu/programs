#include<stdio.h>
#include<math.h>

int firstsize(int p,int *a,int bs)
{
    int i=0,k,flag=0;

    for(i=0;i<bs;i++)
    {
        if(p<a[i])
        {
            *(a+i)=*(a+i)-p;
            flag=1;
            return i;
        }
    }
    if(flag==0)
    {
        return -2;
    }
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
        printf("%d\t\t%d\t\t%d\n",i+1,p_size[i],firstsize(p_size[i],b_size,bs)+1);

    }

    return 0;
}
