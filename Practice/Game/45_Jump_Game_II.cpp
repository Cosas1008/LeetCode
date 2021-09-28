/*
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int position = nums.size() - 1;
        while(position > 0){
            // find leftmost position from 0 to position
            for(int i = 0; i < position; i++){
                if(i + nums[i] >= position){
                    step++;
                    position = i;
                    break;
                }
            }
        }
        return step;
    }
};