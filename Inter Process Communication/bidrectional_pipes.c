#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main(){
    // Demonstration of two way communication in C using Pipes ;)
    // Parent (5) => child()=5;
    // child (5*4) => Parent()=20;

    // Reading end will be referred as fd[0]
    // Writing end will be referred as fd[1]
    int p1[2]; // C=>P {Here the child only writes so we dont need to read anything} 
    int p2[2]; // P=>C {Here the child only reads so we dont need to write anything from child's end}
    if(pipe(p1)==-1){
        return 1;
    }
    if(pipe(p2)==-1){
        return 1;
    }
    int pid=fork();
    if(pid==-1){return 2;}
    if(pid==0){
        // child Process ;)
        close(p1[0]); // No work of Childs Reading End ;0
        close(p2[1]); // No work of Parents Writing End ;0
        int x;
        // We need to read using p2 
        read(p2[0],&x,sizeof(x));
        printf("Received %d\n",x);
        x*=4;
        write(p1[1],&x,sizeof(x));
        printf("wrote %d\n",x);
        close(p1[1]);
        close(p2[0]);
    }else{
        // Parent Process
        close(p1[1]); // No work of Parents Reading End
        close(p2[0]); // No work of Childs Writing End
        srand(time(NULL));
        // Generate random No. and Multiply it with in child process
        int y=rand()%10;
        write(p2[1],&y,sizeof(y));
        /*
        If print Statement is commented then there will be maximum number of chances that
        WHATEVER is wrote on the above line will be immediately read in the below line 
        SO we use two different pipes for bidirectional communication ;) 
        */
        // printf("wrote %d\n",y);
        read(p1[0],&y,sizeof(y));
        printf("Result:%d\n",y);
        close(p1[0]);
        close(p2[1]);
        // wait(NULL);
    }


    return 0;
}