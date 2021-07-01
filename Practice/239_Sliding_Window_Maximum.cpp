class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++)
        {
            if (!q.empty() && q.front() == i - k) q.pop_front(); // This pop_front will remove last element
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back(); // This pop_back will remove small value index
            q.push_back(i); // Store index
            if(i >= k - 1) ans.push_back(nums[q.front()]); // return answer
        }
        return ans;
        
    }
};