/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
*/
class Solution {
public:
    // Sort by tail!!!!
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int> & lhv, const vector<int> & rhv){
            return lhv[1] < rhv[1];
        });
        int n = pairs.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                dp[j] = max(dp[j], pairs[j][0] > pairs[i][1]? dp[i] + 1 : dp[j]);
            }
        }
        for(int i = 0 ; i < n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Greedy is Optimal solution
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int cnt = 0;
        for (int i = 0, j = 0; j < pairs.size(); j++) {
            if (j == 0 || pairs[i][1] < pairs[j][0]) {
                cnt++;
                i = j;
            }
        }
        return cnt;
    }

private:
    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1];
    }
};