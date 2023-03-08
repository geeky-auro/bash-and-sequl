// Write a program in C which Creates a scenario where a parent has two child process C1 and C2 such that C1 becomes a zombie while C2 becomes an orphan process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
In this program, the parent process creates the first child process C1 using the fork() function. The child process immediately exits using exit(0) to become a zombie process.

After waiting for a few seconds using sleep(3), the parent process creates the second child process C2 using the fork() function again. The child process also exits immediately using exit(0) to become an orphan process.

The parent process waits for the second child process C2 to exit using the wait() function, and then it also exits using exit(0). At this point, the parent process becomes an orphan process.*/

int main() {
    int pid1, pid2;

    // create the first child process
    pid1 = fork();
    if (pid1 < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (pid1 == 0) {
        // this is the child process C1
        printf("Child C1 process with pid %d created.\n", getpid());
        // exit immediately to become a zombie process
        exit(0);
    } else {
        // this is the parent process
        // wait a few seconds to allow C1 to become a zombie
        sleep(3);
        // create the second child process
        pid2 = fork();
        if (pid2 < 0) {
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        } else if (pid2 == 0) {
            // this is the child process C2
            printf("Child C2 process with pid %d created.\n", getpid());
            // exit immediately to become an orphan process
            exit(0);
        } else {
            // this is the parent process
            printf("Parent process with pid %d created child processes C1 (%d) and C2 (%d).\n", getpid(), pid1, pid2);
            // wait for C2 to exit so it becomes an orphan process
            wait(NULL);
            printf("Child process C2 has exited. Parent process with pid %d is now an orphan process.\n", getpid());
            // exit the parent process
            exit(0);
        }
    }

    return 0;
}
