class TrieNode {
public:
    bool    is_word;
    TrieNode *child[26];
    TrieNode (){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        is_word = false;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* trie = new TrieNode();
        vector<vector<string>> ans;
        int k = 0;
        TrieNode* cur;
        // Insert Product
        for(auto product : products){
            cur = trie;
            for(char c : product){
                k = c - 'a';
                if(cur->child[k] == NULL){
                    cur->child[k] = new TrieNode();
                }
                cur = cur->child[k];
            }
            cur->is_word = true;
        }
        // Search Product
        string prefix;
        for(char &c : searchWord){
            prefix += c;
            cout << prefix << endl;
            ans.push_back(search(trie, prefix));
        }
        return ans;
    }
private:
    void dfs(string prefix, TrieNode* rt, vector<string>& result){
        if(result.size() == 3) return;
        if(rt->is_word) result.push_back(prefix);
        for(int i = 0; i < 26; i++){
            if(rt->child[i]){
                // cout << "DFS: " << prefix + (char)('a' + i) << endl;
                dfs(prefix + (char)('a' + i), rt->child[i], result);
            }
        }
    }
    vector<string> search(TrieNode* rt, string& prefix){
        vector<string> result;
        for(char& c : prefix){
            int idx = c - 'a';
            if(!rt->child[idx])
                return {};
            rt = rt->child[idx];
        }
        dfs(prefix, rt, result);
        return result;
    }
};