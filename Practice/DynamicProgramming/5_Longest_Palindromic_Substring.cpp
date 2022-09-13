class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    int dp[n][n];
    memset(dp, 0x0, n*n*sizeof(int));
    int start = 0, len = 1;
    
    // Single letter
    for(int i = 0; i < n; ++i)
      dp[i][i] = 1;
    
    // Double words
    for(int i = 0; i < n-1; ++i){
      if(s[i] == s[i+1]){
        dp[i][i+1] = 1;
        start = i;
        len = 2;
      }
    }
    
    for(int j = 2; j < n; ++j){ // length
      for(int i = 0; i < n - j; ++i){
        int l = i;
        int r = i + j;
        if(dp[l+1][r-1] == 1 && s[l] == s[r]){
          dp[l][r] = 1;
          start = i;
          len = j+1;
        }
      }
    }
    return s.substr(start,len);
  }
};