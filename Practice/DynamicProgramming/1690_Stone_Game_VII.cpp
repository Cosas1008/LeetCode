/*
Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.

Maximize Diff

On each player's turn, they can remove either 
    the leftmost stone 
or 
    the rightmost stone 
from the row and receive points equal to the sum of the remaining stones' values in the row.

DP
*/
class Solution {
public:
    int dfs(vector<int>& stones, int i, int j, int sum){
        if(i == j) return 0;
        return dp[i][j]? dp[i][j] : dp[i][j] = max(sum - stones[i] - dfs(stones, i+1, j, sum - stones[i]), sum - stones[j] -dfs(stones, i, j-1, sum - stones[j]));
    }
    int stoneGameVII(vector<int>& stones) {
        return dfs(stones, 0, stones.size()-1, accumulate(stones.begin(), stones.end(), 0));
    }
private:
    int dp[1001][1001];
};