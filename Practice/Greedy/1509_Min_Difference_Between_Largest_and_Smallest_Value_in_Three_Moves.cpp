/*
Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.
*/
class Solution {
public:
    int minDifference(vector<int>& A) {
        int n = A.size();
        if(n < 5) return 0;
        sort(A.begin(), A.end());
        return min(A[n-4] - A[0], min(A[n-3] - A[1], min(A[n-2] - A[2], A[n-1] - A[3])));
    }
};