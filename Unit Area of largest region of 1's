void dfs(vector<vector<int>>& grid, int i, int j, int& area){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
        return;
    }
    
    if(grid[i][j] == 0 || grid[i][j] == 2){
        return;
    }
    
    area++;
    grid[i][j] = 2;
    
    dfs(grid,i,j-1,area);
    dfs(grid,i-1,j-1,area);
    dfs(grid,i-1,j,area);
    dfs(grid,i-1,j+1,area);
    dfs(grid,i,j+1,area);
    dfs(grid,i+1,j+1,area);
    dfs(grid,i+1,j,area);
    dfs(grid,i+1,j-1,area);
}
int findMaxArea(vector<vector<int>>& grid) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    
    int maxArea = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int area = 0;
            if(grid[i][j] == 1){
                dfs(grid,i,j,area);
                maxArea = max(maxArea,area);
            }
        }
    }
    return maxArea;
}
