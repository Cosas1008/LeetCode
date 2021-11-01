/*
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo < hi){
            int mi = lo + (hi - lo) / 2;
            if(nums[mi] > nums[hi])
                lo = mi + 1;
            else if(nums[mi] < nums[lo]){
                hi = mi;
                lo++;
            }else
                hi--;
        }
        return nums[lo];
    }
};