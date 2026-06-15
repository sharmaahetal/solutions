class Solution {
public:
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int island = 0;

        for(int r=0 ; r<rows ; r++){
            for(int c=0 ; c<cols ; c++){
                if(grid[r][c] == 1){
                    island = max(island, dfs(grid, r, c));
                }
            }
        }
        return island;
    }
    int dfs(vector<vector<int>>& grid , int r , int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int res = 1;

        for(int i=0 ; i<4 ; i++){
            res += dfs(grid , r + dirs[i][0] , c + dirs[i][1]);
        }
        return res;
    }
};
