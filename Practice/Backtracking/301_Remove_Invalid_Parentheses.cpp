/*
Input: s = "()())()"
Output: ["(())()","()()()"]
*/

// TLE on "((((((((((((((((((((aaaaa"
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if(s.find_first_of(')') == s.end() || s.find_first_of('(') == s.end()) return "";
        unordered_set<string> ans;
        int l = 0;
        int r = 0;
        for(auto c : s) {
            if(c == '(') {
                ++l;
            }
            if(c == ')') {
                if(l != 0) {
                    --l;
                }
                else {
                    ++r;
                }
            }
        }
        helper(s, 0, l, r, 0, "", ans);
        return vector<string>(ans.begin(), ans.end());
    }
private:
    // l and r indicate '(' and ')' 
    // pair +1 <=> '(' and pair -1 <=> ')' , therefore, pair == 0 means no remains
    void helper(string s, int i, int l, int r, int pair, string path, unordered_set<string>& result) {
        if(i == s.size()) {
            if(l == 0 && r == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        if(s[i] != '(' && s[i] != ')') {
            helper(s, i + 1, l, r, pair, path + s[i], result);
        }
        else {
            if(s[i] == '(') {
                if(l > 0)
                    helper(s, i + 1, l - 1, r, pair, path, result);
                helper(s, i + 1, l, r, pair + 1, path + s[i], result);
            }
            if(s[i] == ')') {
                if(r > 0)
                    helper(s, i + 1, l, r - 1, pair, path, result);
                if(pair > 0)
                    helper(s, i + 1, l, r, pair - 1, path + s[i], result);
            }
        }
    }
};

// DFS solution (TODO read it)
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        helper(s, 0, 0, 0);
        return ans;
    }
private:
    vector<string> ans;
    string p={'(',')'};
    void helper(string& s, int si, int sj, int rev){
        int stackn=0;
        for(int i = si; i < s.size(); i++){
            if(s[i]==p[rev]) stackn++;
            else if(s[i]==p[1-rev]) stackn--;
            if(stackn < 0){
                for(int j=sj;j<=i;j++){
                    if(s[j]==p[1-rev] && (j==sj || s[j-1]!=p[1-rev])){
                        string t=s.substr(0,j) + s.substr(j+1);
                        helper(t, i, j, rev);
                    }
                }
                return;
            }
        }
        string rs = s;
        reverse(rs.begin(), rs.end());
        if(p[rev]=='('){
            helper(rs, 0, 0, 1-rev);
        }else{
            ans.push_back(rs);
        }
    }
};