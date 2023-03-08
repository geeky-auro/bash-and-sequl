// Create two child process C1 and C2. Make sure that only C1 becomes an orphan process.
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int ret=0;
    int wpid;
    int status=0;
    // int n;
    // scanf("%d",&n);
    // for(int i=0;i<n;i++){
    //     ret=fork();
    //     if(ret==0){
    //         printf("Execution of Child Process %d \n",i);
    //         if(i==0)
    //         wait(NULL);
    //         // sleep(NULL);
    //         // exit(0);
    //         else
    //         exit(0);
    //     }
    //     // if(i!=0){
    //     //     wait(NULL);
    //     //     // Execution of Parent Process
    //     //     printf("Terminating Parent Process ;)"); 
    //     // }
    // }

    ret=fork();
    if(ret==0){

        // wait(NULL);
        sleep(5);
        // wait(NULL);
        printf("I am child having PID %d\n",getpid());
        printf("My parent PID is %d\n",getppid());
        exit(0);
    }else{
        // wait(NULL);
        ret=fork();
        if(ret==0){
        printf("I am child 2 having PID %d\n",getpid());
        printf("My parent PID is %d\n",getppid());    
        exit(0);
        }
        wait(NULL);
        printf("I am parent having PID %d\n",getpid());
         printf("My child PID is %d\n",ret);
    }


    // while ((wpid = wait(&status)) > 0);
    // printf("Parent Process Termination \n");

    // if(ret==0){
    //     // sleep(5);
    //     printf("Execute Child Process \n");
    //     printf("Execute another Child Process \n");
    //     printf("Execute 3rd Child Process ;) \n");
    // }else{
    //     wait(NULL);
    //     printf("Execute Parent Process \n");
    //     printf("Execute another Parent Process \n");
    //     printf("Execute 3rd Parent Process ;) \n");
    // }

    return 0;
}