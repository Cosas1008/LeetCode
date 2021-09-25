/*
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: s = "bcabc"
Output: "abc"
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "0";
        vector<int> dict(256, 0);
        vector<bool> visit(256, false);
        for(char c : s) dict[c]++;
        for(char c : s){
            dict[c]--;
            if(visit[c]) continue;
            while(c < ans.back() && dict[ans.back()]){
                visit[ans.back()] = false;
                ans.pop_back();
            }
            ans += c;
            visit[c] = true;
        }
        return ans.substr(1);
    }
};