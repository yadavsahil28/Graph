vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        // pair(distance,node)
        set<pair<int,int>> s;
        
        dist[S] = 0;
        s.insert(make_pair(0,S));
        
        while(!s.empty()){
            //step1: get the top element
            pair<int,int> top = *(s.begin());
            s.erase(top);
            
            int distance = top.first;
            int node = top.second;
            
            //step2: explore neighbour
            for(vector<int> neighbour: adj[node]){
                if(dist[neighbour[0]] > distance + neighbour[1]){
                    //remove old record
                    auto record = s.find(make_pair(dist[neighbour[0]],neighbour[0]));
                    //if record is found, then erase it
                    if(record != s.end()){
                        s.erase(record);
                    }
                    //dist update
                    dist[neighbour[0]] = distance + neighbour[1];
                    //push new record
                    s.insert(make_pair(dist[neighbour[0]],neighbour[0]));
                }
            }
        }
        return dist;
    }
