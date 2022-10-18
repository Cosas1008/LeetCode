/*
1. You have to finish at least one task every day.
2. Return the minimum difficulty of a job schedule. 
3. If you cannot find a schedule for the jobs return -1.

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
*/
// Monotonic Stack
// Time  O(n*D)
// Space O(n)
class Solution {
public:
    // (98%)
    int minDifficulty(vector<int>& A, int D) {
        int n = A.size();
        if(n < D) return -1;
        vector<int> dp(n, 1000), dp2(n), stack;
        for(int d = 0; d < D; ++d){
            stack.clear();
            for(int i = d; i < n; ++i){
                dp2[i] = i ? dp[i-1] + A[i] : A[i];
                while(stack.size() && A[stack.back()] <= A[i]){
                    int j = stack.back(); stack.pop_back();
                    dp2[i] = min(dp2[i], dp2[j] - A[j] + A[i]);
                }
                // Find max value for local stack
                if(stack.size())
                    dp2[i] = min(dp2[i], dp2[stack.back()]);
                stack.push_back(i);
            }
            swap(dp, dp2);
        }
        return dp[n-1];
    }
};
// Top-down DP
// Time  O(n^2*D)
// Space O(n*D)
class Solution{
public:
    // (34%)
    int minDifficulty(vector<int> JD, int D){
        int n = JD.size();
        if(n < D) return -1;
        vector<vector<int>> dp(n, vector<int>(D+1, -1));
        return min_diff(0, D, JD, dp);
    }
private:
    int min_diff(int idx, int daysRemain, vector<int>& JD, vector<vector<int>>& dp){
        if(dp[idx][daysRemain] != -1) return dp[idx][daysRemain];
        // Max of remain jobs
        if(daysRemain == 1){
            return *max_element(JD.begin()+idx, JD.end());
        }
        int res = INT_MAX, daily = 0;
        for(int i = idx; i < JD.size() - daysRemain + 1; ++i){
            daily = max(daily, JD[i]);
            res = min(res, daily + min_diff(i+1, daysRemain-1, JD, dp));
        }
        return dp[idx][daysRemain] = res;
    }
};
// Botton-Up 1-D
// Time  O(n^2*D)
// Space O(n)
class Solution{
public:
    // (44%)
    int minDifficulty(vector<int> A, int D){
        int n = A.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int day = 1; day <= D; ++day){
            vector<int> minDay(n+1, INT_MAX);
            minDay[n] = 0;
            for(int i = 0; i < n - day + 1; ++i){
                int daily = 0;
                for(int j = i + 1; j < n - day + 2; ++j){
                    daily = max(daily, A[j-1]);
                    if(dp[j] != INT_MAX)
                        minDay[i] = min(minDay[i], daily + dp[j]);
                }
            }
            dp = minDay;
        }
        return dp[0] < INT_MAX? dp[0] : -1;
    }
    // Optimized (80%)
    int minDifficulty(vector<int> A, int D){
        int n = A.size();
        if(D > n) return -1;
        vector<int> dp(n+1, 1e9);
        dp[n] = 0;
        for(int day = 1; day <= D; ++day){
            for(int i = 0; i <= n - day; ++i){
                dp[i] = 1e9;
                int maxd = 0;
                for(int j = i; j <= n - day; ++j){
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};