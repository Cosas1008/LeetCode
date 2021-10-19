/*
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1
The path sum is (3 + 5) + (3 + 1) = 12.
*/
class Solution {
public:
    int res = 0;
    int pathSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> mp;
        for(int& num : nums){
            m[num / 10] = m % 10;
        }
        dfs(nums[0] / 10, m, 0);
        return res;
    }
    void dfs(int num, unordered_map<int,int>& mp, int cur){
        int level = num / 10; // hundred
        int pos  = num % 10; // tens
        int left = (level + 1) * 10 + 2 * pos - 1, right = left + 1; // key here is sorted
        cur += mp[num];
        if(!mp.count(left) && mp.count(right)){
            res += cur;
            return;
        }
        if(m.count(left)) dfs(left, mp, cur);
        if(m.count(right)) dfs(right, mp, cur);
    }
};