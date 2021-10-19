class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        for(int i = 0; i < n; ++i)
            ans += i + '1';
        while(--k)
            next_permutation(ans.begin(),ans.end(),[](int x, int y){return  x<=y ; });
        return ans;
    }
};