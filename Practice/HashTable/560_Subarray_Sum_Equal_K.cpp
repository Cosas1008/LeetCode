/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/
class Solution {
public:
    // Time Complexity : O(N^2) Failed: TLE
    int subarraySum(vector<int>& nums, int k) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == k)
                count++;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] - nums[i] == k){
                    count++;
                }
            }
        }
        return count;
    }
    // Better
    // Time Complexity O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        hash[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(hash.find(sum-k) != hash.end()){
                count += hash[sum-k];
            }
            hash[sum] += 1;
        }
        return count;
    }
};