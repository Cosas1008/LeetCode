/*
You are given an integer array nums and an integer x.
In one operation, you can either remove the leftmost or the rightmost element
from the array nums and subtract its value from x. 

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
*/

// Key here is traverse the array to sum up the result from left to right
// map to store stepped sum
// lookup remains from right to left
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = INT_MAX, n = nums.size(), sum = 0;
        unordered_map<int,int> hash;
        hash.emplace(0,-1); // important
        for(int i = 0; i < n && sum <= x ; i++){
            sum += nums[i];
            hash[sum] = i;
        }
        if(sum < x) return -1;
        if(sum == x) return n;
        // cout << "hash size : " << hash.size() << endl;
        
        for(int r = n-1, sum = 0; r >= 0 && sum <= x; r--){
            auto it = hash.find(x - sum);
            if(it != hash.end() && r > it->second){
                res = min(res, n - r + it->second);
            }
            sum += nums[r];
        }
        return (res == INT_MAX)? -1 : res;
    }
};
// Optimize II
int minOperations(vector<int>& nums, int x) {
    int sum = accumulate(begin(nums), end(nums), 0); // get sum first
    int l = 0, r = 0, res = INT_MAX, sz = nums.size();
    while (l <= r)
        if (sum >= x) {
            if (sum == x)
                res = min(res, l + sz - r);
            if (r < sz)
                sum -= nums[r++];
            else
                break;
        }
        else
            sum += nums[l++];
    return res == INT_MAX ? -1 : res;
}