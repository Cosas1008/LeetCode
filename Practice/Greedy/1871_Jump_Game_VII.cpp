class Solution {
public:
    bool canReach(string s, int minJump, int maxJump, int start = 0) {
        vector<bool> dp(s.length()+1, false);
        if(s[0] == '1') return false;
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = minJump; j <= maxJump; j++){
                if(j == 0) continue;
                if(i - j > 0 && s[i-j-1] == '0' || (i == j && s[i-1] == '0')){
                    dp[i] = dp[i] || dp[i-j];
                }
            }
        }
        return dp[s.length()];
    }
};

// SlidingWindow
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump, int start = 0) {
        int n = s.size();
        int pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < n; i++){
            if(i >= minJump){
                pre += dp[i - minJump];
            }
            if(i > maxJump){
                pre -= dp[i - maxJump - 1];
            }
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n-1];
    }
};