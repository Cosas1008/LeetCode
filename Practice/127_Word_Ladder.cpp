/*
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/
// BFS find the shortest path
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while(todo.size()){
            int n = todo.size();
            for(int i = 0; i < n; ++i){
                string word = todo.front(); todo.pop();
                if(word == endWord) return ladder;
                dict.erase(word);
                for(int j = 0; j < word.size(); ++j){
                    char c = word[j];
                    for(int k = 0; k < 26; ++k){
                        word[j] = 'a' + k;
                        if(dict.find(word) != dict.end())
                            todo.push(word);
                    }
                    word[j] = c; // reset
                }
            }
            ladder++;
        }
        return 0;
    }
};
// DFS get TLE
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ans = INT_MAX;
        helper(beginWord, endWord, wordList, 1);
        return ans == INT_MAX? 0 : ans;
    }
private:
    void helper(string B, string E, vector<string>& wordList, int cur){
        if(B == E){
            ans = min(ans, cur);
            return;
        }
        // cout << B << endl;
        for(int i = 0; i < wordList.size(); ++i){
            if(dist(B, wordList[i])){
                vector<string> wordList2(wordList.begin(), wordList.end());
                wordList2.erase(wordList2.begin() + i);
                helper(wordList[i], E, wordList2, cur+1);
            }
        }
    }
    bool dist(string A, string B){
        int difcnt = 0;
        if(A.length() != B.length()) return false;
        for(int i = 0; i < A.length(); ++i){
            if(A[i] != B[i]) difcnt++;
        }
        return difcnt == 1;
    }
    int ans;
};