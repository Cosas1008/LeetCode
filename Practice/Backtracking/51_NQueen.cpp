class Solution {
public:
    bool isQueenValid(int row, int col, vector<string> board, int& n){
        // check up
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q') return false;
        }
        int r = row, c = col;
        // check left diagnal
        while(r>=0&&c>=0){
            if(board[r--][c--] == 'Q') return false;
        }
        // check right diagnal
        r = row, c = col;
        while(r >=0 && c < n){
            if(board[r--][c++] == 'Q') return false;
        }
        return true;
    }
    void helper(int& n, vector<vector<string>>& ans, int row, vector<string>& board){
        if(n == row){
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isQueenValid(row,col,board,n)){
                board[row][col] = 'Q';
                helper(n, ans, row+1,board);
                board[row][col] = '.';
            }
        }
    }
};