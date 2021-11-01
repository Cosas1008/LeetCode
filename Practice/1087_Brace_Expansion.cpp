/*
For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].
* 1 <= S.length <= 50
* There are no nested curly brackets.
* All characters inside a pair of consecutive opening and ending curly brackets are different.
*/
class Solution {
public:
    vector<string> expand(string s){
        vector<string> res;
        int i = 0, n = s.length();
        while(i < n){
            vector<string> A;
            if(s[i] == '{'){
                while(i < n && s[i] != '}'){
                    string t;
                    while(i < n && s[i] != ',' && s[i] != '}')
                        t.push_back(s[i++]);
                    if(s[i] == ',') i++;
                    A.push_back(t);
                }
            }else{
                string t;
                while(i < n && s[i] != ',' && s[i] != '{' && s[i] != '}') i++;
                    t.push_back(s[i++]);
                A.push_back(t);
            }
            if(res.empty())
                swap(res, A);
            else{
                vector<string> B;
                for(string& i : res)
                    for(string& j : A)
                        B.push_back(i+j);
                swap(B, res);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
}