class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ret = 1;
        vector<vector<int>> cache(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                int len = dfs(matrix, i, j, cache);
                ret = max(ret, len);
            }
        return ret;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& cache){
        if(cache[x][y] != 0) return cache[x][y];
        int lmax = 1;
        for(int i = 0; i < 4; ++i){
            int dx = x + dir[i], dy = y +dir[i+1];
            if(dx < 0 || dy < 0 || dx == m || dy == n || matrix[dx][dy] <= matrix[x][y]) continue;
            int len = 1 + dfs(matrix, dx, dy, cache);
            lmax = max(lmax, len);
        }
        cache[x][y] = lmax;
        return lmax;
    }
private:
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};
};

// Creative way
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      vector<vector<int>> tb(m, vector<int>(n, 0));
      vector<vector<int>> bt(m, vector<int>(n, 0));
      vector<vector<int>> lr(m, vector<int>(n, 0));
      vector<vector<int>> rl(m, vector<int>(n, 0));
      // horizontal
      for(int i = 0; i < m; ++i){
        // from left to right : lr
        for(int j = 1; j < n; ++j){
          lr[i][j] = lr[i][j-1] + (matrix[i][j-1] < matrix[i][j]);
        }
        // from right to left : rl
        for(int j = n-2; j >= 0; --j){
          rl[i][j] = rl[i][j+1] + (matrix[i][j+1] < matrix[i][j]);
        }
      }
      // vertical
      for(int i = 0; i < n; ++i){
        // from top to bottom : tb
        for(int j = 1; j < m; ++j){
          tb[j][i] = tb[j-1][i] + (matrix[j-1][i] < matrix[j][i]);
        }
        // from bottom to top : bt
        for(int j = m-2; j >= 0; --j){
          bt[j][i] = bt[j+1][i] + (matrix[j+1][i] < matrix[j][i]);
        }
      }
      int ans = 0;
      for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
          if((i == 0 && j == 0) || (i == m-1 && j == n-1) )// top left corner or bottom right
            ans = max(ans, max(tb[i][j] + rl[i][j], bt[i][j] + lr[i][j]));
          else if((i == 0 && j == n-1) || (i == m-1 && j == 0)) // top right corner or bottom left
            ans = max(ans, max(tb[i][j] + lr[i][j], bt[i][j] + rl[i][j]));
          else
            ans = max(ans, max(tb[i][j], bt[i][j]) + max(lr[i][j], rl[i][j]));
        }
      }
      return ans + 1;
    }
};