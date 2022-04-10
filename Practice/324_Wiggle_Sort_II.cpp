// Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
            nums[i] = sorted[i&1 ? k++ : j++];
    }
    // wiggleSort with equal, e.g. nums[0] <= nums[1] >= nums[2] ...
    void wiggleSort(vector<int>& nums){
        sort(nums.begin(), nums.end());
        for(int i = 2; i < nums.size(); i += 2){
            swap(nums[i], nums[i-1]);
        }
    }
};