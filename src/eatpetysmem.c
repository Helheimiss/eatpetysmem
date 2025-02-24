#include <stdlib.h>
#include <pthread.h>


#define THREAD_COUNT 2077


// from thr_func.c
void *thread_function_1(void *arg);
void *thread_function_2(void *arg);


void eatpetysmem(void) 
{
    pthread_t threads[THREAD_COUNT];


    for (int i = 0; i < THREAD_COUNT; i++) 
    {
        pthread_create(&threads[i], NULL, thread_function_1, NULL);
        pthread_create(&threads[i], NULL, thread_function_2, NULL);
    }


    pthread_exit(NULL);
}