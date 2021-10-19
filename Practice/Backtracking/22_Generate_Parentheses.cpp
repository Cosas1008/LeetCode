/*
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
n is only 0 to 8
*/
class Solution {
public:
    // Closure Number O(4^n / n^(1/2))
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0)
            ans.push_back("");
        else{
            for(int c = 0; c < n; ++c)
                for(string left: generateParenthesis(c))
                    for(string right : generateParenthesis(n-1-c))
                        ans.push_back("(" + left + ")" + right);
        }
        return ans;
    }
    // backtracking
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string str;
        helper(ans, str, 0, 0, n);
        return ans;
    }
    void helper(vector<string>& ans, string str, int left, int right, int max){
        if(left == max && right == max)
            ans.push_back(str);
        
        if(left > max) return;
        helper(ans, str + '(', left+1, right, max);
        if(left > right)
            helper(ans, str + ')', left, right+1, max);
    }
};