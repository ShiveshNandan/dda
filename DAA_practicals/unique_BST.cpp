#include <iostream>
#include <vector>
using namespace std;

int numberOfBST(int node , vector<int> &dp){
     
     if( node < 2) return 1;

     if(dp[node] > -1) return dp[node];

     else{
     
           int ans=0;
             for(int i=1;i<=node;i++){
                ans += numberOfBST(i-1,dp)* numberOfBST(node-i,dp);
             }

             return dp[node]=ans;

     }

}

int main(){
    cout<<"Enter number of nodes : ";
    int node=0; 
    cin>> node;
    vector<int> dp(node+1,-1);
    
    cout<<endl<<"Number of possible BST using "<<node<<" nodes is: "<<numberOfBST(node,dp);
    return 0;
}