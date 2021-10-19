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
    bool isValidSudoku(vector<vector<char>>& board) {
        int check1[9][9] = {0}, check2[9][9] = {0}, check3[9][9] = {0};
        // check1 : row, check2 : col, check3 : 3by3
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                if(board[i][j] != '.'){
                    int val = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(check1[i][val] || check2[j][val] || check3[k][val])
                        return false;
                    check1[i][val] = check2[j][val] = check3[k][val] = 1;
                }
        return true;
    }
};