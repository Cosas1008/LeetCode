/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false)); // key here
        vector<int> minCuts(n+1); // store each minCuts
        for(int i = 0; i <= n; ++i) minCuts[i] = i-1;
        for(int j = 0; j < n; ++j){
            for(int i = j; i >= 0; --i){
                if(s[i] == s[j] && ((j-i < 2) || isPalin[i+1][j-1])){
                    isPalin[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], minCuts[i]+1);
                }
            }
        }
        return minCuts[n];
    }
};