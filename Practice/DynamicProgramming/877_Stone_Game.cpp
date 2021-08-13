/*
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n+2][n+2];
        memset(dp, 0x0, sizeof(dp));
        for(int size = 1; size <= n; size++){
            for(int i = 0, j = size - 1; j < n; i++, j++){
                int parity = (j + i + n) % 2;
                if(parity == 1) // Alex
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else // Lee
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
            }
        }
        return dp[1][n] > 0;
    }
    // or easier one
    /*
    You can first pick piles[i] or piles[j].
        If you pick piles[i], your result will be piles[i] - dp[i + 1][j]
        If you pick piles[j], your result will be piles[j] - dp[i][j - 1]
    So we get:
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
    We start from smaller subarray and then we use that to calculate bigger subarray.
    */
    bool stoneGame(vector<int>& p){
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) dp[i][i] = p[i];
        for(int d = 1; d < n; d++)
            for(int i = 0; i < n - d; i++)
                dp[i][i+d] = max(p[i] - dp[i+1][i+d], p[i+d] - dp[i][i+d-1]);
        return dp[0][n-1] > 0;
    }
    // Optimize with O(N) space
    bool stoneGame(vector<int>& p){
        vector<int> dp = p;
        for(int d = 1; d < p.size(); d++)
            for(int i = 0; i < p.size(); i++)
                dp[i] = max(p[i] - dp[i+1], p[i+d] - dp[i]);
        return dp[0] > 0;
    }
};
// or return true instead