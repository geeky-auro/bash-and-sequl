// Write a C program, that will create any given process tree with the following information for each process i.e level number, index Number and No. of childs, for ex: p1:2(child),level 0 {p2,p3}
//              p2:0(child),level 1 {}
//              p3:2(child),level 1 {p4,p5}
//              p4:0(child),level 2 {}
//              p5:1(child),level 2 {p6}
//              p6:0(child),level 3 {}
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void createChildTree(int child,int level,int index){
    // Enter No. of Child to be produced
    int ret=0;
    if(child==0){
        return;
    }

    for(int i=0;i<child;i++){
        ret=fork();
        if(ret==0){
            printf("Enter No. of Child \n");
            printf("level:%d ,Index:%d Parent Process ID:%d , Child Process ID:%d \n",level,index , getppid(),getpid());
            int n;
            scanf("%d",&n);
        // int x;
        // printf("Enter No. of Child");
        createChildTree(n,level+1,i);
        break;
        }
        wait(NULL);
        
    }
    // printf("No of Child to be produced \n");
    // for(int i=0;i<1;i++){
    //     ret=fork();
    //     // print no. of child
    //     int n;
    //     scanf("%d",&n);
    //     for(int j=0;j<n;j++){
    //         ret=fork();
    //         if(ret==0){
    //         printf("Index:%d Parent Process ID:%d , Child Process ID:%d \n",j , getppid(),getpid());
    //         break;
    //         }
    //     }
    // }
}

int main(){
    int ret=0;
    // if(ret==0){
    //     printf("Wallah Its is Child`` Process \n");
    // }
    // if(ret>0){
    //     printf("Wallah Its is Parent Process \n");
    // }
    // ret=fork();
    
    //  for(int i=0;i<1;i++){
    //     ret=fork();
    //     // print no. of child
    //     int n;
    //     scanf("%d",&n);
    //     for(int j=0;j<n;j++){
    //         ret=fork();
    //         if(ret==0){
    //         printf("Index:%d Parent Process ID:%d , Child Process ID:%d \n",j , getppid(),getpid());
    //         break;
    //         }
    //     }
    // }



    createChildTree(1,0,0);


    // if(ret>0){
    //     int ret1=fork();
    //     if(ret1>0){
    //         wait(NULL);
    //         int ret2=fork();
    //         if(ret2>0){
    //             wait(NULL);
    //             printf("Parent Process:\n");
    //             printf("PID:%d \n",getpid());
    //             printf("PPID:%d \n",getppid());
    //             printf("\n");
    //         }else if(ret2==0){
    //             printf("Child Process 1 ID:\n");
    //             printf("PID:%d \n",getpid());
    //             printf("PPID:%d \n",getppid());
    //             printf("\n");
    //         }
    //     }else if(ret1==0){
    //             printf("Child Process 2 ID:\n");
    //             printf("PID:%d \n",getpid());
    //             printf("PPID:%d \n",getppid());
    //             printf("\n");
    //     }
    // }else if(ret==0){
    //             printf("Child Process 3 ID:\n");
    //             printf("PID:%d \n",getpid());
    //             printf("PPID:%d \n",getppid());
    //             printf("\n");
    // }
return 0;
}
