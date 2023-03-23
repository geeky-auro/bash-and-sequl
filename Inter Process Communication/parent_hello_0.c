#include<unistd.h>
#include<stdio.h>

int main(){
    int pipe_fd[2];

    if(pipe(pipe_fd)==-1){
        perror("Pipe");
        return(0);
    }
    // Create a Child Process
    char buffer[20];
    int ret=fork();
    if(ret==0){
    printf("Reading Message from Parent \n");
        read(pipe_fd[0],buffer,sizeof(buffer));
        printf("Message from Parent is %s\n",buffer);
    }else{
        // close(pipe_fd1[1]);
        printf("Writing Message to Child \n");
        write(pipe_fd[1],"Hello",5);
    }
    return 0;
}