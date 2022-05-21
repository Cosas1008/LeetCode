/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
      vector<int> ans;
      deque<int> q;
      for(int i = 0; i < A.size(); ++i){
        if(!q.empty() && q.front() == i - k) q.pop_front();
        while(q.size() && A[q.back()] < A[i]) q.pop_back();
        q.push_back(i);
        if(i >= k-1) ans.push_back(A[q.front()]);
      }
      return ans;
    }
};