#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include<string.h>
 #include <unistd.h>
// #include<conio.h>

int main(){
    mode_t mode = 0666;
    int cret=mkfifo("my_pipe",mode);
    int fd = open("my_pipe",O_RDWR);
    char y[20];
    while(1){
        read(fd,y,sizeof(y));
    printf("Output of Server: %s\n",y);
    char str[20];
    scanf("%[^\n]%*c", str);
    write(fd,&str,sizeof(str));
    if(strcmp(str,"Bye")==0)
    break;
    }
    close(fd);
    system("rm my_pipe");
    return 0;
}