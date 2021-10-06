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

// DP
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;
        int sum = accummulate(nums.begin(), nums.end(), 0);
        int totalSum = sum;
        if(sum % k != 0) return false;
        sum /= k;
        int n = nums.size();
        // vector<bool> dp(1<<n, false);
        vector<int> total(1<<n, -1);
        // dp[0] = true;
        total[0] = 0;
        for(int i = 0; i < (1<<n); i++){
            if(total[i] == -1) continue;
            int rem = sum - (total[i] % sum);
            for(int j = 0; j < n; j++){
                int future = i | (1<<j);
                if(i == future || total[future] >= 0) continue;
                if(total[j] > rem) break;
                total[future] = total[i] + nums[j];
            }
        }
        return total.back() == totalSum;
    }
};