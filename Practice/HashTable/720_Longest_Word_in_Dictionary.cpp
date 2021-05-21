class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> st(words.begin(), words.end());
        string ans = "";
        for(string word : words){
            if(word.length() == 1 || st.count(word.substr(0,word.length() - 1))){
                ans = word.length() > ans.size() ? word : ans;
                st.insert(word);
            }
        }
        return ans;
    }
};