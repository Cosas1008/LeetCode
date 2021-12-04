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