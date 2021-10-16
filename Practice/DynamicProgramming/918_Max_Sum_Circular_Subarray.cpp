/*
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
*/
class Solution {
public:
    // Kadane's Algorithm
    int maxSubarraySumCircular(vector<int>& A) {
        int total  = 0;
        int maxSum = A[0];
        int minSum = A[0];
        int curMax = 0, curMin = 0;
        for(int& a : A){
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total  += a;
        }
        return maxSum > 0? max(maxSum, total - minSum) : maxSum;
        // If all numbers are negative, maxSum = max(A) and minSum = sum(A).
        // In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
    }
    // Failed
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        vector<int> maxDP(A.begin(), A.end()), minDP(A.begin(), A.end()); // two copy of A

        for(int i = 1; i < n; i++){
            if(maxDP[i-1] > 0)
                maxDP[i] += maxDP[i-1];
            if(minDP[i-1] < 0)
                minDP[i] += minDP[i-1];
        }
        return max(*max_element(maxDP.begin(), maxDP.end()), sum - *min_element(minDP.begin(), minDP.end()));
    }
};