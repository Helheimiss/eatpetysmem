#include <windows.h>


int ONLY_LEFT = 0; // bool
int WAY = 10; // movement 


void ShakeWindow(HWND hwnd) 
{
    RECT rect;
    GetWindowRect(hwnd, &rect);
    
    
    SetWindowPos(hwnd, NULL, rect.left + WAY, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    // Sleep(1);
    if (ONLY_LEFT == 0) SetWindowPos(hwnd, NULL, rect.left, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    return;
}


BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) 
{
    if (IsWindowVisible(hwnd)) 
    {
        ShakeWindow(hwnd);
    }
    return TRUE;
}


void winshake(int ARG_ONLY_LEFT, int ARG_WAY) 
{
    ONLY_LEFT = ARG_ONLY_LEFT;
    WAY = ARG_WAY;
    while (1)
    {
        EnumWindows(EnumWindowsProc, 0);
    }
}