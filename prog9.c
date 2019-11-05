#include<stdio.h>
#include <unistd.h>
#include <pthread.h> 


#define size 5

struct share{
    int buffer;
    int lock;

}shared;

int lock(int pid ){
    
    if( pid == shared.lock ){
        return 1;
    }
    else if( shared.lock == 0){
        shared.lock = pid;
        return 1;
    }
    else {
        return 0;
    }
    
}
int unlock(int pid ){
    
    if( pid == shared.lock ){
        shared.lock = 0;
        return 1;
    }
  
    else {
        return 0;
    }
    
}


void *print(void *vargp){
    printf("\nTESTING");
}

void *consumer(void *vargp){

    int *i = (int *)vargp;
    *i = *i%1000;   
    printf("\n\t\t\t\tLOCK : %d PID : %d BUFFER : %d ",shared.lock, *i, shared.buffer);
     while(1){
        //printf("\n\t\t\t\tLOCK : %d PID : %d BUFFER : %d ",shared.lock, *i, shared.buffer);
 
        if(lock(*i) == 1){
            printf("\n\t\t\t\tLocked for consumer");
            if(shared.buffer==0){
                printf("\n\t\t\t\tbuffer is empty");
            }
            else{
                printf("\n\t\t\t\tconsuming buffer");
                shared.buffer--;
                sleep(5);
                printf("\n\t\t\t\tconsumed buffer : %d",shared.buffer);
            
            }
            unlock(*i);
            printf("\n\t\t\t\tUnlocking buffer");
            sleep(3);
           
        }
        else{
            printf("\n\t\t\t\tunable to lock for consumer");
            sleep(3);
        }
    

}
}

void *producer(void *vargp){
     int *i = (int *)vargp;
     *i = *i%1000;
   printf("\nLOCK : %d, PID : %d, BUFFER : %d ",shared.lock, *i, shared.buffer);
   while(1){
    
       
        if(lock(*i) == 1){
            printf("\nLocked for producer");
            if(shared.buffer==size){
                printf("\nbuffer is full");
            }
            else{
                printf("\nproducing buffer");
                shared.buffer++;
                sleep(5);
                printf("\nproduced buffer: %d",shared.buffer);
            
            }
            printf("\nUnlocking buffer");
            unlock(*i);
            sleep(3);
        
           
       }
        else{
            printf("\nunable to lock for producer");
            sleep(3);
        }
    
   }
}





int main(){
    shared.buffer = 0;
    shared.lock = 0;
    pthread_t tid, tid2; 
    
    
    pthread_create(&tid, NULL, producer, (void *)&tid);
    pthread_create(&tid2, NULL, consumer, (void *)&tid2); 
  
    pthread_exit(NULL);
}






