/*
Given an integer array nums, return all the different possible increasing subsequences of the given array with at least two elements. 
You may return the answer in any order.
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> seq;
        helper(nums, seq, ret, 0);
        return ret;
    }
private:
    void helper(vector<int>& nums, vector<int> seq, vector<vector<int>>& ret, int pos){
        if(seq.size() > 1) ret.push_back(seq);
        unordered_set<int> hash; // Avoid repeated number at same level
        for(int i = pos; i < nums.size(); ++i){
            if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
                seq.push_back(nums[i]);
                helper(nums, seq, ret, i+1);
                seq.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};