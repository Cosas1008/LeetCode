// Time complexity O(n)
// Space n
int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

// Time complexity O(n)
// Space min of constructor
// Good solution
int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;

    int i = 0, j = 0, n = s.size(), ans = 0;
    while(i < n && j < n){
        if(st.find(s[j]) == st.end()){
            st.insert(s[j++]);
            ans = max(ans, j-i);
        }else{
            st.erase(s[i++]);
        }
    }
    return ans;
}

// Time O(N^2)
// Space O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.length();
        int K[slen+1];
        int max = 0;
        for(int i = 0; i <= slen; i++){
            K[i] = 0;
        }
        for(int i = 1; i <= slen; i++){
            char a = s[i-1];
            for(int j = i; j <= slen; j++){
                char b = s[j-1];
                if(a==b){
                    int match = K[i-1];
                    string tmp = s.substr(j-match-1,match);
                    size_t found = tmp.find(b);
                    if(found!=std::string::npos) {
                        K[i] = match - found;
                        cout << "Bang" << endl;
                    }else{
                        K[i] = match + 1;
                    }
                    if(K[i] > max)   max = K[i];
                    cout <<  "(i,j) : (" << i << "," << j << ") substring: "<< tmp  << " match " << match << " found :" << found << endl;
                }
            }
            cout << "Char : " << s.at(i-1) << " K : ";
            for(int l= 1; l <= slen; l++)
                cout << K[l] << "-";
            cout << endl;
        }
        return max;
    }
};
