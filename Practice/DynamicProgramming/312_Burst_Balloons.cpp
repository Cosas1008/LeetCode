/*
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.
Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/
class Solution {
public:
    int dp[501][501];
    int maxCoins(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        return dfs(a, 0, a.size()-1);
    }
    int dfs(vector<int>& a, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i; k <= j; ++k){
            long temp = dfs(a, i, k-1) + dfs(a, k+1, j);
            int l = 1, r = 1;
            if(i - 1 >= 0)
                l = a[i-1];
            if(j + 1 < a.size())
                r = a[j+1];
            temp += l * r * a[k];
            dp[i][j] = max(dp[i][j], (int)temp);
        }
        return dp[i][j];
    }
};