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
    int *bt,*p_no,*type,i,j,n,sys_pro=0,*wt,*tat,count=0,*c,time=0,tq_s=5,tq_u=2;
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    bt=(int *)malloc(n*sizeof(int));
    p_no=(int *)malloc(n*sizeof(int));
    type=(int *)malloc(n*sizeof(int));
    wt=(int *)malloc(n*sizeof(int));
    tat=(int *)malloc(n*sizeof(int));
    c=(int *)malloc(n*sizeof(int));;
    for(i=0;i<n;i++)
    {
        printf("Enter burst time of the new process %d: ",i+1);
        scanf("%d",&bt[i]);
        c[i]=bt[i];
        printf("Enter whether the above process is system(0) or user (1) process: ");
        scanf("%d",&type[i]);
        p_no[i]=i+1;
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        if(type[i]==0)
            sys_pro++;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(type[j]>type[j+1])
            {
                swap(&p_no[j],&p_no[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&type[j],&type[j+1]);
               swap(&c[j],&c[j+1]);
            }
        }
    i=0;
    while(count<sys_pro)
    {
        if(c[i]>tq_s)
        {
            if(c[i]==bt[i])
                wt[i]=time;
            time+=tq_s;
            c[i]-=tq_s;
        }
        else
        {
            if(c[i]==bt[i])
                wt[i]=time;
            time+=c[i];
            c[i]=0;
            tat[i]=time;
            count++;
        }
        i=(i+1)%sys_pro;
        while(c[i]==0 && count!=sys_pro)
            i=(i+1)%sys_pro;
    }
    i=sys_pro;
        while(count<n)
        {
            if(c[i]>tq_u)
            {
                if(c[i]==bt[i])
                    wt[i]=time;
                time+=tq_u;
                c[i]-=tq_u;
            }
            else
            {
                if(c[i]==bt[i])
                    wt[i]=time;
                time+=c[i];
                c[i]=0;
                tat[i]=time;
                count++;
            }
            if(i==n-1)
                i=sys_pro;
            else
                i=(i+1)%n;
            while(c[i]==0 && count!=n)
            {  if(i==n-1)
                    i=sys_pro;
                else
                    i=(i+1)%n;
            }
        }
    printf("Process NO\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("System Process\n\n");
    for(i=0;i<n;i++)
    {
        if(i==sys_pro)
            printf("\nUser Process\n\n");

        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p_no[i],bt[i],wt[i],tat[i]);
    }
}
