// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while(i < n && j < n){
            if((nums[i] & 1) == 0){
                i += 2;
            }else if(nums[j] & 1){
                j += 2;
            }else{
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};