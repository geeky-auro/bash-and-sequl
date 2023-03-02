#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
 int i;
for(i = 0; i< 3; i++)
{
 int ret = fork();

 if(ret == 0)
 {
      printf("Child %d Parent %d\n", getpid(), getppid());
    if(i==1){
        //sleep(2);
        ret=fork();
        printf("Child %d Parent %d\n", getpid(), getppid());
        if(ret>0)
        exit(0);
        else if(ret==0){
            for(int j = 0; j< 2; j++)
            {
                int ret = fork();
                printf("Child %d Parent %d\n", getpid(), getppid());
                if(ret == 0)
                break;
            }
        }
                
    }
    /*if(i==1){
        sleep(2);
        ret=fork();
        printf("Child %d Parent %d\n", getpid(), getppid());
    }*/
 //else{
 //printf("Parent %d\n", getpid());
break;}
}

return 0;
}