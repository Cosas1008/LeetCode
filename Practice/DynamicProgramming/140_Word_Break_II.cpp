/*
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
*/
class Solution {
public:
    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s)) return m[s];
        vector<string> res;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if(dict.count(s)) res.push_back(s);
        for(int i = 1; i < s.length(); ++i){
            string word = s.substr(i); // from i to end
            if(dict.count(word)){
                string rem = s.substr(0,i);
                vector<string> prev = combine(word, wordBreak(rem, wordDict));
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        m[s] = res;
        return res;
    }
private:
    unordered_map<string, vector<string>> m;
};