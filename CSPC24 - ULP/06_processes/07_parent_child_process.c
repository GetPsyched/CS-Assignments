#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pid, status;
    printf("Hello World!\n");

    pid = fork();
    if (pid == -1) {
        perror("An error occured!");
        exit(1);
    }

    if (pid == 0)
        printf("Child\n");
    else {
        wait(&status); // waiting for child process to complete execution
        printf("Parent\n");
    }
}
