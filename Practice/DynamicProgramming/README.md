# List:
- [x] 10   Regular Expression Matching
- [x] 44   Wildcard Matching
- [x] 312  Burst Balloons
- [x] 1000 Minimum Cost to Merge Stone ( Hard )
- [ ] 1397 Find All Good String ( Hard )
- [x] 1690 Stone Game VII
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

### 943 Find the Shortest Superstring

Classic TSP problem

```java
// start TSP DP
for (int i = 1; i < (1 << n); i++) { // for all the combinations of the nodes
    Arrays.fill(dp[i], Integer.MAX_VALUE); // the length =MAX_VALUE
    for (int j = 0; j < n; j++) { //for each node
        if ((i & (1 << j)) > 0) {      // if the node is in the set. Assume i = 10010(18), j = 100(4), then set={1,4}, the node is 2. The node is not in this set
            int prev = i - (1 << j);      // the set without j. Assume i = 10010, j = 10 then pre = 10000
            if (prev == 0) {            // if j is the only one
                dp[i][j] = A[j].length();  // the whole word
            } else {
                for (int k = 0; k < n; k++) {    //try all the possible nodes before j
                    if (dp[prev][k] < Integer.MAX_VALUE && dp[prev][k] + graph[k][j] < dp[i][j]) { // if k is valid and the length could be reduced
                        dp[i][j] = dp[prev][k] + graph[k][j];   //update the result
                        path[i][j] = k; // update the node before j
                    }
                }
            }
        }
        if (i == (1 << n) - 1 && dp[i][j] < min) {  // if i == 11...1111 means the node set contains all the nodes, and the length is smaller
            min = dp[i][j];  //update the result
            last = j;   //update the last node
        }
    }
}
```

Longest Common Subsequence

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
