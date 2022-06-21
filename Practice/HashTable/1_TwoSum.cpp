class Solution {
public:
    // Time O(N^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++){
                if(target - nums[i] - nums[j] == 0){
                    return {i, j};
                }
            }
        }
        return {};
    }
    // Time O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); i++)
        {
            if(hash.find(target - nums[i]) != hash.end()){
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};