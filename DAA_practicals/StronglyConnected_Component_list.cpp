#include<bits/stdc++.h>
#include "graph.cpp"
using namespace std;



void toposort( vector<int>& arr , int N , vector<vector<int>> adj_list){
 
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

    if(que.empty()){
        que.push(0);
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



int Connected_componentCount( G<int> graph  , int N ){

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


    // step 1 get the topological sort
    vector<int> arr;
    toposort( arr , N ,adj_list);


    // step 2 get tranposed the graph

    vector<vector<int>> Tadj(N);

    for(int i = 0; i  < N ; i++){

        for(int j = 0; j < adj_list[i].size() ; j++){

            if( i == j )continue;

            // creating the edge in the reverse order
             Tadj[adj_list[i][j]].push_back(i);
        }

    }


    // step 3 do dfs on the Tadj with reference of the sorted list arr


   vector<int> visited(N,false);
   stack<int> stk;
   int count = 0 ;

   for(int u : arr){

    if(visited[u])
    continue;

    stk.push(u);
   

    while(!stk.empty()){
     
         int node = stk.top();
         stk.pop();
         visited[node] = true;

         for(auto neighbour : Tadj[node]){

            if(!visited[neighbour])
            stk.push(neighbour);
         }

    }

    count++;

   }

   return count;

 
}



int main(){

    G<int> graph;

    graph.add_node( 0 , "0");
    graph.add_node( 1 , "1");
    graph.add_node( 2 , "2");
    // graph.add_node( 3 , "3");

    graph.add_edge( "0" ,"1" ," 1" , 8);
    // graph.add_edge( "1" ,"0" ," 1" , 8);
    // graph.add_edge( "0" ,"3" ," 1" , 8);
    graph.add_edge( "1" ,"2" ," 1" , 8);
    graph.add_edge( "2" ,"0" ," 1" , 8);
    // graph.add_edge( "3" ,"2" ," 1" , 8);

    int count  = Connected_componentCount(graph,3);

    cout<<"No.of Strongly Connected component in this graph = "<<count<<endl;
 
    // graph.print();
}