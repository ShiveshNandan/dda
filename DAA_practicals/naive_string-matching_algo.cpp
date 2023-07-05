#include<iostream>
#include<string>
using namespace std;

int check(string str1, string str2){
   for(int i=0;i<str1.size();i++){
    
       for(int j=0,k=i;j<str2.size();){
         if(str1[k] != str2[j]) break;
         if( str1[k] == str2[j]){
            k++;
            j++;
         }
         if(j == str2.size()) return i;
       }

   }

   return -1;
}

int main(){
    string str1="dfghjiavm";
    string str2="iavm";
    int ans=check(str1,str2);
    cout<<ans;
}
