/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/
class Solution {
public:
    // O(N^2) 252 ms
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        int dp[n+1];
        memset(dp, 1, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(A[j] < A[i] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    // O(NlogN) 4ms
    int lengthOfLIS(vector<int>& A){
        vector<int>res;
        for(int& a : A){
            auto it = std::lower_bound(res.begin(), res.end(), a);
            if(it == res.end()) res.push_back(a); // can not find any larger
            else *it = a;
        }
        return res.size();
    }
};