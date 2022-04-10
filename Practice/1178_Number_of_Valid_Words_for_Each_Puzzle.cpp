/*
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).

1 <= puzzles.length <= 10^4
1 <= words.length <= 10^5
*/

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        unordered_map<int, int> wordCount;
        for(string& word : words)
            wordCount[bitmask(word)]++;
        for(string& puzzle : puzzles){
            int first = 1 << (puzzle[0] - 'a');
            int count = wordCount[first];
            int mask  = bitmask(puzzle.substr(1));
            for(int sub = mask; sub; sub = (sub-1) & mask)
                count += wordCount[sub | first];
            res.push_back(count);
        }
        return res;
    }
private:
    int bitmask(const string& word){
        int mask = 0;
        for(char c : word)
            mask |= 1 << (c - 'a');
        return mask;
    }
};