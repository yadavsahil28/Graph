#include<unordered_map>
#include<list>
void dfs(int src, vector<int> adj[], int& timer, vector<int>& parent, vector<int>& vis, vector<int>& low,
            vector<int>& discovery, vector<vector<int>>& ans){
    vis[src] = 1;
    discovery[src] = timer;
    low[src] = timer;
    timer++;
    
    for(int neighbour: adj[src]){
        if(neighbour == parent[src]){
            continue;
        }
        if(!vis[neighbour]){
            parent[neighbour] = src;
            dfs(neighbour,adj,timer,parent,vis,low,discovery,ans);
            low[src] = min(low[src],low[neighbour]);
            if(low[neighbour] > discovery[src] ){
                vector<int> temp;
                temp.push_back(src);
                temp.push_back(neighbour);
                ans.push_back(temp);
            }
        }
        else{
            // back edge case
            low[src] = min(low[src],discovery[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector<int> adj[v];

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> parent(v,-1);
    vector<int> vis(v,0);
    vector<int> low(v,-1); // earliest possible time
    vector<int> discovery(v,-1); // first time visited
    
    vector<vector<int>> ans;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i,adj,timer,parent,vis,low,discovery,ans);
        }
    }
    return ans;

}
