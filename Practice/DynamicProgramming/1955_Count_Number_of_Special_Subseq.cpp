class Solution {
public:
    // dp[num] as the number of special subsequences ending with num
    // and pre[num+1] as the sum of dp[num]
    int countSpecialSubsequences(vector<int>& A) {
        constexpr int Mod = 1e9 + 7;
        long long dp[3] = {0}, pre[4] = 0;
        pre[0] = 1;
        for(int a : A){
            dp[a] = (pre[a] + pre[a+1]) % Mod;
            pre[a+1] = (pre[a+1] + dp[a]) % Mod;
        }
        return pre[3];
    }
    // Method 2:
    // dp[0] means the number of special sequence of 0.
    // dp[1] means the number of special sequence of 0,1.
    // dp[2] means the number of special sequence 0,1,2.
    int countSpecialSubsequences(vector<int>& A) {
        vector<int> dp(3, 0);
        int mod = 1e9 + 7;
        for(int& a : A){
            dp[a] = ((dp[a] + dp[a]) % mod + (a > 0 ?  dp[a-1] : 1)) % mod;
        }
        return dp[2];
    }
    
};