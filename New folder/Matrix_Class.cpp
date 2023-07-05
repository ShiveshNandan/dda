#include<bits/stdc++.h>
using namespace std;


class matrix{
   
   public:

   int row;
   int col;
   vector<vector<int>> m1;


   matrix(int row , int col){
    this->row = row;
    this->col = col;
    vector<vector<int>> temp(matrix::row , vector<int>(col));
    m1 = temp;
   }

   void multiply( matrix m2){
        
        for(int i =0;i< row ;i++){

            for(int  j=0;j<col;j++){
                
                 int ans = 0;

               for(int k = 0;k< m2.row ;k++){

                    ans += m1[i][k] * m2.m1[k][i];  
               }

                m1[i][j] = ans;
       
            }
        }
   }


   void add( matrix m2){
       
       for(int i = 0; i< row ;i++){

          for(int j = 0; j < col ; j++){

                m1[i][j] = m1[i][j] + m2.m1[i][j];
          }
       }
   }


   void sub( matrix m2){
       
       for(int i = 0; i< row ;i++){

          for(int j = 0; j < col ; j++){

                m1[i][j] = m1[i][j] - m2.m1[i][j];
          }
       }
   }

   void transpose(){

       for(int i = 0; i< row ; i++){

            for(int j = i;j< col ; j++){      
                 swap( m1[j][i] , m1[i][j]);
            }
       }

   }



};

int main(){

    matrix m1(3,3),m2(3,3);

}
