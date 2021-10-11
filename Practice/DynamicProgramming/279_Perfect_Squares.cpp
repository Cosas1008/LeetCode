/*
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
*/
class Solution {
public:
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