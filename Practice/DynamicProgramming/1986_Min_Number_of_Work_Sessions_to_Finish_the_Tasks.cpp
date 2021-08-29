/*
dp[mask] = {a, b} where
a - minimum number of session
b - minimum time of last session
*/
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int inf = 1e9;
        vector<pair<int,int>> dp(1<<n, {inf,inf});
        dp[0] = {0, inf};
        for(int mask = 1; mask < (1 << n); mask++){
            pair<int,int> best = {inf, inf};
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    pair<int,int> cur = dp[mask ^ (1 << i)];
                    if(cur.second + tasks[i] > sessionTime){
                        cur = {cur.first + 1, tasks[i]};
                    }else
                        cur.second += tasks[i];
                    best = min(best, cur);
                }
            }
            dp[mask] = best;
        }
        return dp[(1<<n) - 1].first;
    }

    // Another approach
    int minSessions(vector<int>& tasks, int sessionTime){
        const int N = tasks.size();
        vector<int> dp(1 << N, 1000);
        dp[0] = 0;
        for(int s = 1; s < 1 << N; s++){
            int req = 0;
            for(int i = 0; i < N; i++) if((s>>i) & 1) req += tasks[i];
            if(req <= sessionTime) dp[s] = 1;
            for(int t = s; ; t = (t-1) & s){
                if(dp[s] > dp[t] + dp[s-t]) dp[s] = dp[t] + dp[s-t];
                if(t == 0) break;
            }
        }
        return dp.back();
    }
};