#include <iostream>
#include <thread>
#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std;

int n;
sem_t mutex_sem;
sem_t empty;
sem_t full;
int counter = 0;

void
consumer() {
    while (counter < 100) {
        sem_wait(&full);
        sem_wait(&mutex_sem);

        /*remove an item from the buffer to next_consumed*/
        cout << "Consumer took an item from the buffer!" << endl;
        int buff_size;
        sem_getvalue(&full, &buff_size);
        cout << "Consumer made buffer size as: " << buff_size << endl;
        counter++;
        sem_post(&mutex_sem);
        sem_post(&empty);

        /*consume the item in next consumed*/
        cout << "Consumer consumed the taken item!" << endl;
    }
}

void
producer() {
    while (counter < 100) {
        /*produce an item in next produced*/
        cout << "Producer produced an item" << endl;
        sem_wait(&empty);
        sem_wait(&mutex_sem);

        /*add next produced to the buffer*/
        cout << "Producer added the item produced to the buffer" << endl;
        int buff_size;
        sem_getvalue(&empty, &buff_size);
        cout << "Producer made the buffer size: " << buff_size << endl;
        counter++;
        sem_post(&mutex_sem);
        sem_post(&full);
    }
}

int
main() {
    cout << "Enter the size of the bounded buffer: ";
    cin >> n;
    sem_init(&mutex_sem, 0, 1);
    sem_init(&empty, 0, n);
    sem_init(&full, 0, 0);

    thread producer_thread(producer);
    thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    sem_destroy(&mutex_sem);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
