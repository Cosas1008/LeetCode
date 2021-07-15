/*
The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. 
For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.
*/
typedef long long int64;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int64>> dp(n+1, vector<int64>(2, 0));
        // all the max (evne indexed items sum - odd indexed items sum)
        dp[0][1] = 0;
        dp[0][0] = INT_MIN;
        for(int i = 0; i < n; i++){
            dp[i+1] = dp[i];
            helper(dp[i+1][1],dp[i][0] - nums[i]);
            helper(dp[i+1][0],dp[i][1] + nums[i]);
        }
        int64 ret = max(dp[n][0], dp[n][1]);
        return ret;
    }
    void helper(int64& a, int64 b){
        a = max(a, b);
    }
};

// Same as 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int64 ret = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ret += max(nums[i] - nums[i-1] , 0);
        }
        return ret;
    }
};