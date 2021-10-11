// Pick any nums[i] and delete it to earn nums[i] points. 
// Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

class Solution {
public:
    // skip_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you skip the ith bucket.
    // take_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you take the ith bucket.
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> buckets(n, 0);
        for(auto num : nums)
            buckets[num] += num; // accumulate each bucket
        int take = 0, skip = 0;
        for(int i = 0; i < n; ++i){
            int take_i = skip + buckets[i];
            int skip_i = max(skip, take);
            take = take_i;
            skip = skip_i;
        }
        return max(take, skip);
    }
};