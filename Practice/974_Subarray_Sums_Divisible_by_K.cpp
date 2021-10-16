/*
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/
class Solution {
public:
    // DP Time O(N^2) TLE
    int subarraysDivByK(vector<int>& A, int k) {
        vector<int> dp(A.size()+1, 0);
        for(int i = A.size()-1; i >= 0; --i){
            for(int j = i, sum = 0; j < A.size(); ++j){
                sum += A[j];
                if(sum % k == 0){
                    dp[i] = 1 + dp[j+1];
                    break;
                }
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
    // prefix
    int subarraysDivByK(vector<int>& A, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for(int a : A){
            prefix = (prefix + a  % k + k) % k;
            res += count[prefix]++;
        }
        return res;
    }
};