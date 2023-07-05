#include <iostream>
#include<graphics.h>


// using namespace std;

int main()
{
    int gdrive=DETECT,gmode;
    int x=64;
    int y=48;
    initgraph(&gdrive,&gmode,(char*)" ");

    x=x+320;
    y=240-y;
    putpixel(x,y,200);

}