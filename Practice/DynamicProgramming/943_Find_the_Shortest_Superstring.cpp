/*
Example 1:

Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.

Example 2:
Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
// TSP problem according to https://leetcode.com/problems/find-the-shortest-superstring/discuss/194932/Travelling-Salesman-Problem
1. graph[i][j] means the length of string to append when A[i] followed by A[j]. eg. A[i] = abcd, A[j] = bcde, then graph[i][j] = 1
2. Then the problem becomes to: find the shortest path in this graph which visits every node exactly once. This is a Travelling Salesman Problem.
3. Apply TSP DP solution. Remember to record the path.
*/
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int N = words.size();
        vector<vector<int>> path(N, vector<int>(N, 0));
        vector<vector<int>> dp(1<<N, vector<int>(N, -1));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == j) continue;
                for(int k = 0; k < words[i].length(); k++) {
                    if(words[j].find(words[i].substr(k)) == 0) {
                        path[i][j] = words[i].length()-k;
                        break;
                    }
                }
            }
        }
        
        for(int i = 0; i < N; i++) dp[1<<i][i] = 0;

        int last = -1, total = -1;
        for(int mask = 0; mask < (1 << N); mask++) {
            for(int i = 0; i < N; i++) {
                if(((mask >> i)&1) == 0) continue;
                int pmask = mask ^ (1 << i);
                for(int j = 0; j < N; j++) {
                    if((pmask >> j)&1 == 0) continue;
                    
                    if(dp[pmask][j] != -1 && dp[mask][i] < dp[pmask][j] + dist[j][i]) {
                        dp[mask][i] = dp[pmask][j] + dist[j][i];
                        parent[mask][i] = j;
                    }
                }
                
                if(mask == (1 << N)-1 && dp[mask][i] > total) {
                    total = dp[mask][i];
                    last = i;
                }
            }
        }
    }
};