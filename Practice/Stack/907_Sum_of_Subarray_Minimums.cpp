/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.
*/
class Solution {
public:
    // Time Complexity O(n), Space O(n)
    int sumSubarrayMins(vector<int>& A) {
        // res = sum(A[i] * f(i)) where f(i) is the number of subarrays, in which A[i] is the minimum.
        long  res = 0, mod = 1e9 + 7, n = A.size();
        // left and right are two increasing stacks
        vector<int> left(n), right(n);
        stack<pair<int,int>> s1, s2;
        for(int i = 0; i < n; ++i){
            int count = 1;
            while(s1.size() && s1.top().first > A[i]){ // NOTE here!!! >
                count += s1.top().second;
                s1.pop();
            }
            s1.push({A[i], count});
            left[i] = count;
        }

        for(int i = n-1; i >= 0; --i){
            int count = 1;
            while(s2.size() && s2.top().first >= A[i]){ // NOTE here!!! >=
                count += s2.top().second;
                s2.pop();
            }
            s2.push({A[i], count});
            right[i] = count;
        }

        for(int i = 0 ; i < n; ++i)
            res = (res + (long)A[i] * left[i] * right[i]) % mod;
        return res;
    }
};