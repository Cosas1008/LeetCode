/*
Each word must be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

1 <= m, n <= 12
1 <= words.length <= 3 * 10^4

Hint: Trie
*/

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26]; // child
        string word;
        TrieNode() : word(""){
            for(int i = 0; i < 26; ++i)
                child[i] = nullptr; // initialized
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> ans;
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                dfs(board, i, j, root, ans); // Iterate from all i and j
        return ans;
    }

    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        TrieNode* cur;
        int idx;
        for(string& word : words){
            cur = root;
            for(char c : word){
                idx = c-'a';
                if(cur->child[idx] == nullptr)
                    cur->child[idx] = new TrieNode();
                cur = cur->child[idx];
            }
            cur->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& ans){
        if(i < 0 || j < 0 || i == m || j == n) return;
        char c = board[i][j];
        int  k = c-'a';
        if(c == '#' || !root->child[k]) return;
        root = root->child[k];
        if(root->word.size() > 0){
            ans.push_back(root->word);
            root->word = ""; // reset TrieNode
        }
        // backtracking
        board[i][j] = '#'; // reset
        for(int d = 0; d < 4; d++){
            dfs(board, i+dir[d], j+dir[d+1], root, ans);
        }
        board[i][j] = c; // reverse
    }
private:
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};
};