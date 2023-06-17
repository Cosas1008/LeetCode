/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.
*/
class Solution {
public:
    // Binary Search O(lg N)?
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo < hi){
            int m1 = lo + (hi - lo) / 2;
            int m2 = m1 + 1;
            if(nums[m1] < nums[m2])
                lo = m2;
            else
                hi = m1;
        }
        return lo;
    }
};