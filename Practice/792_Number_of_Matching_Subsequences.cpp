/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
*/
// TLE
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        for(string word : words){
            if(helper(s, word, 0)) ans++;
        }
        return ans;
    }
    bool helper(string s, string w, int pos){
        if(pos == w.length()) return true;
        char c = w.at(pos);
        auto it = s.find(c);
        if(it != string::npos){
            return helper(s.substr((int)it + 1), w, pos+1);
        }else{
            return false;
        }
    }
};
// Optimize surpreme
int numMatchingSubseq(string S, vector<string>& words) {
    vector<const char*> waiting[128];
    for (auto &w : words)
        waiting[w[0]].push_back(w.c_str()); // not that c_str() convert string into const char* with /0 add to end
    for (char c : S) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[*++it].push_back(it);
    }
    return waiting[0].size(); // size of bucket [/0] genious
}

// Optimize 2 bucket ? Pic:https://assets.leetcode.com/users/images/644a318d-02fe-4a9e-bd0a-56279494780a_1624383264.6582396.png

struct Node {
    string word;
    int index;
    Node(const string& word, int index) : word(word), index(index) {}
}

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<Node>> buckets;
        for (string& word : words) {
            char startingChar = word[0];
            buckets[startingChar].push_back(Node(word, 0));
        }
        int ans = 0;
        for (char c : s) {
            auto currBucket = buckets[c];
            buckets[c].clear();
            for (Node& node : currBucket) {
                node.index += 1; // Point to next character of node.word
                if (node.index == node.word.size()) {
                    ans += 1;
                } else {
                    buckets[node.word[node.index]].push_back(node);
                }
            }
        }
        return ans;
    }
};