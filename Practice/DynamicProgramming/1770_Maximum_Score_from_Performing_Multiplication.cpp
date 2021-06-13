/*
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
*/
class Solution {
public:
    int dfs(vector<int> &nums, vector<int> &multipliers, int start, int i){
        if (i >= multipliers.size()){
            return 0; // return if all num are added
        }
        if (!dp[start][i]){
            int end = nums.size() - 1 - (i - start);
            dp[start][i] = max(
                nums[start] * multipliers[i] + dfs(nums, multipliers, start + 1, i + 1), 
                nums[end] * multipliers[i] + dfs(nums, multipliers, start, i + 1));
        }
        return dp[start][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return dfs(nums, multipliers, 0, 0);
    }
private:
    int dp[1001][1001];
};