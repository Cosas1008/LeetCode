/*
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        sum /= 2;
        bool dp[sum+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(auto& num : nums){
            cout << "Num " << num << endl; // debug
            for(int i = sum; i >= 0; i--){
                if(i >= num){
                    dp[i] = dp[i] | dp[i - num];
                }
                print(dp, sum+1); // debug
            }
        }
        return dp[sum];
    }
    void print(bool* dp, int n){
        for(int i = 0 ; i< n; i++)
            cout << dp[i] << " ";
        cout << endl;
    }
};