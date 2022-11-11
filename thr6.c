#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

void *producer (void *) ;
void *consumer(void *) ;
sem_t empty, full, mutex ;

int buffer[10] /*note extra long space!*/ ;
int ID[10] ;
int in = 0 ; int out = 0 ;
int BUFFER_SIZE = 10 ;
int nextProduced = 0 ;

main() {
    int i ;
    pthread_t TID[10] ;

    sem_init(&empty, 0, 10) ;
    sem_init(&full, 0, 0) ;
    sem_init(&mutex, 0, 1) ;

    for(i = 0; i < 10; i++) {
        ID[i] = i ;
        buffer[i] = -1 ;
    }

    //for(i = 0; i < 5000; i += 2) {
        pthread_create(&TID[0], NULL, producer, (void *) &ID[0]) ;
        printf("Producer ID = %d created!\n", 0) ;
        pthread_create(&TID[1], NULL, consumer, (void *) &ID[1]) ;
        printf("Consumer ID = %d created!\n", 1) ;

        pthread_create(&TID[2], NULL, producer, (void *) &ID[2]) ;
        printf("Producer ID = %d created!\n", 2) ;
        pthread_create(&TID[3], NULL, consumer, (void *) &ID[3]) ;
        printf("Consumer ID = %d created!\n", 3) ;
    //}

    for(i = 0; i < 10 ; i++) {
        pthread_join(TID[i], NULL) ;
    }
}

void *producer(void *Boo) {
    int *ptr;
    int ID;
    ptr = (int *) Boo;
    ID = *ptr;
    while (1) {
        nextProduced++; //Producing Integers
        /* Check to see if Overwriting unread slot */
        sem_wait(&empty);
        sem_wait(&mutex);

        if (buffer[in] != -1) {
            printf("Synchronization Error: Producer %d Just overwrote %d from Slot %d\n", ID, buffer[in], in);
            exit(0);
        }

        /* Looks like we are OK */
        buffer[in] = nextProduced;
        printf("Producer %d. Put %d in slot %d\n", ID, nextProduced, in);
        in = (in + 1) % BUFFER_SIZE;
        printf("incremented in!\n");

        sem_post(&mutex);
        sem_post(&full);
    }
 }

void *consumer (void *Boo) {
    static int nextConsumed = 0 ;
    int *ptr ;
    int ID ;
    ptr = (int *) Boo ;
    ID = *ptr ;
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        nextConsumed = buffer[out];
        /*Check to make sure we did not read from an empty slot*/
        if (nextConsumed == -1) {
            printf("Synch Error: Consumer %d Just Read from empty slot %d\n", ID, out) ;
            exit(0) ;
        }
        /* We must be OK */
        printf("Consumer %d Just consumed item %d from slot %d\n", ID, nextConsumed, out) ;
        buffer[out] = -1 ;
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);
    }
}
