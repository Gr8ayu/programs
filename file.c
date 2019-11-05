#include<stdio.h>
void print_arr(int A[],int n){
for (int i = 0; i < n; i += 1)
{
    printf("--%d--",A[i]);
}
}

void wt_calc(int A[],int n){
    int B[100];
    float sum=0;
    B[0] = 0;

    for(int i=0;i<n;i++){
        B[i+1] = B[i] + A[i];
    }
    
    for(int i=0;i<=n;i++){
        sum += B[i];
    }
    printf("\n\nAvg. waiting time : %.2f",(sum - B[n])/n);
    printf("\nAvg. Turn Around time : %.2f\n",sum/n);
    
    
}

void FCFS(int A[],int n){
        wt_calc(A,n);
}

void SJF(int A[],int n){

    for (int i = 0; i < n; i += 1)
    {
        for (int j = i; j < n; j += 1)
        {
            if (A[i]>A[j])
            {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            }
        }
    }    

        wt_calc(A,n);
}

void RR(int A[], int n ){
    int tq, B[n], n2=0,i;
    printf("Time quantum : ");
    scanf("%d",&tq);
    
    for (i = 0; i < n; i += 1)
    {
        if(A[i]>0){
            n2++;
        }
        
        B[i]=0;
    }
    
    while (n2 >0)
    {
        for ( i = 0; i < n; i += 1)
        {   
        
            int run_time;
            if(A[i]<= tq){ run_time = A[i]; }
            else { run_time = tq; }
            
            
            if(A[i]<=0){continue;}
            
            for (int j = 0; j < n; j += 1)
            {
                if(j==i){ 
                    B[j] += 0;
                   
                    A[j] -= run_time;
                    if(A[j]<=0){n2--;}
                    
                  }
                else{
                      
                    //B[j] += tq;
                    
                    //if(A[j] <= tq){B[j] -= tq ;}
                    //else {A[j] -= tq;  }
                    B[j] += run_time;
                     }
                
                
                
            }
            
            
            
            
        }
        print_arr(B,n);
        printf("\n");
    }
    
    
    
}

void PRIORITY(int A[],int n){
    int priority[n];
    for (int i = 0;  i < n; i += 1)
    {
        printf("Enter priority for process %d : ",i+1);
        scanf("%d",&priority[i]);
    }

    for (int i = 0; i < n; i += 1)
    {
        for (int j = i; j < n; j += 1)
        {
            if (priority[i]>priority[j])
            {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            
            temp = priority[i];
            priority[i] = priority[j];
            priority[j] = temp;
            
            }
        }
        
       
    }  
    
    wt_calc(A,n);

}



int main(){
int n,A[100];
    printf("Enter the no of process : ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
    printf("Enter value for process %d :",i+1 );
        scanf("%d",&A[i]);
        }
    int sel;
    printf("\n Select operation :");
    printf("\n 1: FCFS \t2: SJF \t3:RR \t4:PRIORITY\nEnter : ");
    scanf("%d",&sel);
    
    switch(sel){
        case 1: FCFS(A,n);
            break;
        case 2: SJF(A,n);
            break;
        case 3: RR(A,n);
            break;
        case 4: PRIORITY(A,n);
            break;
                
        default: break;
        
    
    }
    
}

























