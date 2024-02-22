class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        queue<pair<int,int>> q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                }
                else if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        int time = 0;
        while(freshOranges != 0 && !q.empty()){
            int size = q.size();
            for(int k=0; k<size; k++){
                pair<int,int> front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;

                pair<int,int> dir[] = {{0,-1},{-1,0},{0,1},{1,0}};
                
                for(int i=0; i<4; i++){
                    int newX = x + dir[i].first;
                    int newY = y + dir[i].second;

                    if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        q.push(make_pair(newX,newY));
                        freshOranges--;
                    }
                }
            }
            time++;
        }
        return freshOranges == 0 ? time : -1;
    }
};
