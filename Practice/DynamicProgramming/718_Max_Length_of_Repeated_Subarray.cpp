/*
Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int dp[n2+1];
        int ret = 0;
        memset(dp, 0x0, sizeof(dp));
        for(int i = n1-1; i >= 0; i--){
            for(int j = 0; j < n2; j++){
                ret = max(ret, dp[j] = (nums1[i] == nums2[j])? dp[j+1] + 1: 0);
            }
        }
        return ret;
    }
};