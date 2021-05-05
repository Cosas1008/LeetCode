class Solution {
public:
    // Solve without sort ( Not efficient)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int total_tuple = nums.size() / 3;
        if(total_tuple == 0) return {};
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size() - 1; i++){
            unordered_map<int, int> hash;
            for(int j = i+1; j < nums.size(); j++){
                int target = - (nums[j] + nums[i]);
                if(hash.find(target) != hash.end()){
                    vector<int> tmp ={nums[i], nums[hash[target]], nums[j]};
                    push_to_ans(ans, tmp);
                }
                hash[nums[j]] = j;
            }
        }
        return ans;
    }
private:
    void push_to_ans(vector<vector<int>>& ans, vector<int> tmp){
        bool duplicate = false;
        for(auto a: ans){
            if(find(a.begin(), a.end(), tmp[0]) != a.end() &&
               find(a.begin(), a.end(), tmp[1]) != a.end() &&
               find(a.begin(), a.end(), tmp[2]) != a.end()){
                duplicate = true;
            }
        }
        if(!duplicate){
            ans.push_back(tmp);
        }
    }
};