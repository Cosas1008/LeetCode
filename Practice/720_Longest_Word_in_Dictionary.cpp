/*
return the longest word in words that can be built one character at a time by other words in words.
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        sort(words.begin(), words.end(), [](const string & lh, const string & rh){
            return lh.size() == rh.size()? lh < rh : lh.size() > rh.size();
        });
        for(auto word : words){
            int size = word.length() - 1;
            // cout << size << endl;
            while(size >= 0){
                // cout << word.substr(0, size) << endl;
                if(dict.find(word.substr(0, size--)) == dict.end())
                    break;
            }
            if(size == -1) return word;
        }
        return "";
    }
    // Clean code, Better! O(nlognL)
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> dict;
        string res = "";
        for(string w : words){
            if(w.size() == 1 || dict.count(w.substr(0, w.size() - 1))){
                res = w.size() > res.size()? w : res;
                dict.insert(w);
            }
        }
        return res;
    }
};