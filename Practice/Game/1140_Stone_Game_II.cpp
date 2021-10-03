/*
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, 
then Alice takes 2 piles again. 
Alice can get 2 + 4 + 4 = 10 piles in total. 
If Alice takes two piles at the beginning, then Bob can take all three piles left. 
In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
On each player's turn, that player can take all the stones in the first X remaining piles,
where 1 <= X <= 2M.  Then, we set M = max(M, X).

*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> presum(n+1, 0);
        for(int i = n-1; i >= 0; i--)
            presum[i] += presum[i+1] + piles[i];
        return dfs(dp, 1, 0, presum);
    }
    int dfs(vector<vector<int>>& dp, int M, int pos, vector<int>& presum){
        if(pos + 2*M >= presum.size() - 1) return presum[pos];
        int res = 0;
        for(int i = 1; i <= 2*M; i++){
            int s = presum[pos] - presum[i + pos];
            if(dp[i + pos][max(i, M)] == 0)
                dp[i + pos][max(i, M)] = dfs(dp, max(i,M), i+pos, presum);
            res = max(res, s + presum[i + pos] - dp[i + pos][max(i,M)]);
        }
        return res;
    }
};