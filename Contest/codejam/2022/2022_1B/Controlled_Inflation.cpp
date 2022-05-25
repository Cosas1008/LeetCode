#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++ti){
        int n, p, value;
        cin >> n >> p;
        vector<pair<int, int>> range(n+1, make_pair<int,int>(1e9+1 , -1e9-1));
        range[0] = make_pair(0,0);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= p; ++j){
                cin >> value;
                range[i].first  = min(range[i].first , value);
                range[i].second = max(range[i].second, value);
            }
        }
        int full;
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        for(int i = 1; i <= n; ++i){
            full = range[i].second - range[i].first;
            dp[i][0] = full + min(dp[i - 1][0] + abs(range[i].second - range[i - 1].first), dp[i - 1][1] + abs(range[i].second - range[i - 1].second));
            dp[i][1] = full + min(dp[i - 1][0] + abs(range[i].first  - range[i - 1].first), dp[i - 1][1] + abs(range[i].first  - range[i - 1].second));
        }
        cout << "Case #" << ti+1 << ": " << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}