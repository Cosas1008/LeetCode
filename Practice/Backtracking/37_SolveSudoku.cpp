class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
private:
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        // check row
        int row = i - i % 3;
        int col = j - j % 3;
        for(int x=0; x < 9; x++) if(board[x][j] == val) return false;
        for(int y=0; y < 9; y++) if(board[i][y] == val) return false;
        for(int x=row; x < row+3; x++){
            for(int y = col; y < col+3; y++){
                if(board[x][y] == val) return false;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) return true;
        if(j==9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
        for(char c = '1'; c <= '9'; c++){
            if(check(board, i, j, c)){
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.'; // backtracking
            }
        }
        return false;
    }
};