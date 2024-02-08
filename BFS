class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();
            
            for(int neighbour: adj[front]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        
        return ans;
    }
};
