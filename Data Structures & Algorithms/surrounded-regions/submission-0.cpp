class Solution {
    int dirs[4][2] = {{1,0} , {-1,0} , {0,1} , {0,-1}};
public:
    void dfs(int r, int c, vector<vector<char>>& board){
        board[r][c] = 'T';

        for(auto& dir : dirs){
            int nr = r + dir[0];
            int nc = c + dir[1];

            if(nr<0 || nc<0 || nr>=board.size() || nc>=board[0].size()){
                continue;
            }
            if(board[nr][nc] != 'O'){
                continue;
            }
            dfs(nr, nc, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int c=0 ; c<cols ; c++){
            if(board[0][c] == 'O'){
                dfs(0 , c , board);     //top row
            }
        }
        for(int c=0 ; c<cols ; c++){
            if(board[rows-1][c] == 'O'){
                dfs(rows-1 , c , board);    //bottom row
            }
        }
        for(int r=0 ; r<rows ; r++){
            if(board[r][0] == 'O'){
                dfs(r , 0 , board);     //left colum
            }
        }
        for(int r=0 ; r<rows ; r++){
            if(board[r][cols-1] == 'O'){
                dfs(r , cols-1 , board);    //right column
            }
        }

        for(int r=0 ; r<rows ; r++){
            for(int c=0 ; c<cols ; c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
                if(board[r][c] == 'T'){
                    board[r][c] = 'O';
                }
            }
        }
    }
};
