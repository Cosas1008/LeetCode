/*
Alice and Bob take turns, with Alice starting first. 
On each player's turn, that player can take 1, 2 or 3 stones from the first remaining stones in the row.
*/
class Solution {
public:
    /*
    There are three option for Alice to choose.
        Take A[i], win take - dp[i+1]
        Take A[i] + A[i+1], win take - dp[i+2]
        Take A[i] + A[i+1] + A[i+2], win take - dp[i+3]
    */
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1e9);
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0, take = 0; j < 3 && i + j < n; j++){
                take += stoneValue[i+j];
                dp[i] = max(dp[i], take - (i+j+1 < n? dp[i+j+1] : 0));
            }
        }
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};