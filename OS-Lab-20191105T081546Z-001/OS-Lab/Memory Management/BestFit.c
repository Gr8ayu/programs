#include<stdio.h>
#include<math.h>

int bestsize(int p, int *a, int bs)
{
    int i,j,best,k=-1;
    for(i=0;i<bs;i++)
    {
        best=10000;
        if(best>=0)
        {
            for(j=i;j<bs;j++)
                {
                    if(*(a+j)-p<best && *(a+j)-p>=0)
                    {
                        best=*(a+j)-p;
                        k=j;
                    }
                }
            break;
        }
    }
    if(k>=0 && k<bs && best>=0)
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
    int b_size[bs],p_size[ps],i=0,j=0;
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
        printf("%d\t\t%d\t\t%d\n",i+1,p_size[i],bestsize(p_size[i],b_size,bs)+1);
    }
}
