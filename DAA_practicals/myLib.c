#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "myLib.h"
#include<fstream>
// ofstream outi;
// int Swap(void* a, void* b, int Size){
//     void *t = malloc(Size);
//     if (!t) return 0;
//     memcpy(t,b,Size);
//     memcpy(b,a,Size);
//     memcpy(a,t,Size);
//     free(t);
//     return 1;
// }

__attribute__ ((constructor)) void myStartupFun (void) {
    QueryPerformanceFrequency(&TimeFrequency);
    QueryPerformanceCounter(&TimeStart);
}

__attribute__ ((destructor)) void myCleanupFun (void) {
    QueryPerformanceCounter(&TimeEnd);
    TimeInterval = (double) (TimeEnd.QuadPart - TimeStart.QuadPart) / TimeFrequency.QuadPart;
    // outi.open("bubble_avg_time.txt",ios :: app);
    // outi<<"\n"<<TimeInterval;
    printf("Time taken %f",TimeInterval);
}
