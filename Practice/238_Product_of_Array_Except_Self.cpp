/*
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/
class Solution {
public:
    // brute force (TLE)
    vector<int> productExceptSelf(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            int sum = 1;
            for(int j = 0; j < n; ++j){
                if(sum != 0 && i != j){
                    sum *= A[j];
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
    // Optimize Time O(n) Space O(n)
    vector<int> productExceptSelf(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n), left(n), right(n);
        left[0] = 1;
        right[0] = 1;
        for(int i = 1; i < n; ++i){
            left[i] = left[i-1] * A[i-1];
            right[i] = right[i-1] * A[n-i];
        }
        for(int i = 0; i < n; ++i){
            ans[i] = left[i] * right[n-i-1];
        }
        return ans;
    }
    // Space O(1)
    vector<int> productExceptSelf(vector<int>& A){
        int n = A.size();
        int left = 1, right = 1;
        vector<int> ans(n, 1);
        for(int i = 0; i < n; ++i){
            ans[i] *= left;
            left *= A[i];
            ans[n-1-i] *= right;
            right *= A[n-1-i];
        }
        return ans;
    }
};