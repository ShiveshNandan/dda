#include<stdio.h>

int count=1;
int  temp=0;;
int  j=0;
int  i=0;

int insertion(int arr[],int  size){
// cout<<"fghjk";
// unsigned long  n=size;
for(i=1;i<size;i++){ 
                                                  
    temp=arr[i];
      j=i-1;

        // cout<<"fghjk";
    while( j>=0  && arr[j] > temp ){   
        count++;
        arr[j+1]=arr[j];
        j--;
    }

//  printf("fghjkk\n");
    arr[j+1]=temp;
}
      
       return count;
}