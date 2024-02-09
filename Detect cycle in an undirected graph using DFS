bool isCyclicDFS(int src, vector<int> adj[], int parent, unordered_map<int,bool>& visited){
    visited[src] = true;
    
    for(int neighbour: adj[src]){
        if(!visited[neighbour]){
            bool ans = isCyclicDFS(neighbour,adj,src,visited);
            if(ans == true){
                return true;
            }
        }
        else if(visited[neighbour] && neighbour != parent){
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    // Disconnected graph h iss liye ye loop lgayi h
    int parent = -1;
    unordered_map<int,bool> visited;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,adj,parent,visited);
            if(ans == true){
                return true;
            }   
        }
    }
    return false;
}
