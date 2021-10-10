/*
1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.

Traverse All empty squares
*/
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // 1. get to know where the start, end and #of empty
        // explore and change 0 to -2 along the way with dfs
        m = grid.size(), n = grid[0].size();
        empty = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }else if(grid[i][j] == 0)
                    empty++;
            }
        }
        dfs(grid, sx, sy);
        return res;
    }
    // Backtracking
    void dfs(vector<vector<int>> grid, int x, int y){
        if(x < 0 || y < 0 || x == m || y == n || grid[x][y] < 0) return;
        if(grid[x][y] == 2){ // ending square
            if(empty == 0) res++;
            return;
        }
        grid[x][y] = -2; // record
        empty--;
        for(int dir = 0; dir < 4; ++dir)
            dfs(grid, x+d[dir], y+d[dir+1]);
        empty++;
    }
private:
    int m, n;
    int d[5] = {0, 1, 0, -1, 0};
    int res, empty, sx, sy;
};