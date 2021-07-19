/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
// Hint : how to prevent duplicate, not like 3Sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 4) return ans;
        sort(nums.begin(), nums.end()); // monotonic increase
        for(int i = 0 ; i < n-3; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            for(int j = i+1; j < n-2; j++)
            {
                if(j > i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break; // max of j included
                if(nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue; // min of all possible
                int left = j+1, right = n-1;
                while(left<right){
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
            
        }
        return ans;
    }
};