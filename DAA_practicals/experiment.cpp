#include <iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
#include "MyTime.h"
#include<fstream>
#include"mysort.h"
// #include"mySort_noncomparisive.h"

ifstream in;
ofstream out;

int main()
{
    myTimer time;
   long sizearr[]={5,10,25, 50,100,250, 500,1000,2500, 5000,10000,25000};

   for(auto size : sizearr){
   
    string filename;
    vector<unsigned long> arr(size,0);
   //   int arr[size];
    long double count=0.0;
    long double intr=0.0;
     
     for(int i=1;i<=30;i++){

      string txt = ".txt";
      string Num = "Num-00";
      string fno = to_string(i);
      string bal = "-00";
      string sz = to_string(size);
      string name = Num + fno + bal + sz + txt;

    in.open(name);

cout<<name<<endl;
     
    for(int i=0;i<size;i++){
       in>>arr[i];
    }
    
 
    in.close();

    time.StartTimer();
    count=count+bubble(arr,size);
    time.EndTimer();
    intr= intr+time.GetInterval();
     }

     count=count/30;
     intr=intr/30;

   out.open("bubble_analtsis.txt",ios:: app);
   out<<"\n"<<setw(6)<<setfill('0')<<size<<"       ";
   out<<setw(15)<<setfill('0')<<intr<<"      ";
   out<<setw(15)<<setfill('0')<<count;
   out.close();

   }
    

   return 0;
    
}