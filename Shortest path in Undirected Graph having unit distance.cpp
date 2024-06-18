vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(N);
        for(int i=0; i<N; i++){
            dist[i] = INT_MAX;
        }
        
        dist[src] = 0;
        
        queue<int> q;
        q.push(src);
        
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(int neighbour: adj[front]){
                if(dist[neighbour] > dist[front] + 1){
                    dist[neighbour] = dist[front] + 1;
                    q.push(neighbour);
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
