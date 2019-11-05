#include <stdio.h>



int main(){
        int i,j;
        int alloc[4][3] = {
        1,0,1,
        1,1,2,
        1,0,3,
        2,0,0                   
        };
        int n = 4;
        
        int max_req[4][3] = {
        4,3,1,
        2,1,4,
        1,3,3,
        5,4,1
        };
        
        
        int ins[] = {8,4,6};
        int avail[] = {8,4,6};
        
        int need[4][3];
        
        int total_alloc[] = {0,0,0};
        

        
        
        for (i = 0; i < 4; i += 1)
        {
                for (j = 0; j < 3; j += 1)
                {
                     need[i][j] = max_req[i][j] - alloc[i][j];  

                     total_alloc[j] += alloc[i][j]; 
                     avail[j] -= alloc[i][j]; 
                }

        }
        
        
        while(n){
        	int lookup = 0;
        	for (int i = 0; i < 4; ++i)
        	{
        		int pass = 1;
        		for (int j = 0; j < 3; ++j)
        		{
        			if(need[i][j] > avail[j] ){
        				pass = 0;
        			}
        		}

        		if(need[i][0] == -1) {continue;}
        		if (pass)
        		{	
        			lookup = 1;
        			printf("\nP%d",i+1);
        			n--;
        			
        			for (int k = 0; k < 3; ++k)
        			{
        				avail[k] += alloc[i][k];
        			}


        			need[i][0] = -1;

        			break;
        		}




        	}

        	if (!lookup)
        	{
        		printf("\n%s","DEADLOCK" );
        		break;
        	}


        }

printf("\n");



}
