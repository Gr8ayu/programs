#include<stdio.h>
#include<stdlib.h>

int bestsize(int p, int *a, int bs)
{
    int j,best=10000,k=-1;
    for(j=0;j<bs;j++)
    {
        if((*(a+j)-p)<best && (*(a+j)-p)>=0)
        {
            best=(*(a+j)-p);
            k=j;
        }
    }
    if(k>=0 && k<bs && best>=0)
    {
        *(a+k)= (*(a+k)-p);
    }
    return (k-1);
}

int main()
{
    int i, j, k, value=0, bs, ps=0, *b_size, *temp, *p_size, *b_no, sum=0;
    printf("Enter the number of blocks: ");
    scanf("%d",&bs);
    b_size=(int *)calloc(bs,sizeof(int));
    temp=(int *)calloc(bs,sizeof(int));
    printf("Enter all the block sizes:\n");
    for(i=0;i<bs;i++)
    {
        scanf("%d",&b_size[i]);
        temp[i]=b_size[i];
    }
    p_size=(int *)calloc(ps+1,sizeof(int));
    b_no=(int *)calloc(ps+1,sizeof(int));
    while(value!=-1)
    {
        printf("Enter the process size (-1 to exit) :\n");
        scanf("%d",&value);
        if(value!=-1)
        {
            p_size=(int *)realloc(p_size,(ps+1)*sizeof(int));
            b_no=(int *)realloc(b_no,(ps+1)*sizeof(int));
            p_size[ps]=value;
            k=bestsize(p_size[ps],b_size,bs);
            b_no[ps]=k;
            ps++;
        }
    }
    for(i=0;i<bs;i++)
        sum+=b_size[i];
    printf("******** AFTER COMPACTION ********\n");
    printf("Block number Block Size Process numbers\n");
    for(i=0;i<bs;i++)
    {
        if(temp[i]!=b_size[i])
        printf("\t%d\t%d\t",i+1,temp[i]-b_size[i]);
        else if(i==(bs-1))
            printf("\t%d\t%d\t",i+1,sum);
        for(j=0;j<ps;j++)
            if(b_no[j]==(i-1))
                printf("%d ",j+1);
        printf("\n");
    }
    for(j=0;j<ps;j++)
        if(b_no[j]==-2)
            printf("Process %d not alloted memory\n",j+1);
    printf("Memory block left after compaction: %d\n",sum);
    return 0;
}
