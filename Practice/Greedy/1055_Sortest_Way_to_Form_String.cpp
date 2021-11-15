/*
Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
*/
class Solution {
public:
    // Greedy
    int shortestWay(string source, string target){
        int sl = source.length(), tl = target.length();
        vector<int> record(26, false);
        for(int i = 0; i < sl; ++i) record[source[i] - 'a'] = true;
        int res = 1, j = 0;
        for(int i = 0; i < tl; ++i){
            if(!record[tl[i]]) return -1; // impossible
            while(j < m && source[j] != target[i]) ++j;
            if(j == m){
                j = -1;
                ++res;
                --i;
            }
            j++;
        }
        return res;
    }
    // Binary Search 
    // time: O(log(m) * n); space: O(m)
    int shortestWay(string source, string target){
        int sl = source.length(), tl = target.length();
        vector<vector<int> > indice(26);
        for (int j = 0; j < sl; ++j) indice[source[j] - 'a'].push_back(j);
        int res = 1, i = 0, j = 0;
        while (i < tl) {
            const vector<int>& idx = indice[target[i] - 'a'];
            if (idx.empty()) return -1;
            auto it = lower_bound(idx.begin(), idx.end(), j);
            if (it == idx.end()) {
                ++res;
                j = 0;
            } else {
                j = *it + 1;
                ++i;
            }
        }
        return res;
    }
};