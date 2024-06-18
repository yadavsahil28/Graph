class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        
        queue<int> q;
        for(int i=0; i<n; i++){
            for(int node: graph[i]){
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            safe[front] = true;

            for(int neigh: adj[front]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        vector<int> safeNodes;
        for(int i=0; i<n; i++){
            if(safe[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
