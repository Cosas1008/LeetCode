/*
Given island B and A, determine A is the sub island of B
*/
class Solution{
    int countSubIslands(vector<vector<int>>& B, vector<vector<int>>& A){
        int m = A.size(), n = A[0].size(), res = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(A[i][j])
                    res += dfs(B, A, i, j);
        return res;
    }
    int dfs(vector<vector<int>>& B, vector<vector<int>>& A, int x, int y){
        int m = A.size(), n = A[0].size(), res = 1;
        if(x < 0 || y < 0 || x == m || y == n || A[x][y] == 0) return 1; // Smart
        A[x][y] = 0;
        res &= dfs(B, A, x+1, y);
        res &= dfs(B, A, x, y+1);
        res &= dfs(B, A, x-1, y);
        res &= dfs(B, A, x, y-1);
        return res & B[x][y];
    }
}