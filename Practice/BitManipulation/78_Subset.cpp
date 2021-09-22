/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> sub(p);
        for(int i = 0; i < p; i++){
            for(int j = 0; j < n; j++){
                if( (i >> j) & 1)
                    sub[i].push_back(nums[j]);
            }
        }
        return sub;
    }
};