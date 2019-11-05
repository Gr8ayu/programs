#include <stdio.h>

int main()
{
    int n, ch;
    //int queue[size]= {-1,-1,-1};
    int queue[size]= {-1,-1,-1,-1};
    int order[size]= {-1,-1,-1,-1};
    
    int A[length] = {7,0,1,2,0,3,0,4,2,3,0,3,2,3};
    
    
    LRU(A,queue);
    
}



void LRU(int A[],int queue[]){
    int i;
    int index = 0;
    for (i = 0; i < length; i += 1)
    {   
       if(find(queue, -1 ) != -1 ){
            queue[index++] = A[i] ;
            
            
            
       }
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




