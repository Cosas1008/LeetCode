// All houses at this place are arranged in a circle.
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin() + 1, nums.end()); // House[2] - House[n]
        vector<int> nums2(nums.begin(), nums.end() - 1); // House[1] - House[n-1]
        return max(rob2(nums2), rob2(nums1));
    }
private:
    int rob2(vector<int>& nums) {
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