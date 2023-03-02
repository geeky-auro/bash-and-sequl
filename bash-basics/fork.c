#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
int ret=0;
ret=fork();
printf("Parent Process=%d \n",getppid());
for(int i=0;i<4;i++){
	ret=fork();
	if(ret>0){
	//printf("Parent Process ID=%d \n",getppid());
	break;
	}
	
	printf("Child Process=%d Parent Process=%d \n",getpid(),getppid());
}
return 0;
}
