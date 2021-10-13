/*
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
*/
class Solution {
public:
    // Sliding Window with K different
    int longestSubarray(vector<int>& A) {
        int res = 0, i = 0, j, n = A.size(), k = 1;
        for(j = 0; j < n; ++j){
            if(A[j] == 0) k--;
            while(k < 0){
                if(A[i] == 0)
                    k++;
                i++;
            }
            res = max(res, j - i);
        }
        return res;
    }
    // Sliding Window 2 (Hard to prove, but smart)
    int longestSubarray(vector<int>& A){
        int i = 0, j, k = 1;
        for(j = 0; j < A.size(); ++j){
            if(A[j] == 0) k--;
            if(k < 0 && A[i++] == 0) k++;
        }
        return j - i - 1;
    }
};