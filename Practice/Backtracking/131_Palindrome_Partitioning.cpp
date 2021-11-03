/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.
Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> par;
        dfs(s, 0, ans, par);
        return ans;
    }
    void dfs(string& s, int start, vector<vector<string>>& ans, vector<string> par){
        if(start == s.length())
            ans.push_back(par);
        else{
            for(int i = start; i < s.length(); ++i){
                if(isPalin(s, start, i)){
                    par.push_back(s.substr(start, i - start + 1));
                    dfs(s, i+1, ans, par);
                    par.pop_back();
                }
            }
        }
    }
    bool isPalin(string& s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};