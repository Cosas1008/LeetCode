/*
Input: nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
Output: 4
Explanation: One optimal approach is to change nums[2] to k. The array becomes [22,4,-33,-20,-15,15,-16,7,19,-10,0,-13,-14].
There are four ways to partition the array.

1 <= pivot < n
nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]

Hint: prefix from left and right
*/
class Solution {
public:
    // We need count of indexes i, such that nums[0] + ... + nums[i-1] == nums[i] ... nums[n-1], that is prefixSum[i-1] = SuffixSum[i].
    int waysToPartition(vector<int>& nums, int k) {
        int N = nums.size();
        int ans = 0;
        vector<long> pref(N), suff(N);
        unordered_map<long long, int> left, right;
        pref[0] = nums[0]; suff[N-1] = nums[N-1];
        for(int i = 1; i < N; ++i){
            pref[i] = pref[i-1] + nums[i];
            suff[N-1-i] = suff[N-i] + nums[N-1-i];
        }
        for(int i = 0; i < N-1; ++i)
            right[pref[i] - suff[i+1]]++;
        if(right.count(0)) ans = right[0]; // number of unchanged pivot index

        for(int i = 0; i < N; ++i){
            // privot index where nums[i] -> k
            long long curr = 0, diff = k - nums[i];
            if(left.count(diff)) curr += left[diff];
            if(right.count(-diff)) curr += right[-diff];

            ans = max(ans, (int) curr); // number of change nums[i] -> k pivot index

            if(i < N-1){
                long long dd = pref[i] - suff[i+1];
                left[dd]++; right[dd]--;
                if(right[dd] == 0) right.erase(dd);
            }
        }
        return ans;
    }
};