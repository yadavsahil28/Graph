vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here
    int n = image.size();
    int m = image[0].size();
    int initialColor = image[sr][sc];
    image[sr][sc] = newColor;
    
    queue<pair<int,int>> q;
    q.push(make_pair(sr,sc));
    
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        
        int row = front.first;
        int col = front.second;
        
        pair<int,int> dir[] = {{0,-1},{-1,0},{0,1},{1,0}};
        
        for(int i=0; i<4; i++){
            int x = row + dir[i].first;
            int y = col + dir[i].second;
            
            if(x>=0 && x<n && y>=0 && y<m && image[x][y]==initialColor && image[x][y]!=newColor){
                image[x][y] = newColor;
                q.push(make_pair(x,y));
            }
        }
    }
    return image;
}
