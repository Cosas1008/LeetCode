/*
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
*/
class Solution {
public:
    // DP
    // Time Complexity O(N^2)
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        long dp[n+1];
        memset(dp, 0x0, sizeof(dp));
        dp[0] = startFuel;
        for(int i = 0; i < n; i++){
            for(int t = i; t >= 0; t--){
                if(dp[t] >= stations[i][0])
                    dp[t+1] = max(dp[t+1], dp[t] + (long) stations[i][1]);
            }
        }
        for(int i = 0; i <= n; i++)
            if(dp[i] >= target) return i;
        return -1;
    }
    // prority_queue
    /*  We add all reachable stop to priority queue.
        We pop out the largest gas from pq and refeul once.
        If we can't refuel, means that we can not go forward and return -1
    */
    int minRefuelStops(int target, int cur, vector<vector<int>>& stations) {
        int i = 0, res;
        priority_queue<int> pq;
        for(res = 0; cur < target; res++){
            while(i < stations.size() && stations[i][0] <= cur)
                pq.push(stations[i++][1]);
            if(pq.empty()) return -1;
            cur += pq.top(); pq.pop();
        }
        return res;
    }
};