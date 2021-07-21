/*
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 3.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n, n);
        int idx = -2*n;
        for(int i = 0; i < n; i++){
            if(s[i] == c){
                idx = i;
            }
            if(i - idx < ans[i]){
                ans[i] = i - idx;
            }
        }
        idx = 2*n;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == c){
                idx = i;
            }
            if(idx - i < ans[i]){
                ans[i] = idx - i;
            }
        }
        return ans;
    }
};

// More concise
vector<int> shortestToChar(string S, char C) {
    int n = S.size(), pos = -n;
    vector<int> res(n, n);
    for (int i = 0; i < n; ++i) {
        if (S[i] == C) pos = i;
        res[i] = i - pos;
    }
    for (int i = pos - 1; i >= 0; --i) {
        if (S[i] == C)  pos = i;
        res[i] = min(res[i], pos - i);
    }
    return res;
}