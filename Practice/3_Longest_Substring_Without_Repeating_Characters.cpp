/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;        
        int i = 0, j = 0, n = s.length(), ans = 0;
        while(i < n && j < n){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j++]);
                ans = max(ans, j - i);
            }else{
                set.erase(s[i++]);
            }
        }
        return ans;
    }
};