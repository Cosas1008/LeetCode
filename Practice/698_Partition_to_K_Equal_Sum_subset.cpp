class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        int size = nums.size();
        vector<bool> used(size, false);
        sum /= k;
        return helper(0, nums, used, k, 0, sum);
    }

private:
    // Backtracting
    bool helper(int start, vector<int>& array, vector<bool>& used, int k, int current, int target)
    {
        if(k == 1) return true;
        if(current > target) return false;
        if(current == target) return helper(0, array, used, k-1, 0, target); // start should be 0 here!
        for(int i = start; i < array.size(); ++i)
        {
            if(used[i]) continue;
            used[i] = true;
            if(helper(i+1, array, used, k, current + array[i], target)) return true;
            used[i] = false;
        }
        return false;
    }
};