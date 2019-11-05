#include<stdio.h>
#include<stdlib.h>
struct process
{
    int pid, bt, at;
};
void findwaitingtime(struct process proc[], int n, int wt[])
{
    int rt[n], i, j, check=0;
    for(i=0;i<n;i++)
        rt[i]=proc[i].bt;
    int complete=0, t=0, minm=10000, shortest=0, finish_time;
    while(complete!=n)
    {
        for(j=0;j<n;j++)
            if( (proc[j].at<=t) && (rt[j]<minm && rt[j]>0))
            {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        if(check==0)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm=rt[shortest];
        if(minm==0)
            minm=10000;
        if(rt[shortest]==0)
        {
            complete++;
            check=0;
            finish_time=t+1;
            wt[shortest]=finish_time - proc[shortest].bt - proc[shortest].at;
            if(wt[shortest]<0)
                wt[shortest]=0;
        }
        t++;
    }
}
void findturnaroundtime(struct process proc[], int n, int wt[], int tat[])
{
    for(int i=0;i<n;i++)
        tat[i]=proc[i].bt + wt[i];
}
void findavgtime(struct process proc[], int n)
{
    int wt[n], tat[n], total_wt=0, total_tat=0;
    findwaitingtime(proc, n, wt);
    findturnaroundtime(proc, n, wt, tat);
    printf("Process No.\tBurst time\tWaiting time\tTurn Around Time\n");
    for(int i=0;i<n;i++)
    {
        total_wt+=wt[i];
        total_tat+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("Average Waiting time: %.3f\n", (float)total_wt/n);
    printf("Average Turn Around Time: %.3f\n", (float)total_tat/n);
}
int main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process proc[n];
    for(i=0;i<n;i++)
    {
        printf("Enter burst time and arrival time for process %d: ",i+1);
        proc[i].pid=i+1;
        scanf("%d %d",&proc[i].bt, &proc[i].at);
    }
    findavgtime(proc, n);
    return 0;
}
