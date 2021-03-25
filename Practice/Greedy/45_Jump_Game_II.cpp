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