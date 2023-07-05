#include<bits/stdc++.h>
#include"graph.cpp"

void vertexCover( G<int> graph ){

    unordered_map<string , bool> exist;

    queue<pair<string,string>> que;

    for(int i = 0 ; i<graph.edglist.size() ; i++){
        que.push(graph.edglist[i].first);
    }


    while( ! que.empty() ){

        string u = que.front().first;
        string v = que.front().second;
        que.pop();

        if( (! exist.count(u) ) and  (! exist.count(v)) ){
            exist[u] = true;
            exist[v] = false;
        }

    }

    set<string> ans;
   
   for(auto x: exist)
       ans.insert(x.first);


   for(auto x : ans){

     cout<<x<<endl;
   }
   


}

int main(){

    G<int> graph;

    graph.add_node(  9 , "0" );
    graph.add_node(  9 , "1" );
    graph.add_node(  9 , "2" );
    graph.add_node(  9 , "3" );
    graph.add_node(  9 , "4" );

    graph.add_edge( "2" , "4" , "9" , 1 );
    graph.add_edge( "0" , "2" , "9" , 1 );
    graph.add_edge( "1" , "4" , "9" , 1 );
    graph.add_edge( "3" , "4" , "9" , 1 );

    vertexCover( graph );

    return 0;
}