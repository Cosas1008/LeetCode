/*
Given an array of strings words, return the smallest string that contains each string in words as a substring. 
If there are multiple valid strings of the smallest length, return any of them.
You may assume that no string in words is a substring of another string in words.

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
        vector<vector<string>> dp(1<<N, vector<string>(N));
        // 1. Find path
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
        // 2. Initialize DP
        for(int i=0; i<N; ++i) dp[1<<i][i] += words[i];
        
        // 3. 
        for(int mask=1; mask<(1<<N); ++mask){
            for(int j=0; j<N; ++j) if((mask&(1<<j))>0){
                for(int i=0; i<N; ++i) if(i!=j && (mask&(1<<i))>0){
                    string tmp = dp[mask^(1<<j)][i]+words[j].substr(path[i][j]);
                    if(dp[mask][j].empty() || tmp.size()<dp[mask][j].size())
                        dp[mask][j] = tmp;
                }
            }
        }
        // 4. get the result
        int last = (1<<N)-1;
        string res = dp[last][0];
        for(int i=1; i<N; ++i) if(dp[last][i].size()<res.size()){
            res = dp[last][i];
        }
        return res;
    }
};