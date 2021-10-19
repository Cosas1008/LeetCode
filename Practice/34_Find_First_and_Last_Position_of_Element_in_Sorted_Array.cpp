/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/
class Solution {
public:
    // 2-pointer Time O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
            if(nums[i] == nums[j] && nums[i] == target) return {i, j};
            if(nums[i] != target) i++;
            if(nums[j] != target) j--;
        }
        return {-1, -1};
    }
};

// God-like std library part 1

// equal_range will return pair<ForwardIt,ForwardIt>
// note: ForwardIt is the iterator of any type
vector<int> searchRange(vector<int>& nums, int target) {
    auto bounds = equal_range(nums.begin(), nums.end(), target);
    if (bounds.first == bounds.second)
        return {-1, -1};
    return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
}


// God-like std library part 2
vector<int> searchRange(vector<int>& nums, int target) {
    int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lo == nums.size() || nums[lo] != target)
        return {-1, -1};
    int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {lo, hi};
}

