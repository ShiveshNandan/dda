#include<bits/stdc++.h>
#include "graph.cpp"
using namespace std;



void toposort( G<int> graph , vector<int>& arr , int N ){

    vector<vector<int>> adj_list(N);

    
     // creating the adgcentcy list
    for(int i =0;i<graph.adj.size() ; i++){

         list < G<int> ::node* > :: iterator it = graph.adj[i].begin();

         for( ; it != graph.adj[i].end() ; it++){

             // first node will de denoted by the index of the vector itself 
            if(it == graph.adj[i].begin())continue;

              adj_list[(*(graph.adj[i].begin()))->data].push_back((*it)->data);
         }

    }

 
    queue<int> que;
    vector<int> indegree(N,0);



    for(int i =0; i < N ;i++){
         
         // inisializing the indegrees 
         for(int j = 0; j< adj_list[i].size() ; j++ ){
            indegree[adj_list[i][j]]++;
         }
    }



    for( int i = 0 ; i < indegree.size() ; i++ ){
        
          // initializing the queue
        if(indegree[i] == 0){
            que.push(i);
        }
    }

  

    while(!que.empty()){

        int node = que.front();
        arr.push_back(node); // storing the uppper most node having indegree = 0
        que.pop();

        for(auto neighbour : adj_list[node]){

            // as the node deleted the indegree should also be reduced for there neighbours
            indegree[neighbour]--;

            // if some of the neighbour have indegree == 0 thats mean no node is present above that
            // so should be pushed into the queue
            if(indegree[neighbour] == 0)
               que.push(neighbour);
              
        }
    }

    return;
}



int main(){

    G<int> graph;

    graph.add_node( 0 , "0");
    graph.add_node( 1 , "1");
    graph.add_node( 2 , "2");
    graph.add_node( 3 , "3");

    graph.add_edge( "0" ,"1" ," 1" , 8);
    graph.add_edge( "0" ,"3" ," 1" , 8);
    graph.add_edge( "1" ,"2" ," 1" , 8);
    graph.add_edge( "3" ,"2" ," 1" , 8);

    vector<int> arr;

    toposort( graph , arr , 4 );

    for(auto x: arr)
     cout<<x<<" ";

     cout<<endl;
 
    // graph.print();
}