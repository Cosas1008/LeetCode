class Solution {
public:
    // Go from boarder first, can change it from 'O' to '?'
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            if(n > 1){
                dfs(board, i, n-1, m, n);
            }
            dfs(board, i, 0, m, n);
        }
        for(int i = 1; i < n-1; i++){
            if(m > 1){
                dfs(board, m-1, i, m, n);
            }
            dfs(board, 0, i, m, n);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '?'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n){
        if(row >= 0 && col >= 0 && row < m && col < n && board[row][col] == 'O'){
            board[row][col] = '?';
            int direction[5] = {0,1,0,-1,0};
            // Go through 4-direct
            for(int i = 1; i < 5; i++){
                dfs(board, row+direction[i-1], col+direction[i], m, n);
            }
        }
    }
};