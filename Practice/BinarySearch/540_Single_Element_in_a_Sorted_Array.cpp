/*
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

1 <= nums.length <= 105
0 <= nums[i] <= 105

Note: Your solution must run in O(log n) time and O(1) space.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-2;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] == nums[mid^1]) // nums[mid] == nums[mid ^ 1] for odd position compares with the previous number; for even position compares with the next number. The unique number must be at even position.
                low = mid+1;
            else
                high = mid-1;
        }
        return nums[low];
    }
};