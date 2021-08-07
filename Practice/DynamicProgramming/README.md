# List:
- [x] 10   Regular Expression Matching
- [x] 44   Wildcard Matching
- [x] 139  Word Break
- [x] 140  Word Break II 
- [x] 312  Burst Balloons
- [x] 494  Target Sum
- [x] 647  Palindromic Substrings ( need to practice again)
- [x] 718  Max Length of Repeated Subarray
- [x] 877  Stone Game
- [x] 1000 Minimum Cost to Merge Stone ( Hard )
- [ ] 1397 Find All Good String ( Hard )
- [x] 1473 Paint House III ( need to use recursive to solve this )
- [x] 1770 Maximum Score from Performing Multiplication Operation

### 44 Wildcard Matching

This can also solved by [greedy](https://leetcode.com/problems/wildcard-matching/discuss/17888/Simple-greedy-Python-with-regexes)
### 213 House Robber
Rob house without two adjacent housess

```cpp
int rob_house(vector<int>& house){
    int total = 0;
    int n = house.size();
    if(n == 0) return 0;
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = house[0];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + house[i-1]);
    }
    return dp[n];
}
```
### 718 Max Length of Repeated Subarray

nums1 and nums2
> Hint:  reverse for

### 943 Find the Shortest Superstring

> 6/1, 8/3 redo    

### Longest Common Subsequence

![LCS](https://assets.leetcode.com/users/votrubac/image_1564691262.png)

- [x] 516 Longest Palindrome Subsequence
- [x] 1143 Longest Common Subsequence
- [x] 1312 Min Insertion to make Palindrome

harder
- [x] 1092 Shortest Common Subsequence ( from back to front )


```cpp
int longestPalindromeSubseq(string s) {
    int n = s.length();
    int dp[n+1][n+1];
    memset(dp, 0x0, sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i+1][j+1] = (s[i] == s[n-1-j])? dp[i][j] + 1 : max(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[n][n];
}
```

### Stone Game
- [x] 877  Stone Game
- [ ] 1140 Stone Game II
- [x] 1406 Stone Game III
- [ ] 1563 Stone Game V
- [ ] 1686 Stone Game VI
- [x] 1690 Stone Game VII
- [ ] 1872 Stone Game VIII