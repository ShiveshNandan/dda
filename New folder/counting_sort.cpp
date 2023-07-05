
#include<bits/stdc++.h>

using namespace std;

class counting_sort{
    public:
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
};

int main(vector<unsigned long> arr){
    vector<unsigned long>ans={2,4,5,1,1,3,4,7};
   counting_sort x;
//    x.sort(ans);
   for(auto y:ans){
    cout<<y<<" ";
   }cout<<endl;
   return 0;
}