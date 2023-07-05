#include<bits/stdc++.h>
#include"graph.cpp"

using namespace std;



vector<pair<int,pair<string,string>> >  prims( G<int> graph , int N){

       
    unordered_map< string , vector<pair< int , pair< string,string >> >> edge_list;

    for(int  i =0 ;i<graph.edglist.size() ; i++){
       edge_list[graph.edglist[i].first.first].push_back ( { graph.edglist[i].second.second , { graph.edglist[i].first.first ,graph.edglist[i].first.second }} );
    }
    

      // initializing min heap 
    priority_queue< pair<int,pair<string,string>> , vector<pair<int,pair<string,string>>> , greater<pair<int,pair<string,string>>>> pq;
    vector<pair<int,pair<string,string>> > ans;

    pq.push(edge_list["1"][0]);

    int minCost = 0;



    for(int i = 1 ; i < N ; i++){

      pair<int,pair<string,string>> Edge = pq.top();
      minCost += Edge.first;
      ans.push_back(Edge);
      pq.pop();
      
      for( auto x : edge_list[Edge.second.second] ){
            pq.push(x);
         }
     
    }

    return ans;

    // cout<<"The minimum cost for the minimum spaning tree of thr given graph is : " <<minCost<<endl<<endl;

    // cout<<"The path as follows : "<<endl;
    
    // for(auto x : ans){
    //   cout<<x.second.first<<" -> "<<x.second.second<<endl;
    // }
 
}

void traverse(){

    
}


void inorderTraversal(  vector<string>&ans , vector<pair<int,pair<string,string>> > & mst ){

    unordered_map<string , vector<string> > adj_list;

    for(int i= 0 ; i< mst.size() ; i++){

        adj_list[mst[i].second.first].push_back( {mst[i].second.second});
    }

    

    
}


void  Tsp( G<int> graph , int N ){


     // step 1 create a MST;
    vector<pair<int,pair<string,string>> > MST = prims(graph , N);

    vector<string> ans;
      
      // step2 save inorder traversal 
    inorderTraversal( ans , MST );
    

    // print the path
    for( auto a : ans){
        cout<<a<<"->";
    }
    
    return;

}