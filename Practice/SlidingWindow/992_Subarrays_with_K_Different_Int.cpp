class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
    int atMostK(vector<int>& nums, int K) {
        int i = 0, res = 0, n = nums.size();
        unordered_map<int, int> m;
        for (int j = 0; j < n; ++j) {
            if (!m[nums[j]]++) K--;
            while (K < 0) {
                if (!--m[nums[i]]) K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};