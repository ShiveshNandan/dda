 
#include<bits/stdc++.h>

using namespace std;

class min_max{
    public:
    
    pair<int,int>find_MinAndMax(vector<int> arr){
          int min=arr[0];
          int max=arr[0];

          for(auto x:arr){
             if(min > x)
               min=x;
             if(max < x)
               max=x;  
          }

          return {min,max};
    }

    int min(vector<int> arr){
        int mini=arr[0];
         for(auto x:arr){
            if(mini > x)
             mini=x;
         }
         return mini;
    }

    int max(vector<int> arr){
        int maxi=arr[0];
         for(auto x:arr){
            if(maxi > x)
             maxi=x;
         }
         return maxi;
    }
};

int main(){

    min_max obj;
    vector<int> arr={1,4,5,6,7,8,9,3,4,6,7,8,8,9};
    pair<int,int> ans =obj.find_MinAndMax(arr);

    cout<<"MIN :"<<ans.first<<endl;
    cout<<"MAX :"<<ans.second<<endl;


    return 0;
}