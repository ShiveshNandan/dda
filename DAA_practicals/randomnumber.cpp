#include <iostream>
#include <fstream>
#include "myLib.c"
#include"myRandom.h"
using namespace std;

ofstream out;

void rand(long long seed, long long a, long long b, int size)
{
   for(int i=0;i<size;i++){
   long long seed2 = (a * seed + b) % 217211;
   out << seed2;
   out << '\n';
   seed=seed2;
   }
}

void insert(int seed,int size){
   
}

int main(int argv, char *argc[])
{
   int size = stoi(argc[1]);
   int nof = stoi(argc[2]);
   int seed = stoi(argc[3]);
   
   for (int i = 1; i <= nof; i++)
   {
      string txt = ".txt";
      string Num = "Num-00";
      string fno = to_string(i);
      string bal = "-00";
      string sz = to_string(size);
      string name = Num + fno + bal + sz + txt;
      out.open(name);
      rand(seed, 18493, 28347, size);
      insert(seed,size);
      out.close();
   }
   return 0;
}