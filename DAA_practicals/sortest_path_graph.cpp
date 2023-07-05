#include<bits/stdc++.h>
using namespace std;

class graph{
    
    unordered_map<int,list<pair<int,int>>> adj;
    public:
    
    void add_edge(int u,int v,int w){
        adj[u].push_back({v,w});
    }

    void toposort(int node,unordered_map<int,bool> &visited,stack<int> &s){

        visited[node] = true;
        
        for(auto u:adj[node]){
            if(!visited[u.first])
              toposort(u.first,visited,s);
        }

        s.push(node);
    }

    vector<int> shortest_path(int src){
  
          unordered_map<int,bool> visited;
          stack<int> s;

          for(int i=0;i<adj.size();i++){
             if(!visited[i])
              toposort(i,visited,s);
          }

          vector<int> distance(adj.size(),INT_MAX);
          distance[src]=0;
        

          while(!s.empty()){
              int node=s.top();
            //   cout<<node<<endl;
              s.pop();

              if(distance[node] < INT_MAX){

                  for(auto neighbour:adj[node]){
                      if( (neighbour.second + distance[node]) < distance[neighbour.first] )
                         distance[neighbour.first]= neighbour.second + distance[node];
                  }
              }
          }


          return distance;
         
    }



};

int main(){

    graph g;

    g.add_edge(0,1,5);
    g.add_edge(0,2,3);
    g.add_edge(1,2,2);
    g.add_edge(1,3,6);
    g.add_edge(2,3,7);
    g.add_edge(2,4,4);
    g.add_edge(2,5,2);
    g.add_edge(3,4,-1);
    g.add_edge(4,5,-2);
    
    vector<int> ans= g.shortest_path(1);
    
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;

}
