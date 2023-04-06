#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include <fcntl.h>
 #include <unistd.h>
// #include<conio.h>

int main(){
    mode_t mode = 0666;
    int cret=mkfifo("my_pipe",mode);
    int fd = open("my_pipe",O_RDWR);
    char y[20];
    read(fd,y,sizeof(y));
    printf("Output of Server: %s\n",y);
    int x=15;
    write(fd,&x,sizeof(x));
    close(fd);
    system("rm my_pipe");
    return 0;
}