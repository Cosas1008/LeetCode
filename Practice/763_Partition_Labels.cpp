/*
You are given a string s. We want to partition the string into as many parts as possible
so that each letter appears in at most one part.
Return a list of integers representing the size of these parts.
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.length();
        unordered_map<char, int> m;
        // store last occurance
        for(int i = n - 1; i >= 0; i--){
            if(m.count(s[i]) == 0){
                m[s[i]] = i;
            }
        }
        int front = 0, last = m[s[0]];
        for(int i = 0; i < n; i++){
            if(m[s[i]] > last)
                last = m[s[i]];
            if(last <= i){
                ans.push_back(last - front + 1);
                front = i+1;
            }
        }
        return ans;
    }
    // concise way
    vector<int> partitionLabels(string s) {
        vector<int> res, pos(26, 0);
        int n = s.length();
        for(int i = 0; i < n; i++) pos[s[i] - 'a'] = i;
        for(int i = 0, idx = INT_MIN, last_i = 0; i < n; ++i){
            idx = max(dix, pos[s[i]-'a']);
            if(idx == i) res.push_back(i - exchange(last_i, i+1) + 1);
        }
        return res;
    }
};