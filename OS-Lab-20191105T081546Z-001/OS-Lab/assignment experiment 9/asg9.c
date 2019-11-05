#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
    int mutex, full, empty, count;
    char message[100];
}pro_con;
int wait(int x)
{
    return (--x);
}
int signal(int x)
{
    return (++x);
}
void producer()
{
    printf("%s\n",pro_con.message);
    if(pro_con.mutex==1 && pro_con.message[0]-48 !=0)
    {
        pro_con.mutex=wait(pro_con.mutex);
        pro_con.empty=wait(pro_con.empty);
        pro_con.full=signal(pro_con.full);
        pro_con.count=signal(pro_con.count);
        printf("Producer produces item %d\n",pro_con.count);
        pro_con.mutex=signal(pro_con.mutex);
    }
    else
        printf("Buffer is full\n");
    pro_con.message[1]='\0';
}
void consumer()
{
    printf("%s\n",pro_con.message);
    if(pro_con.mutex==1 && pro_con.message[0]-48 !=0)
    {
        pro_con.mutex=wait(pro_con.mutex);
        pro_con.empty=signal(pro_con.empty);
        pro_con.full=wait(pro_con.full);
        printf("Consumer consumes item %d\n",pro_con.count);
        pro_con.count=wait(pro_con.count);
        pro_con.mutex=signal(pro_con.mutex);
    }
    else
        printf("Buffer is empty\n");
    pro_con.message[1]='\0';
}
int main()
{
    pro_con.mutex=1;
    pro_con.full=pro_con.count=0;
    printf("Enter the buffer size: ");
    scanf("%d",&pro_con.empty);
    int choice;
    do
    {
        printf("1.Produce\t2.Consume\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: pro_con.message[0]= pro_con.empty+48;
                    strcat(pro_con.message, "Slot is free in buffer");
                    producer();
                    break;
            case 2: pro_con.message[0]=pro_con.full+48;
                    strcat(pro_con.message,"Slot is occupied in buffer");
                    consumer();
                    break;
            default: printf("Exit\n");
        }
    }while(choice==1 || choice==2);
    return 0;
}
