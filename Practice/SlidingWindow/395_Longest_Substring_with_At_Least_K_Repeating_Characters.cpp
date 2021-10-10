/*
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
*/
class Solution {
public:
    // TC : O(N^2)
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n == 0 || k > n) return 0;
        int mp[26], res = 0;
        for(int i = 0; i < n; ++i){
            memset(mp, 0x0, sizeof(mp));
            for(int j = i; j < n; j++){
                mp[s[j]-'a']++;
                if(isValid(k, mp)){
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
private:
    bool isValid(int k, int mp[26]){
        for(int i =0; i < 26; ++i){
            if(mp[i] != 0 && mp[i] < k) return false;
        }
        return true;
    }
};
// Sliding Window O(N)
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, mp[26], n = s.length();
        // get max unique count
        int maxUnique = 0;
        if(k == 1) return n;
        memset(mp, 0x0, sizeof(mp));
        
        for(char c : s){
            maxUnique = max(maxUnique, ++mp[c-'a']);
        }

        for(int currentUnique = 1; currentUnique <= maxUnique; ++currentUnique){
            memset(mp, 0x0, sizeof(mp));
            int unique = 0, windowStart = 0, windowEnd = 0, idx, countAtleastK = 0;
            while(windowEnd < n) {// sliding window from 0 to n-1
                // expend if unique <= currentUnique
                if(unique <= currentUnique){
                    idx = s[windowEnd] - 'a';
                    if(mp[idx]++ == 0) unique++;
                    if(mp[idx] == k) countAtleastK++;
                    windowEnd++;
                } else { // shrink else
                    idx = s[windowStart] - 'a';
                    if(mp[idx]-- == k) countAtleastK--;
                    if(mp[idx] == 0) unique--;
                    windowStart++;
                }
                if(unique == countAtleastK && unique == currentUnique)
                    res = max(res, windowEnd - windowStart);
            }
        }
        return res;
    }
};