#include <stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int *bt,*p_no,*type,i,j,n,user_pro=0,sys_pro=0,*priority,*wt,*tat;

    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    bt=(int *)malloc(n*sizeof(int));
    p_no=(int *)malloc(n*sizeof(int));
    type=(int *)malloc(n*sizeof(int));
    priority=(int *)malloc(n*sizeof(int));
    wt=(int *)malloc(n*sizeof(int));
    tat=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter burst time of the new process: ");
        scanf("%d",&bt[i]);
        printf("Enter whether the above process is system(0) or user (1) process: ");
        scanf("%d",&type[i]);
        printf("Enter the priority of the above process(1-3): ");
        scanf("%d",&priority[i]);
        p_no[i]=i+1;
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        if(type[i]==0)
            sys_pro++;
        else
            user_pro++;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(type[j]>type[j+1])
            {
                swap(&p_no[j],&p_no[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&type[j],&type[j+1]);
                swap(&priority[j],&priority[j+1]);

            }
        }

    for(i=0;i<sys_pro;i++)
        for(j=0;j<sys_pro-i-1;j++)
        {
            if(priority[j]>priority[j+1])
            {
                swap(&p_no[j],&p_no[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&type[j],&type[j+1]);
                swap(&priority[j],&priority[j+1]);
            }
        }


    for(i=sys_pro;i<n;i++)
        for(j=sys_pro;j<n-i+sys_pro-1;j++)
        {
            if(priority[j]>priority[j+1])
            {
                swap(&p_no[j],&p_no[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&type[j],&type[j+1]);
                swap(&priority[j],&priority[j+1]);
            }
        }

    wt[0]=0;
    tat[0]=bt[0];
    printf("Process NO\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p_no[0],bt[0],priority[0],wt[0],tat[0]);
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p_no[i],bt[i],priority[i],wt[i],tat[i]);

    }

}
