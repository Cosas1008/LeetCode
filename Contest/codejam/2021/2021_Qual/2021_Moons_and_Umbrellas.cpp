// TLE
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solve(int t){
    cout << "Case #" << t << ": ";
    int x, y;
    string s;
    cint >> x >> y >> s;
    int n = (int)s.length();
    vector<vector<int>> dp(n+1, vector<int>(2, 1e9));
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; ++i){
        for(int c = 0; c < 2; ++c){
            if(c == 0 && s[i-1] == 'J') continue;
            if(c == 1 && s[i-1] == 'C') continue;
            for(int d = 0; d < 2; ++d){
                int cost = 0;
                if(i > 1){
                    if(d == 0 && c == 1) cost += x; // CJ
                    if(d == 1 && c == 0) cost += y; // JC
                }
                dp[i][c] = min(dp[i][c], dp[i-1][d] + cost);
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int countRepeat(string b, string a){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == b[0] && a[i+1] == b[1]){
            cnt+= 1;
        }
    }
    return cnt;
};
void permutation(int index, string s, int& minval, int& x, int& y)
{
    if(index == s.size()){
        int cntx = countRepeat("CJ", s);
        int cnty = countRepeat("JC", s);
        minval = min(minval, cntx * x + cnty * y);
    }else if(s[index] == '?'){
        permutation(index+1, s.substr(0,index) + 'C' + s.substr(index+1), minval, x, y);
        permutation(index+1, s.substr(0,index) + 'J' + s.substr(index+1), minval, x, y);
    }else{
        permutation(index+1, s, minval, x, y);
    }
};
int main()
{
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++)
    {
        int x, y;
        string s;
        int minval = 2147483647;
        vector<string> store;
        cin >> x >> y;
        cin >> s;
        permutation(0, s, minval, x, y);
        cout << "Case #" << ti+1 << ": " << minval << endl;
    }
    return 0;
}