/*
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
*/
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
      unordered_set<string> good(words.begin(), words.end());
      
      for(string word : words)
        for(int k = 1; k < word.length(); ++k)
          good.erase(word.substr(k));
      
      int ans = 0;
      for(string word : good)
        ans += word.length() + 1;
      
      return ans;
    }
};