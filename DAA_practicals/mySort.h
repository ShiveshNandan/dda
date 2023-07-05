#ifndef __MYSORT__
#define __MYSORT__
#include<bits/stdc++.h>
using namespace std;



void swap(unsigned long *a, unsigned long *b) {
    unsigned long temp = *a;
    *a = *b;
    *b = temp;
}



//All functions return the number of comparisons
unsigned long InsertionSort(unsigned long data[], long Size){
    unsigned long comparisons = 0;

    for (long i = 1; i < Size; i++) {
        unsigned long key = data[i];
        int j = i - 1;
 
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
            comparisons++;
        }
        data[j + 1] = key;
    }

    return comparisons;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////


unsigned long BubbleSort(unsigned long data[], long Size){
     unsigned long comparisons = 0;
 
    for (int i = 0; i < Size-1; i++) {
        bool swapped = false;
 
        for (int j = 0; j < Size-i-1; j++) {
            if (data[j] > data[j+1]) {
                swap(data[j], data[j+1]);
                swapped = true;
                comparisons++;
            }
        }

        if (!swapped)
            break;
    }

    return comparisons;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////


unsigned long SelectionSort(unsigned long data[], long Size){
unsigned long  comparisons = 0;

    for (int i = 0; i < Size-1; i++) {
        int minIndex = i;
 
        for (int j = i+1; j < Size; j++) {
            if (data[j] < data[minIndex])
                minIndex = j;
            comparisons++;
        }
 
        swap(data[i], data[minIndex]);
    }

    return comparisons;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////



unsigned long ShellSort(unsigned long data[], long Size){
unsigned long comparisons = 0;
 
    for (int gap = Size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < Size; i++) {
            unsigned long temp = data[i];
            int j;
 
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
                comparisons++;
            }
 
            data[j] = temp;
        }
    }

    return comparisons;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////



int partition(unsigned long arr[], int low, int high, unsigned long &comparisons) {
    unsigned long pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }

    swap(arr[i + 1], arr[high]);
    comparisons++;
    return (i + 1);
}
 
void quickSort(unsigned long arr[], int low, int high, unsigned long &comparisons) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comparisons);
 
        quickSort(arr, low, pivotIndex - 1, comparisons);
        quickSort(arr, pivotIndex + 1, high, comparisons);
    }
}

unsigned long QuickSort(unsigned long data[], long Size){
    unsigned long comparisons = 0;
    quickSort(data, 0, Size-1, comparisons);

    return comparisons;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////



void heapify(unsigned long arr[], unsigned long n, unsigned long i,unsigned long &comparisons) 
{ 
    unsigned long largest = i; 
    unsigned long l = 2*i + 1; 
    unsigned long r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    comparisons++;

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    comparisons++;

    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        comparisons++;
        heapify(arr, n, largest,comparisons); 
    } 
} 

void heapSort(unsigned long arr[], unsigned long n,unsigned long &comparisons) 
{ 
    for (unsigned long i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i,comparisons);
    }

    for (unsigned long i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
        comparisons++;
        heapify(arr, i, 0,comparisons); 
    } 
} 

unsigned long HeapSort(unsigned long data[], long Size){
unsigned long comparisons = 0;
  heapSort(data, Size,comparisons); 
  return comparisons;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////




void merge(unsigned long arr[], unsigned long l, unsigned long m, unsigned long r,unsigned long &comparisons) {
    unsigned long n1 = m - l + 1;
    unsigned long n2 = r - m;

    unsigned long L[n1], R[n2];

    for (unsigned long i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (unsigned long i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    unsigned long i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        comparisons++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        comparisons++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        comparisons++;
    }
}

void mergeSort(unsigned long arr[], unsigned long l, unsigned long r, unsigned long &comparisons) {
    if (l < r) {
        unsigned long m = l + (r - l) / 2;

        mergeSort(arr, l, m,comparisons);
        mergeSort(arr, m + 1,r, comparisons);

        merge(arr, l, m, r,comparisons);
    }
}

unsigned long MergeSort(unsigned long data[], long Size){
    unsigned long comparisons = 0;
    mergeSort(data, 0, Size - 1,comparisons);
    return comparisons;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////



int partition2(unsigned long arr[], int low, int high,unsigned long &comparisons) {
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
    return partition2(arr, low, high,comparisons);
}

void quickSort2(unsigned long arr[], int low, int high,unsigned long &comparisons) {
    if (low < high) {
        comparisons++;
        int pi = randomizedPartition(arr, low, high,comparisons);
        quickSort2(arr, low, pi - 1, comparisons);
        quickSort2(arr, pi + 1, high, comparisons);
    }
}

unsigned long quick(unsigned long arr[],int size) {
   unsigned long comparisons=0;
    quickSort2(arr, 0, size-1,comparisons);
    return comparisons;
}
unsigned long RandomizedQuickSort(unsigned long data[], long Size){
    return quick(data,Size);
}


#endif // __MYSORT__
