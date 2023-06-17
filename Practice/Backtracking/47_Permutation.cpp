/*
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
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
    for(int k = i; k < j; k++){ // should be k = i + 1?
      if(i != k && nums[i] == nums[k]) continue;
      swap(nums[i], nums[k]);
      helper(nums, i + 1, j, ret);
    }
  }
};


class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &A) {
    int n = A.size();
    if(n <= 1) return A;
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    recursion(A, 0, n, res);
    return res;
  }
private:
  void recursion(vector<int> num, int i, int n, vector<vector<int> > &res) {
    if (i == n-1) {
      res.push_back(num);
      return;
    }
    for (int j = i; j < n; j++) {
      if (i != j && num[i] == num[j]) continue;
      swap(num[i], num[j]);
      recursion(num, i+1, n, res);
    }
  }
};