/*
You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.
*/
class Solution {
public:
    // One pass
    string pushDominoes(string d) {
        int force = 0;
        int n = d.length();
        vector<int> forces(n, 0);
        // left to right
        for(int i = 0; i < n; ++i){
            if(d[i] == 'R') force = n;
            else if(d[i] == 'L') force = 0;
            else force = max(force-1, 0);
            forces[i] += force;
        }
        // right to left
        for(int i = n-1; i >= 0; --i){
            if(d[i] == 'L') force = n;
            else if(d[i] == 'R') force = 0;
            else force = max(force-1, 0);
            forces[i] -= force;
        }
        string ans;
        for(int i = 0; i < n; ++i){
            ans += forces[i] > 0? 'R' : forces[i] < 0? 'L' : '.';
        }
        return ans;
    }
};