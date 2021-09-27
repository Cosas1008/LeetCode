/*
You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents
the number of points at position (r, c) on the matrix. 
Two robots are playing a game on this matrix.
Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
*/
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topAcc = accumulate(grid[0].begin(), grid[0].end(), 0ll), botAcc = 0;
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            topAcc -= grid[0][i];
            ans = min(ans, max(topAcc, botAcc));
            botAcc += grid[1][i];
        }
        return ans;
    }
};