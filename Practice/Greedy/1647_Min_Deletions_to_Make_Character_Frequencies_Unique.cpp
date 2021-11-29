// A string s is called good if there are no two different characters in s that have the same frequency.
class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        unordered_set<int> used;
        int res = 0;
        for(char c : s){
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
            for (; freq[i] > 0 && !used.insert(freq[i]).second; --freq[i])
                ++res;
        return res;
    }
};