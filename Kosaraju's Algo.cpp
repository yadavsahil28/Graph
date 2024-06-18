void dfs(int src, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s){
	    vis[src] = true;
	    for(int neigh: adj[src]){
	        if(!vis[neigh]){
	            dfs(neigh,adj,vis,s);
	        }
	    }
	    s.push(src);
	}
	
	void revDfs(int src, unordered_map<int,list<int>>& newAdj, vector<bool>& vis2){
        vis2[src] = true;
        for(int neigh: newAdj[src]){
            if(!vis2[neigh]){
                revDfs(neigh,newAdj,vis2);
            }
        }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // STEP 1 : TOPOLOGICAL SORT
        stack<int> s;
        vector<bool> vis(V,false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,adj,vis,s);
            }
        }
        
        // STEP 2 : TRANSPOSE EDGES
        unordered_map<int,list<int>> newAdj;
        for(int i=0; i<V; i++){
            for(int v: adj[i]){
                newAdj[v].push_back(i);
            }
        }
        
        // STEP 3 : DFS based on T.S.
        vector<bool> vis2(V,false);
        int scc = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            if(!vis2[node]){
                scc++;
                revDfs(node,newAdj,vis2);
            }
        }
        return scc;
    }
