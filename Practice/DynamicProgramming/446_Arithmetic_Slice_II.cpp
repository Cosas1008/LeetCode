/*
For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
return the number of all the arithmetic subsequences of nums.
Not Consecutive
*/
// DP
// for each index, i = 0 ... n / j = 0 .. i find the difference for index(i) and index(j) -> store to dp[i][dif]
// if found same diff -> add dp[j][dif] to dp[i][dif] and add dp[i][dif] to res
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<int,int>> dp(n); // [index, [difference, count]]
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if((long) A[i] - (long)A[j] > INT_MAX || (long) A[i] - (long)A[j] < INT_MIN) continue; // ignore OOR
                int dif = A[i] - A[j];
                dp[i][dif] += 1;
                if(dp[j].find(dif) != dp[j].end()){
                    dp[i][dif] += dp[j][dif];
                    res += dp[j][dif];
                }
            }
        }
        return res;
    }
};