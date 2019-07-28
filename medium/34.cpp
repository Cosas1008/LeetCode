class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator it, init;
        vector<int> vec_return; // I might just return {-1,-1} and all set! XD
        int start = -1, end = -1;
        init = nums.begin();
        it = nums.begin();
        vec_return.push_back(start);
        vec_return.push_back(end);
        if(nums.empty()){
            return vec_return;
        }
        while(it!= nums.end()){
            if(*it == target){
                vec_return.clear();
                start = distance(init, it);
                vec_return.push_back(start);
                end = start;
                it++;
                while(it != nums.end() && *it == target){
                    end++;
                    it++;
                }
                vec_return.push_back(end);
                return vec_return;
            }
            it++;
        }
        return vec_return;
    }
};

// God-like std library part 1

// equal_range will return pair<ForwardIt,ForwardIt>
// note: ForwardIt is the iterator of any type
vector<int> searchRange(vector<int>& nums, int target) {
    auto bounds = equal_range(nums.begin(), nums.end(), target);
    if (bounds.first == bounds.second)
        return {-1, -1};
    return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
}


// God-like std library part 2
vector<int> searchRange(vector<int>& nums, int target) {
    int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lo == nums.size() || nums[lo] != target)
        return {-1, -1};
    int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {lo, hi};
}

