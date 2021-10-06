/*
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(dfs(board, i, j, word)) return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        if (!word.size())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[0])  
            return false;
        char c = board[i][j];
        board[i][j] = '*'; // mark 
        string s = word.substr(1);
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        board[i][j] = c; // reset
        return ret;
    }
private:
    int m, n;
    int dir[5] = {0,1,0,-1,0};
};