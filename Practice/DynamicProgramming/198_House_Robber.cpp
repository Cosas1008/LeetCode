// Time Complexity O(2^n)
class Solution {
public:
    int rob(vector<int>& nums) {
        return max(nums[0] + helper(nums, 2), helper(nums, 1));
    }
private:
    int helper(vector<int>& nums, int idx)
    {
        if(idx < nums.size()){
            return max( nums[idx] + helper(nums, idx+2), helper(nums, idx+1));
        }else{
            return 0;
        }
    }
};

// Botton-Up with mem (TLE)
// Time Complexity O(2^n)
class Solution {
public:
    int rob(vector<int>& nums) {
        return rob(nums, nums.size() - 1);
    }
private:
    unordered_map<int, int> mem;
    int rob(vector<int>& nums, int idx){
        if( idx < 0){
            return 0;
        }
        if(mem[idx] > 0){
            return mem[idx];
        }
        mem[idx] = max(nums[idx] + rob(nums, idx - 2), rob(nums, idx - 1));
        return mem[idx];
    }
};

// DP
// Time Complexity O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2 ; i <= nums.size(); i++){
            dp[i] = max(dp[i - 1], nums[i-1] + dp[i-2]);
        }
        return dp[nums.size()];
    }
};