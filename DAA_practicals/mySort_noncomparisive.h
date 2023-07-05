#ifndef __MYSORT__
#define __MYSORT__
#include<bits/stdc++.h>
using namespace std;

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

unsigned long bucket_sort(std::vector<unsigned long> arr,int size) {
    // Example usage
    unsigned long compCount = bucketSort(arr,10 );
    return compCount;
}


////////////////////////////////////////////////////////////////////////





 void counting_for_radix(vector<unsigned long> &arr, int itr)
    {
        vector<unsigned long> org = arr;
        map<unsigned long, unsigned long> mapy;

        for (auto x : arr)
        {    
           unsigned long temp=x;
            unsigned long ans=x;
            for (int i = 0; i < itr; i++){
                 ans=temp%10;
                 temp=temp/10;
            }

            mapy[ans] = mapy[ans] + 1;
        }

        arr.clear();

        vector<unsigned long>::iterator it = org.begin();
        for (auto ele : mapy)
        {
            for (unsigned long b = 0; b < ele.second; b++)
            {
                it = org.begin();
                for (unsigned long i = 0; i < org.size(); i++, it++)
                {
                    unsigned long ans = org[i];
                    unsigned long temp=org[i];
        
                    for (unsigned long k = 0; k < itr; k++)
                    {   
                        ans = temp % 10;
                        temp=temp/10;
                    }
                    if ( ans == ele.first)
                    {
                        arr.push_back(org[i]);
                        org.erase(it);
                        i--;
                        it--;
                    }
                }
            }
        }
    }





      void sort_radix(vector<unsigned long> &arr)
    {
        unsigned long maxi = *(max_element(arr.begin(), arr.end()));
        unsigned long count = 0;
        while (maxi != 0)
        {
            maxi = maxi/10;
            count++;
        }

        for (unsigned long i = 1; i <= count; i++)
        {
            counting_for_radix(arr, i);
        }
    }

 unsigned long radixSort(vector<unsigned long> arr,int size){
      
      sort_radix(arr);

 }




 //////////////////////////////////////////////////////////////////////





 
    void sort_counting(vector<unsigned long> &arr){

        map <unsigned long,unsigned long> mapy;
        
        for(auto x:arr){
            mapy[x]=mapy[x]+1;
        }
        
        arr.clear();

        for(auto ele:mapy){
            for(int i=0;i<ele.second;i++)
             arr.push_back(ele.first);
        }
    }

void counting(vector<unsigned long> arr){
     sort_counting(arr);
}


#endif // __MYSORT__