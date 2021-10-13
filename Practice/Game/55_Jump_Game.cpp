/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
*/
class Solution {
public:
    // Time : O(n) Space O(1)
    bool canJump(vector<int>& A){
        int i = 0, n = A.size();
        for(int reach = 0; i < n && i <= reach; ++i){
            reach = max(i + A[i], reach);
        }
        return i == n;
    }

    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--)
            if(i + nums[i] >= goal)
                goal = i;
            
        return (!goal);
    }
};