bool isCyclicBFS(int src, vector<int> adj[], unordered_map<int,bool>& visited, unordered_map<int,int>& parent){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int neighbour: adj[front]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
            else if(visited[neighbour] && neighbour != parent[front]){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    // Disconnected graph h iss liye ye loop lgayi h
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i,adj,visited,parent);
            if(ans == true){
                return true;
            }   
        }
    }
    return false;
}
