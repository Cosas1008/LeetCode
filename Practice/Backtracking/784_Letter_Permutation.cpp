class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        helper(S, 0, ans);
        return ans;
    }
    void helper(string& S, int index, vector<string>& ans)
    {
        if(index == S.size()){
            ans.push_back(S);
            return;
        }
        
        helper(S, index+1, ans);
        
        if(isalpha(S[index])){
            S[index] ^= (1<<5);
            helper(S, index+1, ans);
        }
    }
};