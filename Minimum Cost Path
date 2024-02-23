int minimumCostPath(vector<vector<int>>& grid) 
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push(make_pair(grid[0][0],make_pair(0,0)));
    ans[0][0] = grid[0][0];
    
    while(!pq.empty()){
        pair<int,pair<int,int>> front = pq.top();
        pq.pop();
        int sum = front.first;
        int row = front.second.first;
        int col = front.second.second;
        
        if(row == n-1 && col == m-1){
            break;
        }
        
        pair<int,int> dir[] = {{-1,0},{0,1},{1,0},{0,-1}};
        
        for(int i=0; i<4; i++){
            int x = row + dir[i].first;
            int y = col + dir[i].second;
            if(x>=0 && x<n && y>=0 && y<m && ans[x][y] > ans[row][col] +  grid[x][y]){
                ans[x][y] = ans[row][col] + grid[x][y];
                pq.push(make_pair(ans[x][y],make_pair(x,y)));
            }   
        }
    }
    return ans[n-1][m-1];
}
