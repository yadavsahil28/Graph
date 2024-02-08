class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int src, vector<int> adj[], vector<int>& ans, unordered_map<int,bool>& visited){
        ans.push_back(src);
        visited[src] = true;
        
        for(int neighbour: adj[src]){
            if(!visited[neighbour]){
                dfs(neighbour,adj,ans,visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        unordered_map<int,bool> visited;
        
        dfs(0,adj,ans,visited);
        return ans;
    }
};
