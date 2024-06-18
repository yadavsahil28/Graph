void topoSortDFS(int src, vector<int> adj[], unordered_map<int,bool>& visited, stack<int>& s){
    visited[src] = true;
    
    for(int neighbour: adj[src]){
        if(!visited[neighbour]){
            topoSortDFS(neighbour,adj,visited,s);
        }
    }
    
    s.push(src);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    unordered_map<int,bool> visited;
    stack<int> s;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            topoSortDFS(i,adj,visited,s);
        }
    }
    
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
