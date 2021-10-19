// Use nothing but next_permutation ( begin, end, x<=y)
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      std::sort(nums.begin(),nums.end());  
      vector<vector<int>>result;
        result.push_back(nums);
        auto comp = [](int x, int y){return  x<=y ; };
        while(std::next_permutation(nums.begin(),nums.end(),comp) != false)
             result.push_back(nums);
        return result;
    }
};

// Backtracking Version
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans, nums, 0);
        return ans;
    }
    void helper(vector<vector<int>>& ans, vector<int> nums, int begin){
        if(begin >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++){
            swap(nums[begin], nums[i]);
            helper(ans, nums, begin+1);
            swap(nums[begin], nums[i]); // reverse
        }
    }
};