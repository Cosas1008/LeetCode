/*
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
*/
class Solution {
public:
    // DFS get TLE
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // beginWord, endWord wordList
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> tmp, ans;
        if(dict.count(beginWord) == 0 || dict.count(endWord) == 0) return {};
        dfs(dict, tmp, beginWord, endWord, {beginWord});
        for(auto t : tmp){
            if(t.size() == shortest)
                ans.emplace_back(t);
        }
        return ans;
    }
    void dfs(unordered_set<string> dict, vector<vector<string>>& tmp, string curWord, string endWord, vector<string> path){
        if(dict.empty()) return;
        if(curWord == endWord){
            shortest = min(shortest, (int) path.size());
            tmp.push_back(path);
            return;
        }
        dict.erase(curWord);
        for(int j = 0; j < curWord.size(); ++j){
            char c = curWord[j];
            for(int i = 0; i < 26; ++i){
                curWord[j] = 'a' + i;
                if(dict.count(curWord)){
                    path.push_back(curWord);
                    dfs(dict, tmp, curWord, endWord, path);
                    path.pop_back();
                }
            }
            curWord[j] = c; // reset
        }
    }
private:
    int shortest = 1e5;
};