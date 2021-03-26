class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if( digits.size() == 0) return {};
        vector<string> ans;
        const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
        ans.push_back("");
        for(int i = 0; i < digits.size(); i++)
        {
            vector<string> tmp;
            for(auto charact : pad[digits[i] - '0']){
                for(int j = 0; j < ans.size(); j++){
                    tmp.push_back(ans[j] + charact);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};