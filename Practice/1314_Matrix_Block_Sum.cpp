/*
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
*/
// ref: https://leetcode.com/problems/matrix-block-sum/discuss/477041/Java-Prefix-sum-with-Picture-explain-Clean-code-O(m*n)
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1));
        for(int r = 1; r <= m; r++){
            for(int c = 1; c <= n; c++){
                sum[r][c] = mat[r-1][c-1] + sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                int r1 = max(0, r-k), c1 = max(0, c-k);
                int r2 = min(m-1, r+k), c2 = min(n-1, c+k);
                ++r1; ++r2; ++c1; ++c2;
                ans[r][c] = sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
            }
        }
        return ans;
    }
};