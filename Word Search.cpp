bool dfs(vector<vector<char>>& board, int i, int j, string word, vector<vector<bool>>& vis, int index){
    if(index == word.size()){
        return true;
    }
    
    if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || word[index] != board[i][j] || vis[i][j] == true){
        return false;
    }
    
    vis[i][j] = true;
    index++;
    
    bool l = dfs(board,i,j-1,word,vis,index);
    bool u = dfs(board,i-1,j,word,vis,index);
    bool r = dfs(board,i,j+1,word,vis,index);
    bool d = dfs(board,i+1,j,word,vis,index);
    
    vis[i][j] = false;
    return (l || u || r || d == true);
}
bool isWordExist(vector<vector<char>>& board, string word) {
    // Code here
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int index = 0;
            if(board[i][j] == word[0]){
                if(dfs(board,i,j,word,vis,index)){
                    return true;
                }
            }
        }
    }
    return false;
}
