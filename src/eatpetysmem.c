#include <stdlib.h>
#include <pthread.h>
#include "../include/thr_func.h"


#define THREAD_COUNT 2077


void eatpetysmem(void) 
{
    pthread_t threads[THREAD_COUNT];


    for (int i = 0; i < THREAD_COUNT; i++) 
    {
        pthread_create(&threads[i], NULL, thread_function_1, NULL);
        #if C_OS == 1
            pthread_create(&threads[i], NULL, thread_function_2, NULL);
        #endif
    }


    pthread_exit(NULL);
}