class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // it is important here
        vector<vector<int>> ans;
        vector<int> vec;
        helper(vec, nums, 0, ans);
        return ans;
    }
    void helper(vector<int>& vec, vector<int> nums, int begin, vector<vector<int>>& ret)
    {
        ret.push_back(vec);
        for(int i = begin ; i < nums.size(); i++){
            if(i == begin || nums[i] != nums[i-1]){
                vec.push_back(nums[i]);
                helper(vec, nums, i+1, ret);
                vec.pop_back();
            }
        }
    }

    // If there is no duplicate element, the answer is simply 2^n, where n is the number of elements.
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        ans.push_back({});
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = ans.size(); // current answer len
            for(int k = 0; k < previousN; k++){
                vector<int> instance = ans[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    ans.push_back(instance);
                }
            }
            i += count;
        }
        return ans;
    }
};