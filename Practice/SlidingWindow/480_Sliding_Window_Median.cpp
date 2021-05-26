class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);

        vector<double> medians;

        for(int i = k; ; i++){
            medians.push_back((double(*mid) + *prev(mid, 1 - k %2)) / 2.0);

            // if all done, return
            if(i == nums.size())
                return medians;

            // insert nums[i]
            window.insert(nums[i]);
            if(nums[i] < *mid){
                mid--;
            }

            // Erase nums[i-k]
            if(nums[i - k] <= *mid){
                mid++;
            }

            window.erase(window.lower_bound(nums[i - k]));
        }
        return medians;
    }
}