/*
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
*/
class Solution {
public:
    // Dynamic Programming
    int numSquares(int n) {
        if(n <= 0) return 0;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j*j <= i; ++j)
                dp[i] = min(dp[i], dp[i-j*j] + 1);
        return dp[n];
    }
    // Static array
    int numSquares(int n) {
        vector<int> dp = {0};
        while(dp.size() <= n){
            int m = dp.size(), square = INT_MAX;
            for(int i = 1; i * i <= m; ++i)
                square = min(square, dp[m-i*i] + 1);
            dp.push_back(square);
            printDP(dp);
        }
        return dp[n];
    }
    void printDP(vector<int>& dp){
        for(auto & item : dp)
            cout << item << " " ;
        cout << endl;
    }
};