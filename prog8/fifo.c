#include <stdio.h>
#define size 4
#define length 14
void insertq(int[], int);
int deleteq(int[]);
void display(int[]);
int find(int [], int );
void fifo(int [],int []);
int full(int []);
void LRU(int [],int []);
void movetoend(int [],int);

int front =  - 1;
int rear =  - 1;


int main()
{
    int n, ch;
    //int queue[size]= {-1,-1,-1};
    int queue[size]= {-1,-1,-1,-1};
    int A[length] = {7,0,1,2,0,3,0,4,2,3,0,3,2,3};
    //int A[] = {1,3,0,3,5,6,3};
    //fifo(A,queue);
    LRU(A,queue);
    
}


void fifo(int A[],int queue[]){
    int i;
    for (i = 0; i < length; i += 1)
    {   
        if(find(queue,A[i]) != -1 ){display(queue); printf(" hit"); continue;}
    
           
        if (full(queue)){
                deleteq(queue);
            }
            insertq(queue,A[i]);
        display(queue);  
        printf(" miss"); 
        continue;
    
   
    }
}

void LRU(int A[],int queue[]){
    int i;
    for (i = 0; i < length; i += 1)
    {   
        if(find(queue,A[i]) != -1 ){display(queue);printf(" hit %d",A[i]); 
        movetoend(queue,A[i]);
        continue;}
        
        if(full(queue)){
            deleteq(queue);
        }
        
        
        insertq(queue,A[i]);
        display(queue);   
        
        printf(" miss %d",A[0]);
   
    }
}



int find(int queue[], int n)
{
   int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < size; i++)
        {
            if(queue[i] == n){return i;}
        }
        for (i = 0; i <= rear; i++)
            if(queue[i] == n){return i;}
    }
    else
    {
        for (i = front; i <= rear; i++)
            if(queue[i] == n){return i;}
    }
    
    return -1;
}

void movetoend(int queue[], int n){

    int first = queue[front];
    int x=-1;
    while(x!=first){
        x = deleteq(queue);
        if(x == n){continue;}
        insertq(queue,x);
    }
    
    insertq(queue,n);
      





}

void insertq(int queue[], int item)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("queue is full");
        return;
    }
    else if (rear ==  - 1)
    {
        rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
}
/*
void display(int queue[])
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < size; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}
*/

void display(int q[]){
    int i = 0;
    for (i = 0; i < size; i += 1)
    {
        if(q[i] == -1){continue;}
        printf("%d ",q[i]);
    }

}

int deleteq(int queue[])
{   int del = -1;
    if (front ==  - 1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)
    {
        //printf("\n %d deleted", queue[front]);
        del = queue[front];
        front =  - 1;
        rear =  - 1;
    }
    else
    {
       // printf("\n %d deleted", queue[front]);
       del = queue[front];
        front++;
    }
    
    return del;
}

int full(int queue[] ){

if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        //printf("queue is full");
        return 1;
    }
    return 0;


}


int empty(int queue[] ){

if (front ==  - 1)
    {
        //printf("queue is full");
        return 1;
    }
    return 0;


}
