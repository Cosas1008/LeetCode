/*
StreamChecker(String[] words) Initializes the object with the strings array words.
boolean query(char letter) Accepts a new character from the stream and returns true 
if any non-empty suffix from the stream forms a word that is in words.

Key: to store word reversely
*/
class Trie{
public:
    Trie(){
        is_leaf = false;
        for(int i = 0; i < 26; ++i)
            children[i] = NULL;
    }
    void insert_reversed(string word) {
        reverse(word.begin(), word.end());
        Trie* root = this;
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if (root->children[index] == NULL)
                root->children[index] = new Trie();
            root = root->children[index];
        }
        root->is_leaf = true;
    }
    Trie *children[26];
    bool is_leaf;
};
class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for(string& word : words){
            trie.insert_reversed(word);
            if (word.length() > longest_word)
                longest_word = word.length();
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);
        // keep in queries only the "longest word" last queries, because we don't need the other ones anymore
        if (queries.size() > longest_word)
            queries.pop_back();
        Trie* cur = &trie;
        for (auto it = queries.begin(); it!=queries.end();++it)
        {
            if (cur->is_leaf) return true;
            if (cur->children[*it -'a'] == NULL) return false;
            cur = cur->children[*it-'a'];
        }
        return cur->is_leaf;
    }
private:
    Trie trie;
    int longest_word = 0;
    vector<char> queries;
    
};