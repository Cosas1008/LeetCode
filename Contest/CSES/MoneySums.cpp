/*
Input
------------
The first input line has an integer n: the number of coins.
The next line has n integers x1,x2,…,xn: the values of the coins.

Output
------------
First print an integer k: the number of distinct money sums. 
After this, print all possible sums in increasing order.

*/
void solve(vector<int>& C, int n){
    int sum = accumulate(begin(C), end(C), 0);
    bool dp[sum+1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(int i = 0; i < n; i++){
        for(int j = sum - C[i]; j >= 0; j--){
            if(dp[j])
                dp[j+C[i]] = true;
        }
    }
    vector<int> ret;
    for(int i = 1; i <= sum; i++){
        if(dp[i])
            ret.push_back(i);
    }
}