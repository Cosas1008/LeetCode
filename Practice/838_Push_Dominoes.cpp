/*
You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.
*/
class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        string ans = "";
        for(int i = 0, j = 1; j < d.length(); ++j){
            if(d[j] == '.') continue;
            int middle = j - i - 1;
            if(i > 0)
                ans += d[i];
            if(d[i] == d[j])
                ans += string(middle, d[i]);
            else if(d[i] == 'L' && d[j] == 'R')
                ans += string(middle, '.');
            else
                ans += string(middle/2, 'R') + string(middle % 2, '.') + string(middle/2, 'L');
            i = j;
        }
        return ans;
    }
};

// Better yet, travel from left-to-right and right-to-left to obtain distance between R and L
for(int i=0; i<n; i++){
    if(!l[i] && !r[i]) ans += s[i];
    else if(!l[i]) ans += 'R';
    else if(!r[i]) ans += 'L';
    else if(l[i] == r[i]) ans += '.';
    else if(l[i] > r[i]) ans += 'R';
    else ans += 'L';
}
// ref: https://leetcode.com/problems/push-dominoes/discuss/787845/O(N)-C%2B%2B-Easy-Solution.-greater90