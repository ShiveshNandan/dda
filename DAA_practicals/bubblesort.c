#include<stdio.h>

int count=0;

int bubble(int arr[],int size)
{
    
    for(int j=0;j<size;j++){
   
     for(int i=0;i<size;i++)
     {
        if ( arr[i]>arr[i+1])
        {   count++;
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]= temp;
        
        }
     }
    }
    return count;
    // for(int i =0;i<size;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    // return 0;
}