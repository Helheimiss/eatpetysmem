#include <stdlib.h>
#include "thr_func.h"


#if C_OS == 1
    // from winshake.c
    void winshake(int ARG_ONLY_LEFT, int ARG_WAY);
#endif


char *ptr1 = NULL;
char *ptr2 = NULL;


void *thread_function_1(void *arg) 
{
    while (1)
    {
        ptr1 = malloc(1);
        *ptr1 = 127;
        if (ptr1 != NULL)
        {
            free(ptr1);
        }
        
    }

    return NULL;
}


#if C_OS == 1
void *thread_function_2(void *arg) 
{
    while (1)
    {
        winshake(0, 10);
    }

    return NULL;
}
#endif