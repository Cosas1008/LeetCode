/*
Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]

*/
class Solution {
public:
    struct TrieNode {
        bool isWord;
        TrieNode *children[26];
    };

    TrieNode *getNode() {
        struct TrieNode *node = new TrieNode;
        node->isWord = false;
        for (int i = 0; i < 26; i++) {
            node->children[i] = NULL;
        }
        return node;
    }

    void insertWord(string &key) {
        struct TrieNode *node = root;
        for (int i = 0; i < key.size(); i++) {
            int ind = key[i] - 'a';
            if (node->children[ind] == NULL) {
                node->children[ind] = getNode();
            }
            node = node->children[ind];
        }
        node->isWord = true;
    }

    bool searchTrie(string &key) {
        struct TrieNode *node = root;
        for (int i = 0; i < key.size(); i++)
        {
            int idx = key[i] - 'a';
            if (node->children[idx] == NULL)
            { // if not found return false;
                return false;
            }
            node = node->children[idx];
        }
        return node->isWord == true;
    }

    bool ispalindrome(string s) {
        return s == string(s.rbegin(), s.rend());
    }

    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
            mp[words[i]] = i;
            insertWord(words[i]); // inserting reversed words
            reverse(words[i].begin(), words[i].end());
        }

        // Exception on null
        if (mp.count("")) {
            for (int i = 0; i < words.size(); i++){
                if (words[i] != "" && ispalindrome(words[i])){
                    ans.push_back({mp[""], i}); // making a seperate case for empty strings
                }
            }
        }

        // Search
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string left  = words[i].substr(0, j);
                string right = words[i].substr(j);
                
                if (searchTrie(left) && ispalindrome(right) && mp[left] != i) {
                    ans.push_back({i, mp[left]});
                }
                
                if (searchTrie(right) && ispalindrome(left) && mp[right] != i) {
                    ans.push_back({mp[right], i});
                }
            }
        }
        return ans;
    }

private:
    struct TrieNode *root = getNode();
    map<string, int> mp;
};