#include <bits/stdc++.h>
using namespace std;

void swap(unsigned long *a, unsigned long *b) {
    unsigned long temp = *a;
    *a = *b;
    *b = temp;
}

int partition(unsigned long arr[], int low, int high,unsigned long &comparisons) {
    unsigned long pivot = arr[high];
    int i = low - 1;
 
    for (int j = low; j <= high - 1; j++) {
      comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int randomizedPartition(unsigned long arr[], int low, int high,unsigned long &comparisons) {
    srand(time(NULL));
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high,comparisons);
}

void quickSort(unsigned long arr[], int low, int high,unsigned long &comparisons) {
    if (low < high) {
        comparisons++;
        int pi = randomizedPartition(arr, low, high,comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

unsigned long quick(unsigned long arr[],int size) {
   unsigned long comparisons=0;
    quickSort(arr, 0, size-1,comparisons);
    return comparisons;
}
