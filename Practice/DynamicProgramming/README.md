## 943 Find the Shortest Superstring

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