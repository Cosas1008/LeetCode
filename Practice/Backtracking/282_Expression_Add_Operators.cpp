class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, 0, "", ans);
        return ans;
    }
    void helper(string& num, int& target, int pos, long cv, long pre, string r, vector<int>& ans)
    {
        if(num.size() == pos && cv == target){
            ans.push_back(r);
            return;
        }
        for(int i = 1; i < num.size() - pos; i++){
            string tmp = num.substr(pos, i);
            if(i > 1 && tmp[0] == '0') continue;
            long n = stol(tmp);
            if(pos == 0){
                helper(num, target, i, n, n, tmp, ans);
                continue;
            }
            helper(num, target, pos+i, cv+n, n, r+"+"+tmp, ans);
            helper(num, target, pos+i, cv-n, -n, r+"-"+tmp, ans);
            helper(num, target, pos+i, cv-pre+pre*n, pre*n, r+"*"+tmp, ans);
        }
    }
};