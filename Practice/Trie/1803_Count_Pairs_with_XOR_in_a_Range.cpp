/*
Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.
A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.

Example 1:

Input: nums = [1,4,2,7], low = 2, high = 6
Output: 6
Explanation: All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
*/
class Solution {
public:
    struct Trie{
        Trie* t[2] = {};
        int cnt = 0;
        void insert(int n, int i = 14){
            if(i >= 0){
                auto b = (n >> i) & 1;
                t[b] = t[b] == nullptr? new Trie() : t[b];
                ++t[b]->cnt;
                t[b]->insert(n, i-1);
            }
        }
        int countLess(int n, int lim, int i = 14){
            auto b = (n >> abs(i)) & 1, lim_b = (lim >> abs(i)) & 1, x = b ^ lim_b;
            return lim_b * (t[b] ? t[b]->cnt : 0) + 
                (t[x] ? t[x]->countLess(n, lim, i - 1) : 0);
        }
    };
    int countPairs(vector<int>& nums, int low, int high) {
        Trie root;
        int res = 0;
        for(int& n : nums){
            res += root.countLess(n, high+1) - root.countLess(n, low);
            root.insert(n);
        }
        return res;
    }
};
// Explain
/*
Bit     Limit_bit  |  Action
0          0       |  Cannot go to 1 subtree because 0^1=1 (bit ^ 1 subtree ) w/c is > limit_bit.  So we move to 0 subtree to find possible pairs with n.
0          1       |  Count all in 0 subtree because 0^0=0 is strictly less than limit_bit (So all numbers in 0 subtree will be in limit). 
                      Also, move to 1 subtree (0^1=1 <=limit_bit) to find possible pairs in that subtree.
1          0       |  Cannot go to 0 subtree (1^0=1 >limit_bit). Move to 1 subtree (1^1=0 <=limit_bit) to find possible pairs.
1          1       |  Count all in 1 subtree (1^1=0 is strictly less than limit_bit). Move to 0 subtree to find possible pairs.
*/