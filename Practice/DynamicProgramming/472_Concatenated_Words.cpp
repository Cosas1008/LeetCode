class Solution {
public:
    // Method 1 : using Word Break technique
    // TLE Time O(n^2)
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& lh, const string& rh){
            return lh.length() < rh.length();
        });
        unordered_set<string> s;
        vector<string> ans;
        for(string& word : words){
            int n = word.length();
            vector<bool> dp(n+1, false);
            dp[0] = true;
            for(int i = 0; i < n; ++i){
                if(!dp[i]) continue;
                for(int j = i+1; j <= n; ++j){
                    if(j - i < n && s.count(word.substr(i, j-i))) dp[j] = true;
                }
                if(dp[n]){ 
                    ans.push_back(word);
                    break;
                }
            }
            s.insert(word);
        }
        return ans;
    }
    // Method 2: Recursive
    // TLE too
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> set;
        for(string word : words){
            if(dfs(word, set)) 
                ans.push_back(word);
            set.insert(word);
        }
        return ans;
    }
    // Recursive DFS function
    bool dfs(string word, unordered_set<string> set){
        if(set.count(word)) return true;
        for(int i = 1; i <= word.length(); ++i){
            if(set.count(word.substr(0,i)) && dfs(word.substr(i), set))
                return true;
        }
        return false;
    }
};