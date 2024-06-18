bool dfs(int src, vector<int> newAdj[], vector<int>& vis, int parent){
    vis[src] = 1;
    
    for(int neigh: newAdj[src]){
        if(!vis[neigh]){
            bool ans = dfs(neigh,newAdj,vis,src);
            if(ans){
                return true;
            }
        }
        else if(vis[neigh] && neigh != parent){
            return true;
        }
    }
    return false;
}
int isTree(int n, int m, vector<vector<int>> &adj) {
    // code here
    vector<int> newAdj[n];
    
    for(int i=0; i<m; i++){
        int u = adj[i][0];
        int v = adj[i][1];
        
        newAdj[u].push_back(v);
        newAdj[v].push_back(u);
    }
    int parent = -1;
    vector<int> vis(n,0);
    int components = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            components++;
            bool ans = dfs(i,newAdj,vis,parent);
            if(ans){
                return false;
            }
        }
    }
    return (components == 1);
}
