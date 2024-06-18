bool isCyclicDirectedDFS(int src, vector<int> adj[], unordered_map<int,bool>& visited, unordered_map<int,bool>& isPresentInRecursiveCall){
    visited[src] = true;
    isPresentInRecursiveCall[src] = true;
    
    for(int neighbour: adj[src]){
        if(!visited[neighbour]){
            bool ans = isCyclicDirectedDFS(neighbour,adj,visited,isPresentInRecursiveCall);
            if(ans == true){
                return true;
            }
        }
        else if(visited[neighbour] && isPresentInRecursiveCall[neighbour]){
            return true;
        }
    }
    isPresentInRecursiveCall[src] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    unordered_map<int,bool> visited;
    unordered_map<int,bool> isPresentInRecursiveCall;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            bool ans = isCyclicDirectedDFS(i,adj,visited,isPresentInRecursiveCall);
            if(ans){
                return ans;
            }
        }
    }
    return false;
}
