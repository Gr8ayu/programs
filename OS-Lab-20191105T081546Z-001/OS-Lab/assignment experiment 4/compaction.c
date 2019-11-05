#include<stdio.h>
#include<stdlib.h>

void bestsize(int p, int *a, int bs)
{
    int i,j,best,k=-1;
    for(i=0;i<bs;i++)
    {
        best=10000;
        if(best>=0)
        {
            for(j=i+1;j<bs;j++)
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
    }
}

int main()
{
    int i, j, best, bs, ps, *b_size, *p_size, sum=0;
    printf("Enter the number of blocks: ");
    scanf("%d",&bs);
    b_size=(int *)calloc(bs,sizeof(int));
    printf("Enter the number of processes: ");
    scanf("%d",&ps);
    p_size=(int *)calloc(ps,sizeof(int));
    printf("Enter all the block sizes:\n");
    for(i=0;i<bs;i++)
        scanf("%d",&b_size[i]);
    printf("Enter all the process sizes:\n");
    for(i=0;i<ps;i++)
        scanf("%d",&p_size[i]);
    for(i=0;i<ps;i++)
        bestsize(p_size[i],b_size,bs);
    for(i=0;i<bs;i++)
        sum+=b_size[i];
    printf("Memory block left after compaction: %d\n",sum);
    return 0;
}
