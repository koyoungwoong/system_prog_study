#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;


int value = 100;
bool notified = false;

void* reporter(void* unused) {
    /*
    pthread_mutex_lock(&m);
    while (!notified) {
        pthread_cond_wait(&cond_var, &m);
    }
    */
    printf("The value is %d\n", value);
    /*
    pthread_mutex_unlock(&m);
    */
    return NULL;
}

void* assigner(void* unused) {
    value = 20;
    /*
    pthread_mutex_lock(&m);
    notified = true;
    pthread_cond_signal(&cond_var);
    pthread_mutex_unlock(&m);
    */
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t rep, asgn;

    pthread_create(&rep, NULL, reporter, NULL);
    pthread_create(&asgn, NULL, assigner, NULL);

    void* unused;

    pthread_join(rep, &unused);
    pthread_join(asgn, &unused);
    return 0;
}
