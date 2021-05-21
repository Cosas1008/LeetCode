class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        st.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return st.find(word) != st.end();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for(auto s : st){
            if(s.find(prefix) == 0){
                return true;
            }
        }
        return false;
    }
private:
    unordered_set<string> st;
};

// TrieNode DS
class TrieNode {
public:
    bool is_word;
    TrieNode *child[26];
    TrieNode (){
        is_word = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int wl = word.length();
        int k = 0;
        TrieNode *cur = root;
        for(char c : word){
            k = c - 'a';
            if(cur->child[k] == NULL){
                cur->child[k] = new TrieNode();
            }
            cur = cur->child[k];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int k;
        TrieNode * ptr = root;
        for(char c : word){
            k = c - 'a';
            if(!ptr->child[k]) return false;
            ptr = ptr->child[k];
        }
        return ptr->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int k;
        TrieNode * ptr = root;
        for(char c : prefix){
            k = c - 'a';
            if(!ptr->child[k]) return false;
            ptr = ptr->child[k];
        }
        return true;
    }
private:
    TrieNode* root;
};
