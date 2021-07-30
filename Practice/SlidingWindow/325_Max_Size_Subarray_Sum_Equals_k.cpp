/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. 
If there isn't one, return 0 instead.
array nums contains negative values
*/
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, ret = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k) ret = i + 1;
            else if(mp.count(sum - k)) ret = max(ret, i - mp[sum-k]);
            if(!mp.count(sum)) mp[sum] = i;
        }
        return ret;
    }
};