#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,r,al[100][100],re[100][100],av[100],f[100],i,j,k,flag;
    printf("Enter the number of proceess : ");
    scanf("%d",&p);
    printf("Enter the number of resources");
    scanf("%d",&r);
    for(i=0;i<p;i++)
        f[i]=0;
    for(i=0;i<r;i++)
    {
        printf("Number of available instances of res %d:  ",i+1);
        scanf("%d",&av[i]);
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("For Process %d ,number of allocated instances of res %d : ",i+1,j+1);
            scanf("%d",&al[i][j]);
        }
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("For Process %d ,number of current request of instances of res %d : ",i+1,j+1);
            scanf("%d",&re[i][j]);
        }
    }
for(k=0;k<p;k++)
{
    for(i=0;i<p;i++)
    {
        if(f[i]==0)
        {flag=0;
            for(j=0;j<r;j++)
            {
                if(re[i][j]>av[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(j=0;j<r;j++)
                {
                    av[j]+=al[i][j];
                    f[i]=1;
                }
            }
        }

    }
}printf("The Process under deadlock are: ");
for(i=0;i<p;i++)
{

    if(f[i]==0)
        printf("%d\t",i+1);

}

    return 0;
}
