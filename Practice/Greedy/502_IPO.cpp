/*
Initially, you have w capital. 
When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
*/

typedef pair<int,int> pii;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pii> projects;
        for(int i = 0; i < n; i++)
            projects.push_back(make_pair(profits[i], capital[i]));
        
        sort(projects.begin(), projects.end(),[&](pii a, pii b){ return a.second < b.second; });
        priority_queue<int> pq;
        int i = 0;
        while(k){
            while(i < n && projects[i].second <= w)
                pq.push(projects[i++].first); // profits
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
            k--;
        }
        return w;
    }

    // Op2
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c){
        priority_queue<int> low;
        multiset<pii> high;
        for(int i = 0; i < p.size(); i++){
            if(p[i] <= 0) continue;
            if(c[i] <= w)
                low.push(p[i]);
            else
                high.emplace(c[i], p[i]);
        }

        while(k-- && low.size()){
            w += low.top(); low.pop();
            for(auto it = high.begin(); high.size() && it->first <= w; it = high.erase(it))
                low.push(it->second);
        }
        return w;
    }

    // DP Wrong 23/25
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> dp(k+1, vector<int>(n+1));
        for(int i = 0; i <= n; i++){
            dp[0][i] = w;
        }
        for(int i = 1; i <= k; i++){
            dp[i][0] = w;
            for(int j = 1; j <= n; j++){
                int tmp = 0;
                for(int k = 0; k < j; k++){
                    if(dp[i-1][k] >= capital[j-1])
                        tmp = max(dp[i-1][k] + profits[j-1], tmp);
                }
                dp[i][j] = tmp;
            }
        }
        int res = 0;
        for(int i = 0; i <= n; i++){
            res = max(dp[k][i], res);
        }
        return res;
    }
};