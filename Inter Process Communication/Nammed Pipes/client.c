#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include<string.h>
 #include <unistd.h>
int main(){
    
    int fd = open("my_pipe",O_RDWR);
    if(fd == -1){
        perror("open");
        exit(1);
    }
    char sendBuffer[20]="Hello";
    // int x=200;
    write(fd,sendBuffer,strlen(sendBuffer));
    char y[20]; 
    sleep(2);
    read(fd,y,sizeof(y));
    printf("Output of Clientt: %s\n",y);
    return 0;
}