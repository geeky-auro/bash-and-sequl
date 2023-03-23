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
    printf("Child Process :%d Parent Process:%d \n",getpid(),getppid());
    exit(0);
 }
}

return 0;
}
