/*
Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
*/
class Solution {
public:
    int shortestWay(string source, string target){
        int cs[26];
        memset(cs, 0x0, sizeof(cs));
        for(char c : source)
            cs[c-'a']++;
        int j = 0, n = source.length();
        int res = 1;
        for(int i = 0;  < target.length(); ++i){
            if(cs[target[i]-'a'] == 0) return -1;
            while(j < n && source[j] != target[i]) j++; // increment when mismatched
            if(j == n){
                j = 0;
                res++;
                i--;
            }
        }
        return res;
    }
}