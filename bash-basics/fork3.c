// Write a C program, Where the Parent process has N wait till the completion of all child processes so that no child process will become orphan 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int ret=0;
    int wpid;
    int status=0;
    printf("Parent Process Started \n");
    printf("Enter No. of Child Processes \n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ret=fork();
        if(ret==0){
            // sleep(1);
            // wait(NULL);
            // Execution of Child Process ;)
            printf("Child Process %d \n",i);
            exit(0);
        }
         
    }
    // In This way, the Parent waits for all the child processes to complete it's Execution ;)
    while ((wpid = wait(&status)) > 0);
   printf("Parent Process Ended \n");
    // wait(NULL);
    return 0;
}