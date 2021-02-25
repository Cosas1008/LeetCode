class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 14000);
        set<int> s(days.begin(), days.end());
        dp[0] = 0;
        for(int i = 1 ; i <= 365; i++){
            if(s.find(i) != s.end()){
                dp[i] = min(dp[i], dp[i - 1] + costs[0]);
                if(i >= 7){
                    dp[i] = min(dp[i], dp[i - 7] + costs[1]);
                }else{
                    dp[i] = min(dp[i], dp[0] + costs[1]);
                }
                if(i >= 30){
                    dp[i] = min(dp[i], dp[i - 30] + costs[2]);
                }else{
                    dp[i] = min(dp[i], dp[0] + costs[2]);
                }
                
            }else{
                dp[i] = dp[i-1];
            }
        }
        // for(int i = 1; i < days[days.size() - 1]; i++){
        //     cout << dp[i] <<  " ";
        // }
        return dp[days[days.size() - 1]];
    }
};