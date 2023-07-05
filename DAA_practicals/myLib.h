#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <windows.h>
/////////////////////////////////////////////////////////////////
// The function swaps the content of a and b, remember they have
// to be of same size.
int Swap(void* a, void* b, int Size);

/////////////////////////////////////////////////////////////////
//Time Measurement functions
LARGE_INTEGER TimeFrequency;
LARGE_INTEGER TimeStart;
LARGE_INTEGER TimeEnd;
double TimeInterval;

__attribute__ ((constructor)) void myStartupFun (void) ;
__attribute__ ((destructor)) void myCleanupFun (void) ;

#endif // MYLIB_H_INCLUDED
