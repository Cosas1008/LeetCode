/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; ++i){
            prefix[i] = nums[i] + (prefix[i-1] > 0? prefix[i-1] : 0);
            res = max(res, prefix[i]);
        }
        return res;
    }
};