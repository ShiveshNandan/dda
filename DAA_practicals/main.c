#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dsaassignment20.c"

int main()
{
    /////////////////////////////////////////////////////////
    // code to be measured
    // double x=100.0, y=200.0;
    // for (long long i =0; i< 100000;i++) {
    //     printf("%ld\n",i);
    //     Swap(&x,&y,sizeof(double));
    // }

    
   printf("Enter the size of array :");
   int size;
   scanf("%d",&size);
   int arr[size];bool loop=true;
   printf("Enter the element of the array :");
   for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
   }

   while(loop){
   printf("\n\n1 Insertion\n2 Bubble\n3 Quicksort\n4 Heapsort\n5 Mergesort\n6 Shell sort\n Your input :");
   int choice;
   scanf("%d",&choice);
   switch(choice){
    case 1: insertion(arr,size);break;
    case 2: bubble(arr,size);break;
    case 3: quick(arr,size);break;
    case 4: heap(arr,size);break;
    case 5: merging(arr,size);break;
    case 6: shell(arr,size);break;
    default : printf("\n\nEnter a valid input \n\n");loop=false;break;
   }
   
   
} 


    return 0;
}
