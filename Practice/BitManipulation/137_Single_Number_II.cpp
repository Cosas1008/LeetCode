/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0; // Assume "ones" and "twos" to be sets that are keeping track of which numbers have appeared once and twice respectively;
        for(auto n : nums){
            ones = (ones ^ n) & ~twos; // (ones ^ A[i])  if and only if A[i] is not present in the set "twos". 
            twos = (twos ^ n) & ~ones; // (twos ^ A[i])  if and only if A[i] is not present in the set "ones". 
        }
        return ones;
    }
};