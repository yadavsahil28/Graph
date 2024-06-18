#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>>adj;

    for(auto it:g) {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(n+1,INT_MAX);
    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,-1);

    dist[1] = 0;

    for(int i=1; i<=n; i++){
        int mini = INT_MAX;
        int u = -1;
        for(int j=1; j<=n; j++){
            if(!vis[j] && dist[j]<mini){
                mini = dist[j];
                u = j;
            }
        }

        vis[u] = true;

        for(auto neighbour: adj[u]){
            int node = neighbour.first;
            int weight = neighbour.second;

            if(!vis[node] && dist[node] > weight){
                dist[node] = weight;
                parent[node] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> mst;
    for(int i=2; i<=n; i++){
        mst.push_back(make_pair(make_pair(parent[i],i),dist[i]));
    }
    return mst;
}
