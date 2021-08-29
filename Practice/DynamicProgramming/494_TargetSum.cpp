
/*
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/
// Brute-Force
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        calculate(nums, 0, 0, S);
        return count;
    }
private:
    int count;
    void calculate(vector<int>& nums, int i, int num, int S){
        if(i == nums.size()){
            if(num == S){
                count++;
            }
        }else{
            calculate(nums, i+1, num + nums[i], S);
            calculate(nums, i+1, num - nums[i], S);
        }
    }
};

// Dynamic-Programming
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n+1][2001];
        memset(dp, 0, sizeof(dp));
        dp[0][1000 + nums[0]]++;
        dp[0][1000 - nums[0]]++;
        for(int i = 1; i < n; i++){
            for(int sum = -1000; sum < 1001; sum++){
                if(dp[i-1][sum + 1000] > 0){
                    dp[i][sum + nums[i] + 1000] += dp[i-1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i-1][sum + 1000];
                }
            }
        }
        return target > 1000? 0 : dp[n-1][target+1000];
    }
};