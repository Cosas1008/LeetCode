/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

Hint: Longest Increasing Subsequence
*/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int dp[n];
        memset(dp, 0x0, n);
        vector<int> lds, lis; // longest increasing/desreasing subsequence
        
        for(int i = 0; i < n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            if(it == lis.end()){
                lis.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
            dp[i] = lis.size();
        }
        
        for(int i = n-1; i >= 0; i--){
            auto it = lower_bound(lds.begin(), lds.end(), nums[i]);
            if(it == lds.end()){
                lds.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
            if(dp[i] > 1 && lds.size() > 1)
            ans = max(ans, dp[i] + (int)lds.size() - 1);
        }
        
        return n - ans;
    }
};