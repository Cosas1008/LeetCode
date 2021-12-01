/*
Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
*/
class Solution {
public:
    // Magic!
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, L = -1, R = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > right) L = i;
            if(nums[i] >= left) R = i;
            res += R - L;
        }
        return res;
    }
    // More solid way
    int numSubarrayBoundedMax(vector<int>& A, int left, int right){
        return count(A, right) - count(A, left-1);
    }
    int count(vector<int>& A, int bound){
        int ans = 0, cnt = 0;
        for(int a : A){
            cnt = a <= bound? cnt+1 : 0;
            ans += cnt;
        }
        return ans;
    }
};