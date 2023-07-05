#include <iostream>
#include <vector>
#include <algorithm>

unsigned long bucketSort(std::vector<unsigned long>& arr, int numBuckets) {
    unsigned long compCount = 0;

    // Find maximum element in the array
    unsigned long maxVal = *std::max_element(arr.begin(), arr.end());

    // Create buckets and distribute elements into them
    std::vector<std::vector<unsigned long>> buckets(numBuckets);
    for(unsigned long i : arr) {
        int bucketIdx = (int)(i / ((maxVal + 1) / numBuckets));
        buckets[bucketIdx].push_back(i);
    }

    // Sort each bucket and concatenate results back into original array
    int idx = 0;
    for(auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for(unsigned long elem : bucket) {
            arr[idx++] = elem;
            if(idx > 1) {
                compCount++;
            }
        }
    }

    return compCount;
}

unsigned long main(std::vector<unsigned long> arr,int size) {
    // Example usage
   
    unsigned long compCount = bucketSort(arr,10 );

   

    return compCount;
}