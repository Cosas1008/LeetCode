class Solution {
public:
    vector<int> _nums;
    Solution(vector<int>& nums) {
        this->_nums = nums;
    }
    
    int pick(int target) {
        int n = 0, sz = _nums.size(), ret = 0;
        for(int i = 0; i < sz; i++){
            if(_nums[i] != target) continue;
            if(n == 0){ret = i; n++;}
            else{
                n++;
                if(rand() % n == 0){ret = i;}// with prob 1/(n+1) to replace the previous index
            }
        }
        return ret;
    }
};