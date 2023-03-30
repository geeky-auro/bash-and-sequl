#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

int main(){
    // int fd1[2];
    int fd2[2];
    char buffer1[100];
    int ret=fork();
    if(ret==0){
        printf("Child ID:%d received data from Parent ID:%d\n",getpid(),getppid());
        int ni=read(fd2[0],buffer1,100);
        write(1,buffer1,ni);
        printf("Child ID:%d Completed \n",getpid());
    }else{
        printf("parent process Started ;)\n");
        write(fd2[1],"hello\n",6);
        int fd3[2]; 
        char buffer[100];
        wait(NULL);
        int ret1=fork();
        if(ret1==0){
            printf("Child ID:%d received data from Parent ID:%d\n",getpid(),getppid());
            int n=read(fd3[0],buffer,100);
            write(1,buffer,n);
            printf("Child ID:%d Completed \n",getpid());
        }else{
            write(fd3[1],"hi \n",4);
            printf("parent process Completed\n");
            wait(NULL);
        }
        
    }
    return 0;
}