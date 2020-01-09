// Time complexity O(n^2)
// Space n^2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.length();
        int K[slen+1][slen+1];
        int max = 0;
        for(int i = 0; i <= slen; i++){
            for(int j = 0; j <= slen; j++){
                K[i][j] = 0;
            }
        }
        for(int i = 1; i <= slen; i++){
            for(int j = i; j <= slen; j++){
                // cout << "i : " << i << " j : " << j  << " K : " << K[i-1][j-1] << endl;
                if(s.at(i-1) == s.at(j-1)){
                    int match = K[i-1][j-1];
                    std::size_t found = s.substr(j-match-1,match).find(&s.at(j-1),0,1);
                    if(found!=std::string::npos) {
                        K[i][j] = match-found;
                    }else{
                        K[i][j] = K[i-1][j-1] + 1;
                    }
                }
            }
        }
        for(int i = 1; i <= slen; i++){
            // for(int k=0;k<i;k++) cout << " |  ";
            // cout << " ";
            for(int j = i; j <= slen; j++){
                // cout << K[i][j] << " | ";
                if(K[i][j] > max)
                    max = K[i][j];
            }
            // cout << endl;
        }
        return max;
    }
};

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
