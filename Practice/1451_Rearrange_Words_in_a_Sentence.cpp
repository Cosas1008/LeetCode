class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        map<int, string> bucket;
        stringstream ss(text), rs;
        string ans;
        string word;
        while(ss >> word)
        {
            bucket[word.length()] += word + " ";
            // cout << word << endl;
        }
        for (const auto& pair: bucket) rs << pair.second;
        ans = rs.str();
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};