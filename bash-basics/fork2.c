#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void createChildTree(int child){
    // Enter No. of Child to be produced
    int ret=0;
    if(child==0){
        return;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ret=fork();
        if(ret==0){
        int x;
        printf("Enter No. of Child");
        createChildTree(n);
        }
        
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
    
     for(int i=0;i<1;i++){
        ret=fork();
        // print no. of child
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            ret=fork();
            if(ret==0){
            printf("Index:%d Parent Process ID:%d , Child Process ID:%d \n",j , getppid(),getpid());
            break;
            }
        }
    }



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
