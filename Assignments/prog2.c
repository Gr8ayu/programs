#include<stdio.h>

int get_int(char s[]){
    
    int x;
    printf("%s",s );
    scanf("%d",&x);
    return x;
}

int sum_array(int A[],int n){
    int sum = 0,i;
    for (i = 0; i <= n; i += 1)
    {
        sum+=A[i];
    }
    


}


void print_arr(int A[],int n){
for (int i = 0; i < n; i += 1)
{
    printf("--%d--",A[i]);
}
}


void wt_calc(int A[],int B[],int n){
    int i;
    float sum=0;
    B[0] = 0;

    for(int i=0;i<n;i++){
        B[i+1] = B[i] + A[i];
    }
    
    for(int i=0;i<=n;i++){
        sum += B[i];
    }
    
 
}

void FCFS(int A[],int n){
        //wt_calc(A,n);
}


int main(){
    
    int n ,i;
    n = get_int("No of processes : ");
    int system_process[n], user_process[n],no_of_sys_process=0,no_of_user_process=0;
    int B1[n+1],B2[n+1];
    for (i = 0; i < n; i += 1)
    {
        int a,b;
        a = get_int("Enter Burst time for process :");
        b = get_int("System/User process (0/1) :");
        
        if(b==0){
        system_process[no_of_sys_process++]=a;

        }
        if(b==1){user_process[no_of_user_process++]=a;}
        
        
    }
    printf("PROCESS\tTYPE\tBURST\tWAITING\tTURNAROUND\n");
    wt_calc(system_process,B1,no_of_sys_process);
    
    for (i = 0; i < no_of_sys_process; i += 1)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",i+1,0,system_process[i],B1[i],B1[i+1] );
    }
    
   
    wt_calc(user_process,B2,no_of_user_process);
    
    for (i = 0; i < no_of_user_process; i += 1)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",no_of_sys_process+i+1,1,user_process[i],B1[no_of_sys_process] + B2[i],B2[i+1] + B1[no_of_sys_process] );
    }

    
}

