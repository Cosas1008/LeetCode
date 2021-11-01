/*
The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing Subsequence and the coresponding number of these sequence which ends with nums[i], respectively. That is:

len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].
*/
class solution {
public:
    int findNumberOfLIS(vector<int>& A){
        int n = A.size(), res = 0, max_len = 0;
        vector<pair<int,int>> dp(n, {1,1}); // len and cnt
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(A[i] > A[j]){
                    if(dp[i].first == dp[j].first + 1)
                        dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1)
                        dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if(max_len == dp[i].first)
                res += dp[i].second;
            if(max_len < dp[i].first){
                max_len = dp[i].first;
                res     = dp[i].second;
            }
        }
        return res;
    }
};