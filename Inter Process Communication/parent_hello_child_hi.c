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
    char buffer[20];
    char readmessage1[20];
    int ret=fork();
    if(ret==0){
        // Child Process
        close(pipe_fd[1]);
        close(pipe_fd1[0]);
        printf("Reading Message from Parent \n");
        read(pipe_fd[0],buffer,sizeof(buffer));
        printf("Message from Parent is %s\n",buffer);
        printf("Writing Message to Parent");
        write(pipe_fd1[1],"Hi",2);

    }else{
        close(pipe_fd[0]);
        close(pipe_fd1[1]);
        printf("Writing Message to Child \n");
        write(pipe_fd[1],"Hello",5);
        printf("Reading Message from Child \n");
        read(pipe_fd1[0],readmessage1,sizeof(readmessage1));
        printf("Message from Child is %s \n",readmessage1);

    }
    
    return 0;
}