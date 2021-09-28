/*
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
1 <= n <= 200
*/
class Solution {
public:
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1, INT_MAX));
        return getAmount(0, n);
    }
    int getAmount(int i, int j){
        if(i >= j)
            return 0;
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        for(int k = i; k <= j; ++k){
            dp[i][j] = min(dp[i][j],
                max(getAmount(i, k-1), getAmount(k+1, j)) + k);
        }
        return dp[i][j];
    }
private:
    vector<vector<int>> dp;
};