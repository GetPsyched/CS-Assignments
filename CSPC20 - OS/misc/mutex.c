#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int var = 0;
pthread_mutex_t mutexLock;

void* func1(void* arg) {
    int i = 0;
    while(i < 5) {
        pthread_mutex_lock(&mutexLock);
        printf("\nThread 1 has entered critical section\n");

        sleep(1);
        var += 5;

        printf("Thread 1 exiting critical section with var = %d\n", var);
        pthread_mutex_unlock(&mutexLock);
        i++;
    }
    return NULL;
}

void* func2(void* arg) {
    int i = 0;
    while(i < 5) {
        pthread_mutex_lock(&mutexLock);
        printf("\nThread 2 has entered critical section\n");

        sleep(1);
        var += 10;

        printf("Thread 1 exiting critical section with var = %d\n", var);
        pthread_mutex_unlock(&mutexLock);
        i++;
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&mutexLock, NULL);
    pthread_t t1, t2;

    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutexLock);
    return 0;
}
