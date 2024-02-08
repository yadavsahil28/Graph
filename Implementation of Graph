#include<iostream>
#include<map>
#include<list>
using namespace std;
template <typename T>

class Graph{
    public:
    map<T,list<T>> adjList;
    void addEdge(T u, T v, bool directed){
        adjList[u].push_back(v);
        if(directed == false){
            adjList[v].push_back(u);
        }
    }

    void printAdj(){
        for(pair<T,list<T>> i: adjList){
            cout<<i.first<<" : ";
            for(int j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    // Graph ke sath <int> sirf iss liye likha h kyuki yha hum template ka use kr rhe h
    // template me jo type ka data use kr rhe h wo specify kiya h
    Graph<int> g;
    int n,m;
    cout<<"No. of nodes(n) ";
    cin>>n;
    cout<<"No. of edges(m) ";
    cin>>m;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdj();

}
