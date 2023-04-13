#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

int main()
{
    int fd[2];
    int ret=fork();
    if(ret==0){
        // Child process
        dup2(fd[1],1);
        close(fd[0]);
        close(fd[1]);
        system("ls");
        return 1;
    }
        int ret1=fork();
        if(ret1==0){
            dup2(fd[0],0);
            close(fd[0]);
            close(fd[1]);
            system("sort");
            return 1;
        }
        
        close(fd[0]);
        close(fd[1]);

    return 0;
}