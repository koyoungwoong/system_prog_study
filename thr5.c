#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

int c = 0;
bool done = false;

void* producer(void* unused) {
    int i;
    for (i = 0; i < 500; i++) {
        /* produce something */
        /* append it to a list */
        c++;
    }
    done = true;
    return NULL;
}

void* consumer(void* unused) {
    while (!done) {
        while (c > 0) {
            /* remove something from list */
            c--;
        }
    }
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t prod, con;

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&con, NULL, consumer, NULL);

    void* unused;
    pthread_join(prod, &unused);
    pthread_join(con, &unused);

    printf("Net: %d\n", c);
}
