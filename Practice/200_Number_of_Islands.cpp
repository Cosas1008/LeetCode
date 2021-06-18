/*
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visit[i][j] && grid[i][j] == '1'){
                    // island
                    cnt += 1;
                    dfs(visit, grid, i, j, m, n);
                }
            }
        }
        return cnt;
    }
    int dfs(vector<vector<bool>>& visit, vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || visit[i][j] || grid[i][j] == '0') return 0;
        int tmp = 1;
        visit[i][j] = true;
        int dir[5] = {0,1,0,-1,0};
        for(int d = 1; d < 5; d++){
            tmp += dfs(visit, grid, i + dir[d-1], j + dir[d], m, n);
        }
        return tmp;
    }
};