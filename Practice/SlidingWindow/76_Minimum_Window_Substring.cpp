/*
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        for(char c : t){
            mp[c]++;
        }
        int cnt = t.length();
        int begin = 0, end = 0, head = 0, dist = INT_MAX;
        while(end < s.length()){
            if(mp[s[end++]]-- > 0) cnt--;
            while(cnt == 0){
                if(end - begin < dist){
                    dist = end - begin;
                    head = begin;
                }
                if(mp[s[begin++]]++ == 0) cnt++;
            }
        }
        return (dist == INT_MAX)? "" : s.substr(head,dist);
    }
};