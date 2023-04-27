#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


int sharedVariable=0;
pthread_mutex_t s;
void * increment(){
    // pthread_mutex_lock(&s);
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&s);
        sharedVariable++;
        printf("%d \n",sharedVariable);
         pthread_mutex_unlock(&s);
        
    }
    
}


int main(){

    pthread_t thread[2];
     pthread_mutex_init(&s,NULL);
    for(int i = 0; i < 2; i++) {
        // Create a new thread
    pthread_create(&thread[i], NULL,increment,NULL);
    }
    for(int i = 0; i < 2; i++) {
        // Process Wait for the completion of thread ;) 

    pthread_join(thread[i], NULL); 

    }
     pthread_mutex_destroy(&s);
     printf("%d \n",sharedVariable);
    return 0;
}


