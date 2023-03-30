// Parent Process will be the sender and child process will be the receiver..!
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    int fd[2],n;
    char buffer[100];
    int p;
    pipe(fd);
    // Reading end will be referred as fd[0]
    // Writing end will be referred as fd[1]
    p=fork();
    if(p>0){
        // Parent Process
        printf("Passing Values to child process \n");
        write(fd[1],"hello\n",6);
    }else{
        // Child Process
        printf("Child received data\n");
        n=read(fd[0],buffer,100);
        // The below system call is used to display on screen how much is received ;)
        write(1,buffer,n);
    }
    return 0;
}