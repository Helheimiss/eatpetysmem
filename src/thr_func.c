#include <stdlib.h>


// #define WINDOWS_STP
#ifdef WINDOWS_STP
    #include <Windows.h>
#endif


// from winshake.c
void winshake(int ARG_ONLY_LEFT, int ARG_WAY);


char *ptr = NULL;


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