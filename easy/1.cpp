class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnVector(2);
        int length = nums.size();
        int remains;
        for(int i =0 ; i < length; i ++){
            remains = target - nums[i];
            //find the next couple value
            for(int j = length - 1; j >=0 ; j --){
                if(nums[j] == remains && i != j){
                    returnVector[0] = i;
                    returnVector[1] = j;
                    return returnVector;
                }
            }
        }
        
    };
    
};