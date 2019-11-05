#include<stdio.h>

int find_best(int p, int bs[], int n1){
        int min = 1000000;
        int index  = -1;
        int i,j;
        for (i = 0; i < n1; i += 1)
        {
                if(bs[i] > p && bs[i] < min ){
                        index = i;
                        min = bs[i];
                }
        }
        
        return index;

}

int find_worst(int p, int bs[], int n1){
        int max = 0;
        int i,j;
        int index  = -1;
        for (i = 0; i < n1; i += 1)
        {
                if(bs[i] > p && bs[i] > max ){
                        index = i;
                        max = bs[i];
                }
        }
        
        return index;

}


void first_fit(int bs[], int ps[], int n1, int n2){
         int i,j;
         for (i = 0; i < n2; i += 1)
        {
                for (j = 0; j < n1; j += 1)
                {
                        if(bs[j] >= ps[i] ){
                                bs[j] -= ps[i];
                                printf("%d    %d     %d\n",i+1,ps[i] , j+1 );
                                break;
                        }
                }
                
                if(j==n1){
                        printf("%d    %d     Not Allocated\n",i+1,ps[i]  );
                }
        }
        
}

void best_fit(int bs[], int ps[], int n1, int n2){
        int i;
         for (i = 0; i < n2; i += 1)
        {
                int x  = find_best(ps[i], bs, n1);
                if(x == -1){
                        printf("%d    %d     Not Allocated\n",i+1,ps[i]  );
                }
                
                else{   
                        bs[x] -= ps[i];
                        printf("%d    %d     %d\n",i+1,ps[i] , x+1 );
                }
                
                
                
        }
        
}


void worst_fit(int bs[], int ps[], int n1, int n2){
        int i;
         for (i = 0; i < n2; i += 1)
        {
                int x  = find_worst(ps[i], bs, n1);
                if(x == -1){
                        printf("%d    %d     Not Allocated\n",i+1,ps[i]  );
                }
                
                else{   
                        bs[x] -= ps[i];
                        printf("%d    %d     %d\n",i+1,ps[i] , x+1 );
                }
                
                
                
        }
        
}



int main(){
        int n1=5,n2=4,i,j;
        int bs[] = {100,500,200,300,600};
        int ps[] = {212,417,112,426};
        
        worst_fit(bs, ps, n1, n2);


}









