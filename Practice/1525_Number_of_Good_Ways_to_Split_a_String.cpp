/*
Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
*/
class Solution {
public:
    int numSplits(string s) {
        int ls[26] = {}, rs[26] = {}, dif_l = 0, dif_r = 0;
        for(char c : s){
            dif_r += ++rs[c-'a'] == 1;
        }
        int ans = 0;
        for(char c : s){
            dif_l += ++ls[c-'a'] == 1;
            dif_r -= --rs[c-'a'] == 0;
            ans += dif_l == dif_r;
        }
        return ans;
    }
};