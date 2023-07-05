  
#include<stdio.h>

void quickSort(unsigned long arr[], int left, int right) {
    int i = left, j = right;
    unsigned long tmp;
    unsigned long pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}


int partition(int arr[],int lb,int ub,long double* count)
{
  int start=lb+1;
  int end=ub;
  int pivot=lb;

  while( start <= end)
  { 
    //  *count++;
     while(arr[start] <= arr[pivot] )
     {
      // *count++;
      start++;
     }

     while( arr[end] > arr[pivot])
     {
      // *count++;
      end--;
     }

     if( start < end)
     {
      // *count++;
      int temp = arr[start];
      arr[start]=arr[end];
      arr[end]=temp;

     }
  }


  int temp = arr[end];
   arr[end]= arr[pivot];
   arr[pivot]=temp;

   return end;
}


void quicksort(int arr[],int lb,int ub,long double* count)
{
  if(lb < ub)
  {
    // *count++;
  int loc = partition(arr,lb,ub,count);

  quicksort(arr,lb,loc-1,count);
   
  quicksort(arr,loc+1,ub,count);
    
  }
}

void quick(unsigned long arr[],int size)
{
  int lb=0,ub=size-1;
//   long double count =0.0;
//   long double* counter=&count;
  quickSort(arr,lb,ub);
  for(int i=0;i<=ub;i++)
  {
    printf("%d ",arr[i]);
  }
  // return *counter;
}