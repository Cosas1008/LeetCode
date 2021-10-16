// A subarray is a contiguous subsequence of the array.
// Solution 0 : if not continuous
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= nums.size(); ++i)
            for(int j = 0; j < i; ++j)
                dp[i] = max(dp[i-1] * nums[i-1], dp[j]);
        return dp[n];
    }
};
/*
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for(int i = 0; i < n; ++i){
            l = (l ? l : 1) * A[i];
            r = (r ? r : 1) * A[n-i-1];
            res = max(res, max(l, r));
        }
        return res;
    }
};