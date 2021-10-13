# List:

- [x] 44   Wildcard Matching
- [x] 62   Unique Paths
- [x] 63   Unique Paths II
- [x] 85   Max Rectangle ( smart )
- [x] 91   Decode Ways
- [x] 115  Distinct Subsequence ( smart )
- [x] 123  Best Time to Buy and Sell Stock III
- [x] 139  Word Break
- [x] 140  Word Break II 
- [x] 198  House Robber
- [x] 213  House Robber II
- [x] 221  Max Square
- [x] 279  Perfect Square
- [x] 300  Longest Increasing Subsequence
- [x] 312  Burst Balloons
- [x] 337  House Robber III
- [x] 322  Coins Change ( Classic DP )
- [x] 416  Partition Equal Subset.cpp
- [x] 494  Target Sum
- [x] 518  Coins Change 2
- [x] 546  Remove Boxes ( Easily TLE, Hard )
- [x] 639  Decode Ways II 
- [x] 647  Palindromic Substrings ( need to practice again)
- [x] 718  Max Length of Repeated Subarray
- [ ] 730  Count Different Palindromic Subsequences
- [x] 740  Delete and Earn
- [x] 746  Min Cost Climbing Stairs
- [x] 871  Min number of Refueling Stops
- [x] 1000 Minimum Cost to Merge Stone ( Hard )
- [x] 1049 Last Stone Weight II ( 0-1 Knapsacks DP )
- [x] 1187 Make Array Strictly Increasing ( Hard )
- [x] 1235 Max Profit in Job Scheduling ( Hard )
- [x] 1239 Max Length of a Concatenated String with Unique Characters ( bitset )
- [x] 1335 Min Difficulty of a Job Schedule
- [ ] 1397 Find All Good String ( Hard )
- [x] 1654 Min Jumps to Reach Home
- [x] 1770 Maximum Score from Performing Multiplication Operation
- [x] 1723 Find Min Time to Finish All Jobs
- [x] 1986 Min Number of Work Session to Finish the Tasks ( Masked BIT DP)


### 44 Wildcard Matching

This can also solved by [greedy](https://leetcode.com/problems/wildcard-matching/discuss/17888/Simple-greedy-Python-with-regexes)


### 85 & 221 Maximum Rectangle/Square

Worth a try

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

### 416. Partition Equal Subset

This technique using for loop from target to 0 is geneous

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