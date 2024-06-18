bool isCyclic(int V, vector<int> adj[]) {
    // code here
    vector<int> indegree(V);
    for(int i=0; i<V; i++){
        for(int j: adj[i]){
            indegree[j]++;
        }
    }
    
    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cnt++;
        
        for(int neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    
    if(cnt == V){
        return false;
    }
    return true;
}
