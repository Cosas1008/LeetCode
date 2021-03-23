class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    helper(nums, 0, nums.size(), ret);
    return ret;
  }
private:
  void helper(vector<int> nums, int i, int j, vector<vector<int>>& ret)
  {
    if(i == j - 1){
      ret.push_back(nums);
      return;
    }
    for(int k = i; k < j; k++){
      if(i != k && nums[i] == nums[k]) continue;
      swap(nums[i], nums[k]);
      helper(nums, i + 1, j, ret);
    }
  }
};