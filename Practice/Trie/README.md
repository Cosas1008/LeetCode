# Trie Related problem

- [x] 212 Word Search II ( In backtracking )
- [x] 421 Maximum XOR of Two Numbers in an Array
- [ ] 472 Concatenated Words
- [ ] 336 Palindrome Pairs
- [x] 1268 Search Suggestions System (use trie)
- [ ] 1707 Maximum XOR with Elements from Array
- [ ] 1803 Count Pairs with XOR in a Range ( Hardest! )
- [ ] 1938 Maximum Genetic Difference Query 
## TODO:

1707

Trie Struct
```cpp
struct trienode{  // make structure of trie..
    bool isendofword;
    trienode* children[26];
};

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
```