/*
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] 
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, n = nums.size(), res = n + 1;
        for(int j = 0; j < n; j++){
            target -= nums[j];
            while(target <= 0){
                res = min(res, j - i + 1);
                target += nums[i++];
            }
        }
        return res % (n + 1);
    }
};