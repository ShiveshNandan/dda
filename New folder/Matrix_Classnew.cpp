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

   void fill_mat( vector<vector<int>> temp , int row ,int col){
       
       for(int i = 0 ; i < row ; i++){
            
            for(int j = 0 ; j < col ; j++){
                 
                m1[i][j] = temp[i][j];
            }
       }
   }

   void multiply( matrix m2){
          
    vector<vector<int>> rslt(row,vector<int> (col));
  
    printf("Multiplication of given two matrices is:\n");
  
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            rslt[i][j] = 0;
  
            for (int k = 0; k < row; k++) {
                rslt[i][j] += m1[i][k] * m2.m1[k][j];
            }
        }
    }

    m1 = rslt;

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

   void print(){

        for(int i = 0; i< row ; i++){

            for(int j = 0;j< col ; j++){      
                 cout<<m1[i][j]<<" ";
            }cout<<endl;
       }
   }



};

int main(){

    matrix m1(3,3),m2(3,3);

    m1.fill_mat( { {1,2,3},{4,5,6},{7,8,9}} ,3,3);
    m2.fill_mat( { {1,2,3},{4,5,6},{7,8,9}},3,3);

    m1.print();

    m1.multiply(m2);
    // m1.transpose();
    m1.print();



}
