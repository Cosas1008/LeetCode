class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int min_cost = 0, target = nums[nums.size() / 2];
        for(auto num : nums){
            min_cost += abs(num - target);
        }
        return min_cost;
    }
};