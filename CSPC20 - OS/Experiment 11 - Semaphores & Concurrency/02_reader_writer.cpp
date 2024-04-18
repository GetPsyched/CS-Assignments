#include <iostream>
#include <thread>
#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std;

sem_t rw_mutex;
sem_t mutex_sem;
int read_count = 0;
int counter = 0;

void
reader() {
    while (counter < 100) {
        sem_wait(&mutex_sem);
        read_count++;
        cout << "read_count becomes: " << read_count << endl;
        if (read_count == 1)
            sem_wait(&rw_mutex);
        sem_post(&mutex_sem);

        cout << "Readers are reading: " << endl;
        sem_wait(&mutex_sem);

        read_count--;
        if (read_count == 0)
            sem_post(&rw_mutex);
        sem_post(&mutex_sem);
        counter++;
    }
}

void
writer() {
    while (counter < 100) {
        sem_wait(&rw_mutex);
        /** some writing is performed*/
        cout << "The writer is writing to the file!" << endl;
        counter++;
        sem_post(&rw_mutex);
    }
}

int
main() {
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex_sem, 0, 0);
    thread reader1_thread(reader);
    thread writer1_thread(writer);
    thread reader2_thread(reader);
    thread reader3_thread(reader);
    thread reader4_thread(reader);
    thread writer2_thread(writer);
    reader1_thread.join();
    reader2_thread.join();
    reader3_thread.join();
    reader4_thread.join();
    writer1_thread.join();
    writer2_thread.join();
    return 0;
}
