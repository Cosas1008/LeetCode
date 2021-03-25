
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
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2001));
        
        dp[0][1000 + nums[0]]++;
        dp[0][1000 - nums[0]]++;
        for(int i = 1; i < nums.size(); i++){
            for(int sum = -1000; sum < 1001; sum++){
                if(dp[i-1][sum + 1000] > 0){
                    dp[i][sum + nums[i] + 1000] += dp[i-1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i-1][sum + 1000];
                }
            }
        }
        return S > 1000? 0 : dp[nums.size() - 1][S + 1000];
    }
};