/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
If there is no such subarray, return -1.
*/
class Solution {
public:
    // deque
    int shortestSubarray(vector<int>& A, int k) {
        int n = A.size(), res = n+1;
        deque<int> d;
        for(int i = 0; i < n; ++i){
            if(i > 0) A[i] += A[i-1];
            if(A[i] >= k) res = min(res, i+1);
            while(d.size() && A[i] - A[d.front()] >= k)
                res = min(res, i - d.front()), d.pop_front();
            while(d.size() && A[i] <= A[d.back()]) // Popout lesser
                d.pop_back();
            d.push_back(i);
        }
        return (res == n+1)? -1 : res;
    }
};