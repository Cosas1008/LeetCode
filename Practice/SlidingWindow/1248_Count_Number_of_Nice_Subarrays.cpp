/*
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k-1);
    }
    int atMost(vector<int>& A, int k){
        int j = 0, n = A.size(), res = 0;
        for(int i = 0; i < n; ++i){
            if(A[i] % 2) k--;
            while(k < 0){
                if(A[j] % 2) k++;
                j++;
            }
            res += i - j + 1;
        }
        return res;
    }
};