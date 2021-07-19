/*
Input: stones = [3,2,4,1], k = 2
Output: 20
Explanation: We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
n == stones.length
1 <= n <= 30
1 <= stones[i] <= 100
2 <= k <= 30
*/
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = (int)stones.size();
        if((n-1) % (K-1)) return -1;
        vector<int> prefix(n+1);
        for(int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + stones[i];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int m = K; m <= n; m++){
            for(int i = 0; i + m <= n; i++){
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k += K-1)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                if((j-i) % (K-1) == 0)
                    dp[i][j] += prefix[j+1] - prefix[i];
            }
        }
        return dp[0][n-1];
    }
};