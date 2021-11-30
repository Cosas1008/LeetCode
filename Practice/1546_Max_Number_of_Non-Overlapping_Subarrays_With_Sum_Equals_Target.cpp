/*
Return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 2
Output: 2
Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
*/
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sum = 0, cnt = 0, right = -1;
        unordered_map<int,int> dp;
        dp[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(dp.count(sum - target)){
                int left = dp[sum - target];
                if(right <= left){
                    cnt++;
                    right = i;
                }
            }
            dp[sum] = i;
        }
        return cnt;
    }
};