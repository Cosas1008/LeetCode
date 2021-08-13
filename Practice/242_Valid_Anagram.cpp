// sorting 76 ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s.compare(t) == 0;
    }
};
// Hash table or int array to store
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> mp;
        int count[26] = {0};
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto c : mp){
            if(c.second) return false;
        }
        return true;
    }
};