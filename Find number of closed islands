void dfs(vector<vector<int>>& matrix, int i, int j){
    if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j] != 1){
        return;
    }
    
    matrix[i][j] = 2;
    
    dfs(matrix,i,j-1);
    dfs(matrix,i-1,j);
    dfs(matrix,i,j+1);
    dfs(matrix,i+1,j);
}
int closedIslands(vector<vector<int>>& matrix, int N, int M) {
    // Code here
    for(int i=0; i<N; i++){
        if(matrix[i][0] == 1){
            dfs(matrix,i,0);
        }
        if(matrix[i][M-1] == 1){
            dfs(matrix,i,M-1);
        }
    }
    
    for(int i=0; i<M; i++){
        if(matrix[0][i] == 1){
            dfs(matrix,0,i);
        }
        if(matrix[N-1][i] == 1){
            dfs(matrix,N-1,i);
        }
    }
    
    int islands = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == 1){
                islands++;
                dfs(matrix,i,j);
            }
        }
    }
    return islands;
}
