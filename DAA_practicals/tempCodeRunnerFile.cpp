int main(){

    G<int> graph;

   graph.add_node(0,"shivam");
    graph.add_node(1,"shvam");
    graph.add_node(2,"shiam");
    graph.add_node(3,"shiv");
    graph.add_node(4,"shiva");
    graph.add_edge( "shiam","shiva","yesh",5);
    graph.add_edge( "shiam","shiv","esh",5);

    graph.print();

    cout<<"hello world"<<endl;
    return 0;
}