#include<stdio.h>
struct
{
    int r;
    int w;
    int r_count;
    int mutex;

}monitor;
void wai()
{
    monitor.mutex--;
}
void sign()
{
    monitor.mutex++;
}
void rea()
{
    wai();
    if(monitor.r_count==1)
    printf("1 Process is Reading\n");
    else
        printf("%d Processes are Reading\n",monitor.r_count);
    sign();

}
void writ()
{
    wai();
    printf("A Process is Writing\n");
    sign();
    monitor.w=0;
}
int main()
{
    int choice;
    monitor.r=monitor.w=monitor.r_count=0;
    monitor.mutex=1;
    do
    {
        printf("\n1.Read\n2.Write\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: if(monitor.mutex==1 && monitor.w!=1)
                    {
                        monitor.r_count++;
                        monitor.r=1;
                        rea();
                    }
                else
                    printf("Busy\n");
                break;
            case 2:
                monitor.r_count=0;
                monitor.r=0;
                if(monitor.mutex==1 && monitor.r!=1)
            {   monitor.w=1;
                writ();
            }
                else
                    printf("Busy\n");
                break;
            default: printf("Exit\n");
                break;
        }
    }while(choice==1 || choice==2);
}
