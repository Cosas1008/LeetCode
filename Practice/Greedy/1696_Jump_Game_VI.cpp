/*
Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
*/
//First Try ( TLE )
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size()+1, 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int optimize = INT_MIN;
            for(int j = 1; j <= k && i - j >= 0; j++){
                optimize = max(optimize, dp[i-j] + nums[i]);
            }
            dp[i] = optimize;
            // printdp(dp);
        }
        return dp[nums.size()-1];
    }
// private:
//     void printdp(vector<int>& dp){
//         for(auto d : dp){
//             cout << d << " ";
//         }cout << endl;
//     }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> d{0};
        for(int i = 1; i < nums.size(); i++){
            if(d.front() + k < i)
                d.pop_front();
            nums[i] += nums[d.front()];
            while(!d.empty() && nums[d.back()] <= nums[i]) d.pop_back();
            d.push_back(i);
        }
        return nums.back();
    }
};