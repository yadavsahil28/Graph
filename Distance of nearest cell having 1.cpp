vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
              if(grid[i][j] == 1){
                  q.push({{i,j},0});
                  vis[i][j] = 1;
              }
        }
    }
    
    pair<int,int> dir[] = {{0,-1},{-1,0},{0,1},{1,0}};
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int row = front.first.first;
        int col = front.first.second;
        int dist = front.second;
       // vis[row][col] = 1;
        ans[row][col] = dist;
        
        for(int i=0; i<4; i++){
            int x = row + dir[i].first;
            int y = col + dir[i].second;
            
            if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0){
                q.push({{x,y},dist+1});
                vis[x][y] = 1;
            }
        }
        
    }
    return ans;
}
