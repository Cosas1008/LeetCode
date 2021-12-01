/*
Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
Output: 19
Explanation: One permutation of nums is [2,1,3,4,5] with the following result: 
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
Total sum: 8 + 3 = 11.
A permutation with a higher total sum is [3,5,4,2,1] with the following result:
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
Total sum: 11 + 8 = 19, which is the best that you can do.
*/
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        long res = 0, mod = 1e9+7;
        int n = nums.size();
        vector<int> freq(n);
        for(vector<int>& r : requests){
            freq[r[0]]++;
            if(r[1] + 1 < n)
                freq[r[1]+1]--;
        }
        for(int i = 1; i < n; ++i)
            freq[i] += freq[i-1];
        
        sort(begin(freq), end(freq));
        sort(begin(nums), end(nums));
        for(int i = 0; i < n; ++i)
            res += (long) freq[i] * nums[i];
        return res % mod;
    }
};