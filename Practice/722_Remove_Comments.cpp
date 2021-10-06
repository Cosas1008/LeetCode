// '//' for single line comment, '/* */' for multiple line comment 
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string mcstart = "/*", mcend = "*/", sc = "//";
        vector<string> ans;
        bool isMC = false;
        string str;
        for(string s : source){
            int n = s.length();
            for(int i = 0; i < n; ++i){
                if(!isMC && i + 1 < n && s.substr(i,2) == sc) break;
                else if(isMC && i + 1 < n && s.substr(i,2) == mcend) isMC = false, i++;
                else if(!isMC && i + 1 < n && s.substr(i,2) == mcstart) isMC = true, i++;
                else if(!isMC) str.push_back(s[i]);
            }
            if(!isMC && str.length()) ans.push_back(str), str.clear();
        }
        return ans;
    }
};