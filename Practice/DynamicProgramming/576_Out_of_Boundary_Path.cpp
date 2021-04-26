class Solution {
public:
    // Time Complecity O(4^n), Space O(n)
    int findPaths(int m, int n, int N, int i, int j) {
      if(i == m || j == n || i < 0 || j < 0) return 1;
      if( N == 0) return 0;
      return findPaths(m, n, N - 1, i + 1, j) + findPaths(m, n, N - 1, i - 1, j) + findPaths(m, n, N - 1, i, j - 1) + findPaths(m, n ,N - 1, i, j + 1);
    }

    // Time: O(mnN)
    // Space: O(mn)
    int findPaths(int m, int n, int N, int i, int j) {
        unsigned int dp[2][50][50] = {};
        while (N-- > 0)
        for (int k = 0; k < m; ++k)
            for (int l = 0, nc = (N + 1) % 2, np = N % 2; l < n; ++l)
                dp[nc][k][l] = ((k == 0 ? 1 : dp[np][k - 1][l]) + (k == m - 1 ? 1 : dp[np][k + 1][l])
                        + (l == 0 ? 1 : dp[np][k][l - 1]) + (l == n - 1 ? 1 : dp[np][k][l + 1])) % 1000000007;
        return dp[1][i][j];
    }
};


// Better, (Top-Down)
typedef long long LL;
class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int mod = 1e9 + 7;
    inline int hash(int x, int y, int n) { return 10000 * x + 100 * y + n; }
    unordered_map<int, int> dp;
    int dfs(int m, int n, int N, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (!N) return 0;
        int key = hash(i, j, N);
        if (dp.count(key)) return dp[key];
        LL cnt = 0;
        for (auto &dir : dirs) cnt = (cnt + dfs(m, n, N - 1, i + dir[0], j + dir[1])) % mod;
        return dp[key] = cnt;
    }
public:
    int findPaths(int m, int n, int N, int i, int j) {
        return dfs(m, n, N, i, j);
    }
};

// Button-Up
// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(mnN)
// Space: O(mn)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int mod = 1e9 + 7;
    int findPaths(int m, int n, int N, int x, int y) {
        if (!N) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2)));
        for (int i = 0; i < m; ++i) dp[i][0][1]++, dp[i][n - 1][1]++;
        for (int i = 0; i < n; ++i) dp[0][i][1]++, dp[m - 1][i][1]++;
        int ans = dp[x][y][1];
        for (int k = 2; k <= N; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = 0;
                    for (auto &dir : dirs) {
                        int a = i + dir[0], b = j + dir[1];
                        if (a < 0 || a >= m || b < 0 || b >= n) continue;
                        val = (val + dp[a][b][(k - 1) % 2]) % mod;
                    }
                    dp[i][j][k % 2] = val;
                    if (x == i && y == j) ans = (ans + val) % mod;
                }
            }
        }
        return ans;
    }
};