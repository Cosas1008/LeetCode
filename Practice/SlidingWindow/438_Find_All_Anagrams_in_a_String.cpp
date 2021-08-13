/*
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, pv(26, 0), sv(26, 0);
        int pl = p.length();
        int sl = s.length();
        if(sl < pl) return res;
        for(int i = 0; i < pl; i++){
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        if(pv == sv) res.push_back(0);
        for(int i = pl; i < sl; i++){
            sv[s[i]-'a']++;
            sv[s[i-pl]-'a']--;
            if(sv == pv) res.push_back(i-pl+1);
        }
        return res;
    }
};