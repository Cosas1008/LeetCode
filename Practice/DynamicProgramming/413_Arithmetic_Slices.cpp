/*
A subarray is a contiguous subsequence of the array.
Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
*/
// backtracking -> TLE
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        helper(nums, 0, 0);
        return ans;
    }
    void helper(vector<int>& nums, int low, int high){
        if(mp[high*n+low]) return;
        if(low > high || high >= n) return;
        // high > low
        if(high - low >= 2){
            bool pass = true;
            int tmp = low, diff, pre = -2001;
            while(pass && tmp < high){
                diff = nums[tmp+1] - nums[tmp];
                tmp++;
                if(pre != -2001 && diff != pre) pass = false;
                pre = diff;
            }
            if(pass){
                // cout << nums[low] << " to " << nums[high] << endl;
                ans++;
            }
        }
        mp[high*n + low]++;
        helper(nums, low+1, high);
        helper(nums, low, high+1);
    }
private:
    int ans;
    int n;
    unordered_map<int,int> mp;
};

// DP
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        vector<int> dp(n, 0);
        if(A[2] - A[1] == A[1] - A[0]) dp[2] = 1;
        int result = dp[2];
        for(int i = 3; i < n; ++i){
            // end with A[i] = end with A[i-1] + A[i-2]
            if(A[i] - A[i-1] == A[i-1] == A[i-2])
                dp[i] = dp[i-1] + 1;
            result += dp[i];
        }
        return result;
    }
    // O(1) space
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        int dp = 0, result = 0;
        for(int i = 2; i < n; ++i){
            // end with A[i] = end with A[i-1] + A[i-2]
            if(A[i] - A[i-1] == A[i-1] - A[i-2])
                ++dp;
            else
                dp = 0;
            result += dp;
        }
        return result;
    }
};
