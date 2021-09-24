/*
There is only one character 'A' on the screen of a notepad. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
*/
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        memset(dp, 0x0, sizeof(dp));
        for(int i = 2; i <= n; i++){
            dp[i] = i;
            for(int j = i / 2; j > 1; j--){
                if(i % j == 0){
                    dp[i] = dp[j] + i/j;
                    break;
                }
            }
        }
        return dp[n];
    }

    // Prime Factorization
    // Time Complexity: O(\sqrt{N})
    int minSteps(int n) {
        int ans = 0, d = 2;
        while(n > 1){
            while(n % d == 0){
                ans += d;
                n   /= d;
            }
            d += 1;
        }
        return ans;
    }
};