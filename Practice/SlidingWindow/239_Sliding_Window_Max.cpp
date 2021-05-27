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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++)
        {
            if (!q.empty() && q.front() == i - k) q.pop_front(); // remove from front
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back(); // remove if smaller than new value
            q.push_back(i);
            if(i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
        
    }
};