class Solution {
public:
// Time Complexity : O(N^2)
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz  = nums.size();
        int ans;
        for(int i = 0; i < sz; i++){
            int cur = nums[i]; // remove 1 first
            int front = i + 1;
            int back = sz - 1;
            while(front < back){
                int p1  = nums[front];
                int p2  = nums[back];
                int tmp = cur + p1 + p2;
                if(tmp < target) front++;
                else if(tmp > target) back--;
                else return target;
            }
            
            while(i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};