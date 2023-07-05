#include<bits/stdc++.h>
using namespace std;

int partition(int left,int right,vector<int>&arr){

    int pivot=right;
    int start=left;
    int end=left;

    while( start <= right){
        
    
        // while(start <= right and arr[start] <= arr[pivot]) start++;

        // while(end <= right and arr[end] > arr[pivot]) end++;

        // if(start < end)
        //  swap(arr[start],arr[end]);

        if(arr[start] <= arr[pivot]){
            swap(arr[start],arr[end]);
            start++;
            end++;
        }
        else  start++;
    }


    // if(start == right)return start;

    // swap(arr[end],arr[pivot]);

    return end-1;
}

int smallest(vector<int>& arr,int left,int right,int k){
    
    // if( left >= right)return -1;
    int loc=partition(left,right,arr);

    if(loc == k)return arr[loc];
    
    else{
        int ans=0;

        if(loc > k)
         ans=smallest(arr,left,loc-1,k);

         else 
          ans=smallest(arr,loc+1,right,k);

    return ans;

    }


}

int main(){
    vector<int> arr={2,3,4,5,1,3,7,9,12,13,14,0,-2,6,-89};
    int ans=smallest(arr,0,arr.size()-1,14);
    cout<<ans<<endl;

}