/*
Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
    // Recursive is TLE even with some optimize technique
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return wb(s, st);
    }
    bool wb(string s, unordered_set<string>& st){
        int len = s.length();
        if(len == 0) return true;
        for(int i = len; i >= 0; i--){
            if(st.count(s.substr(0,i)) != 0 && wb(s.substr(i), st)){
                return true;
            }
        }
        return false;
    }
    // DP Time complexity O(Nlog(N))
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    if(dict.find(word) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};