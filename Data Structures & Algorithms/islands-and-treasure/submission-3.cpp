class Solution {
    int dirs[4][2] = {{1,0} , {-1,0} , {0,1} , {0,-1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int , int>> q;

        for(int i = 0 ; i<rows ; i++){
            for(int j = 0 ; j<cols ; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0 ; i<4 ; i++){
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if(r<0 || c<0 || r>=rows || c>=cols || grid[r][c] != INT_MAX)
                    continue;

                grid[r][c] = grid[row][col] + 1;
                q.push({r,c});
            }
        }
    }
};
