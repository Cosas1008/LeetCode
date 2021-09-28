/*
Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5].
The left row has the value 11 and the right row has value 14. 
Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). 
The game ends because only one stone is remaining in the row.
The game ends when there is only one stone remaining. Alice's is initially zero.
*/
class Solution {
public:
    class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        // make the value as even as possible
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        for(int i = 0; i < n; i++){
            presum[i+1] = presum[i] + stoneValue[i];
        }
        return helper(stoneValue, 0, n-1);
    }
    int helper(vector<int>& S, int i, int j){
        if(i == j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        memo[i][j] = 0;
        for(int p = i + 1; p <= j; p++){
            int l = presum[p] - presum[i];
            int r = presum[j+1] - presum[p];
            if(r > l){
                memo[i][j] = max(memo[i][j], l + helper(S, i, p-1));
            }else if(r < l){
                memo[i][j] = max(memo[i][j], r + helper(S, p, j));
            }else{
                memo[i][j] = max(memo[i][j], l + max(helper(S, i, p-1), helper(S, p, j)));
            }
        }
        return memo[i][j];
    }
private:
    int presum[501];
    int memo[501][501];
};