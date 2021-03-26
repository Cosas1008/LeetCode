class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValid(board, 0, 0);
    }
private:
    bool isValid(vector<vector<char>>& board, int i, int j){
        if(i == 9) return true;
        if(j == 9) return isValid(board, i+1, 0);
        if(board[i][j] == '.') return isValid(board, i, j+1);
        int row  = i - i%3;
        int col  = j - j%3;
        char val = board[i][j];
        for(int x = 0; x < 9; x++) if(x!=i && board[x][j] == val) return false;
        for(int y = 0; y < 9; y++) if(y!=j && board[i][y] == val) return false;
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++)
                if(x!=(i-row) && y!=(j-col) && board[row+x][col+y] == val)
                    return false;
        return isValid(board, i, j+1);
    }
};