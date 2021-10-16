/*
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
*/
class Solution {
public:
    // Sliding Window
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> count;
        vector<int> ans; // store index
        int n = s.length();
        for(string word : words){
            count[word]++;
        }
        if(count.size() == 0 || n == 0) return ans;
        int num = words.size(), len = words[0].length();
        for(int i = 0; i < n - len * num + 1; i++){ // add 1 here is the key!!
            unordered_map<string, int> seen;
            int j = 0;
            for(; j < num; j++){
                string tmp = s.substr(i + j * len, len);
                if(count.find(tmp) != count.end()){
                    seen[tmp]++;
                    if(seen[tmp] > count[tmp]) break;
                }
                else break;
            }
            if(j == num) ans.push_back(i);
        }
        return ans;
    }
};

// Recurssive ( Failed )
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        vector<int> ans;
        total_word = 0;
        for(auto word : words){
            mp[word]++;
            total_word += word.length();
        }
        int start = 0;
        int n = s.length();
        if(n < total_word) return ans;
        helper(ans, mp, s, 0, n);
        return ans;
    }
    void helper(vector<int>& ans, unordered_map<string, int> mp, string s, int start, int n){
        int len = 1;
        if(mp.size() == 0){
            ans.push_back(start - total_word - 1);
        }
        while(start < n){
            string tmp = s.substr(start,len);
            if(mp.count(tmp) != 0){
                mp[tmp]--; // found
                helper(ans, mp, s, start+len+1, n);
                mp[tmp]++; // reverse
            }
            len++;
        }
    }
private:
    int total_word;
};