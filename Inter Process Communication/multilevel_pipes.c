#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>


int main(){
    int fd1[2];
    char buffer1[100];
    int ret=fork();
    if(ret==0){
        // Child process 0
        printf("Child ID:%d received data from Parent ID:%d\n",getpid(),getppid());
        int ni=read(fd1[0],buffer1,100);
        write(1,buffer1,ni);
        printf("Child ID:%d Completed \n",getpid());
        sleep(1);
        int fd2[2];
        char buffer2[100];
        int ret1 = fork();
        if(ret1==0){
            // Child process 1
            int ni2=read(fd2[0],buffer2,100);
            write(1,buffer2,ni);
            sleep(1);
            int fd3[2];
            char buffer3[100];
            int ret2 = fork();
            if(ret2==0){
                // Child process 2
                int ni3=read(fd3[0],buffer3,100);
                write(1,buffer3,ni3);
            }else{
                write(fd3[1],"Hello\n",6);
                printf("parent process ID:%d Completed\n",getppid());
                wait(NULL);
            }
        }else{
            write(fd2[1],"Hello\n",6);
            printf("parent process ID:%d Completed\n",getppid());
            wait(NULL);
        }
    }else{
        // Parent process
        write(fd1[1],"Hello\n",6);
        printf("parent process ID:%d Completed\n",getppid());
        wait(NULL);
    }
    return 0;
}