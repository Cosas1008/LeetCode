/*
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
*/
// O(nlogn) for sorting, O(NSS) for loop
class Solution {
public:
    static bool compare(const string& s1, const string& s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for(string w : words){
            for(int i = 0; i < w.length(); i++){
                string pre = w.substr(0,i) + w.substr(i+1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end()? 1 : dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};