#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void printDP(vector<vector<int>>& dp, string& s, string& t){
        int m = dp.size(), n = dp[0].size();
        cout << "     ";
        for(int i = 0; i < n; ++i)
            cout << setw(4) << t[i];
        cout << endl;
        for(int i = 0; i < m; ++i){
            cout << s[i] << " ";
            for(int j = 0; j < n; ++j)
                cout << setw(3) << dp[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    string minWindow(string S, string T) {
        int sl = S.length(), tl = T.length();
        int start = -1, minLen = INT_MAX;
        vector<vector<int>> dp(sl+1, vector<int>(tl+1, -1));
        for(int i = 0; i <= sl; ++i) dp[i][0] = i;
        for(int i = 1; i <= sl; ++i){

            for(int j = 1; j <= min(tl, i); ++j)
                dp[i][j] = (S[i-1] == T[j-1])? dp[i-1][j-1] : dp[i-1][j];

            if(dp[i][tl] != -1){
                int len = i - dp[i][tl];
                if(minLen > len){
                    minLen = len;
                    start  = dp[i][tl];
                }
            }
        }
        printDP(dp, S, T);
        return (start == -1)? "" : S.substr(start, minLen);
    }
    // two pointer
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX, i = 0, j = 0;
        while (i < m) {
            if (S[i] == T[j]) {
                if (++j == n) {
                    int end = i + 1;
                    while (--j >= 0) {
                        while (S[i--] != T[j]);
                    }
                    ++i; ++j;
                    if (end - i < minLen) {
                        minLen = end - i;
                        start = i;
                    }
                }
            }
            ++i;
        }
        return (start != -1) ? S.substr(start, minLen) : "";
    }
};

int main(){
    Solution s;
    string S = "abcdebdde";
    string T = "bde";
    cout << s.minWindow(S, T) << endl;
    return 0;
}