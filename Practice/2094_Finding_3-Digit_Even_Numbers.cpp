// Key: permutation
class Solution {
public:
    // DFS get TLE
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> ans;
        dfs(digits, ans, 0);
        vector<int> A(ans.begin(), ans.end());
        sort(A.begin(), A.end());
        return A;
    }
    void dfs(vector<int> digits, unordered_set<int>& ans, int cur){
        if(cur > 999) return;
        if(cur > 99){
            if(cur % 2 == 0)
                ans.insert(cur);
            return;
        }
        for(int i = 0; i < digits.size(); ++i){
            vector<int> tmp(digits);
            int newcur = cur * 10 + digits[i];
            tmp.erase(tmp.begin() + i); // erase pos
            dfs(tmp, ans, newcur);
        }
    }
    // Brute-Force
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        int n = digits.size();
        for(int i = 0; i < n; ++i){
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    if(i == j || j == k || i == k) continue;
                    if(digits[k] % 2) continue;
                    int total = digits[i] * 100 + digits[j] * 10 + digits[k];
                    res.insert(total);
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};