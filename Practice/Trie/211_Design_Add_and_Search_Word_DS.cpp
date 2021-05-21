
class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    TrieNode() {
        isWord = false;
        memset(child, 0, sizeof(child));
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    void addWord(string word) {
        TrieNode* root = dict;
        for(char c : word){
            if(!root->child[c-'a'])
                root->child[c-'a'] = new TrieNode();
            root = root->child[c-'a'];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), dict);
    }
private:
    TrieNode* dict = new TrieNode();
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> child[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> child[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> isWord;
    }
};