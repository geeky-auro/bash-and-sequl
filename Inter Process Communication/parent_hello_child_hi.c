#include<unistd.h>
#include<stdio.h>
int main(){
    int pipe_fd[2];
    int pipe_fd1[2];
    if(pipe(pipe_fd)==-1){
        perror("Pipe");
        return(0);
    }
    if(pipe(pipe_fd1)==-1){
        perror("Pipe");
        return(0);
    }
    // Create a Child Process
    char readmessage[20];
    int ret=fork();
    if(ret==0){
        // Child Process
        printf("Reading Message from Parent \n");
        read(pipe_fd[0],readmessage,sizeof(readmessage));
        printf("Message from Parent is %s\n",readmessage);
    }else{
        printf("Writing Message to Child \n");
        write(pipe_fd[1],"Hello",5);
    }
    
    return 0;
}