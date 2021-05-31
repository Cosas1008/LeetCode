// Use nothing but next_permutation ( begin, end, x<=y)
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
        helper(ans, nums, {});
        return ans;
    }
    void helper(vector<vector<int>>& ans, vector<int> nums, vector<int> choice){
        if(nums.size() == 0){ ans.push_back(choice); return;}
        for(int i = 0; i < nums.size(); i++){
            int tmp = nums[i];
            nums.erase(nums.begin()+i);
            choice.push_back(tmp);
            helper(ans, nums, choice);
            nums.insert(nums.begin()+i, tmp);
            choice.pop_back();
        }
    }
};