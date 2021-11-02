/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
If there is no such subarray, return -1.
*/
class Solution {
public:
    // monotonic deque
    int shortestSubarray(vector<int>& A, int k) {
        int n = A.size(), res = n+1;
        deque<int> d;
        vector<long> B(A.begin(), A.end());
        for(int i = 0; i < n; ++i){
            if(i > 0) B[i] += B[i-1];
            if(B[i] >= k) res = min(res, i+1);
            while(d.size() && B[i] - B[d.front()] >= k)
                res = min(res, i - d.front()), d.pop_front();
            while(d.size() && B[i] <= B[d.back()]) // monotonic deque
                d.pop_back();
            d.push_back(i);
        }
        return (res == n+1)? -1 : res;
    }
    // priority_queue
    int shortestSubarray(vector<int>& A, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        long sum = 0;
        int n   = A.size();
        int ans = n+1;
        for(int i = 0; i < n; ++i){
            sum += A[i];
            if(sum >= k) ans = min(ans, i+1);
            while(pq.size() && sum - pq.top().first >= k){
                ans = min(ans, i - pq.top().second); pq.pop();
            }
            pq.emplace(sum, i);
        }
        return ans == n+1? -1 : ans;
    }
};