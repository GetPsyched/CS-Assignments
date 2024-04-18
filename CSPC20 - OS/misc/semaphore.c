#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t s;
int var = 1;

void* func1(void* arg) {
    int i = 0;
    while(i < 5) {
        sem_wait(&s);
        printf("\nThread 1 has entered critical section\n");

        sleep(1);
        var += 5;

        printf("Thread 1 exiting critical section with var = %d\n",var);
        sem_post(&s);
        sleep(1);
        i++;
    }
}

void* func2(void* arg) {
    int i = 0;
    while(i < 5) {
        sem_wait(&s);
        printf("\nThread 2 has entered critical section\n");

        sleep(1);
        var += 10;

        printf("Thread 2 exiting critical section with var = %d\n",var);
        sem_post(&s);
        i++;
    }
}

int main() {
    sem_init(&s, 0, 1);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, func1, NULL);
    sleep(2);
    pthread_create(&t2, NULL, func2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&s);
    return 0;
}
