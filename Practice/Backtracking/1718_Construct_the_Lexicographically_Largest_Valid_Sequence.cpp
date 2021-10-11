class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n - 1);
        vector<int> nums(n+1, 1);
        return dfs(nums, ans, 0);
    }
    vector<int> dfs(vector<int>& nums, vector<int>& arr, int p){
        if(p == arr.size()) return arr;
        if(arr[p] != 0) return dfs(nums, arr, p+1);
        for(int i = nums.size() - 1; i >= 1; --i){ // from largest to smallest
            int dist = i == 1 ? 0 : i;
            if(nums[i] != 0 && dist + p < arr.size() && arr[dist+p] == 0){
                arr[p] = arr[dist+p] = i; // key here is to assign two num a time
                nums[i] = 0; // indicate visted
                auto res = dfs(nums, arr, p+1);
                if(!res.empty())
                    return res;
                // backtracking
                nums[i] = 1;
                arr[p] = arr[p+dist] = 0;
            }
        }
        return {};
    }
};