/*
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Example 1:

Input: s = "bcabc"
Output: "abc"
*/
class Solution {
public:
    string smallestSubsequence(string s) {
      string ans = "";
      int last[26] = {}, seen[26] = {}, n = s.length();
      for(int i = 0; i < n; ++i)
        last[s[i] - 'a'] = i;
      for(int i = 0; i < n; ++i){
        if(seen[s[i]-'a']++) continue;
        // if the current character is smaller than the last character in the stack,
        // and the last character exists in the following stream,
        while(!ans.empty() && ans.back() > s[i] && last[ans.back()-'a'] > i)
          seen[ans.back()-'a'] = 0, ans.pop_back();
        ans.push_back(s[i]);
      }
      return ans;
    }
};