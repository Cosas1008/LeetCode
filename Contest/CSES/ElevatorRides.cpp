/*
W is array wih n element, indicate weight of each person
limit is the elevate weight limit per ride

Return total ride should be made

*/

#define INF 1e9

int solve(vector<int>& W, int n, int limit){
    vector<pair<int,int>> dp(1<<n, {INF, INF});
    dp[0] = {0, INF};
    for(int mask = 1; mask < 1<<n; mask++){
        pair<int,int> best = {INF, INF};
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                pair<int,int> cur = dp[mask ^ (1<<i)];
                if(cur.second + W[i] > limit)
                    cur = {cur.first + 1, W[i]}; // new Ride start
                else
                    cur.second += W[i]; // current ride add new passenger
                best = min(best, cur);
            }
        }
        dp[mask] = best;
    }
    return dp[(1<<n) - 1].first;
}