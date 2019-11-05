#include<stdio.h>
#define TB 100
void allocate();
void deallocate();
void display();
int BFull();
struct Sequence
{
    char n[30];
    int len;
    int st;
}F[30];
int Table[TB],pos=0,r,i,j,ch,B=0;
char fn[30];
main()
{
     printf("\n Contiguous File Allocation \n\n");
     do{
     printf("\n\n1.Allocate\n2.Deallocate\n3.Display\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
                case 1:
                    pos++;
                    allocate();
                    break;

                case 2:
                    deallocate();
                    break;

                case 3:
                    display();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);

}
void allocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(F[pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(F[pos].len));
   if(BFull())
   {
        pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
   while(1)
   {
        i=0;
        r=(rand()%TB+1);
        if(r+F[pos].len-1>TB)
           continue;
        if(Table[r]==0)
        {
                for(i=r+1;i<r+F[pos].len;i++)
                    if(Table[i]==1)
                        break;
        }
        if(i==r+F[pos].len)
            break;


    }
    F[pos].st=r;
    for(i=r;i<r+F[pos].len;i++)
        Table[i]=1;
    printf("\n\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t%d",F[i].n,F[i].st,F[i].len);
        printf("\n");
    }

}
void deallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&fn);
   for(i=1;i<=pos;i++)
   {
            if(strcmp(F[i].n,fn)==0)
            {
                    for(j=F[i].st ;j<(F[i].len+F[i].st);j++)
                        Table[j]=0;
                    strcpy(F[i].n,"--");
                    F[i].st=0;
                    F[i].len=0;
                    printf("\nFile (%s) Deleted Successfully \n",fn);
                    break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\t\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t%d",F[i].n,F[i].st,F[i].len);
        printf("\n");
    }
}
void display()
{
    printf("\nEnter The File Name : ");
    scanf("%s",fn);
    printf("\nBlocks Allocated Are : ");
    for(i=1;i<=pos;i++)
    {
        if(strcmp(F[i].n,fn)==0)
        {
            for(j=F[i].st;j<(F[i].st+F[i].len);j++)
                printf("--%d--",j);
            break;
        }
    }
}
int BFull()
{
    for(i=1,B=0;i<=pos;i++)
        B=B+F[i].len;
    if(B>TB)
        return 1;
    else
        return 0;
}
