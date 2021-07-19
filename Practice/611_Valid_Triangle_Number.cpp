/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles 
if we take them as side lengths of a triangle.
Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        sort(nums.begin(), nums.end());
        for(int i = n-1; i >= 0; i--){
            int l = 0, r = i-1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    total += r-l;
                    r--;
                }else{
                    l++;
                }
            }
        }
        return total;
    }
};